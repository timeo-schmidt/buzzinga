#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <chrono>
#include <sys/time.h>
#include <ctime>
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <alsa/asoundlib.h>


#include "edge-impulse-sdk/classifier/ei_run_classifier.h"

// Callback function declaration
int get_microphone_data(size_t offset, size_t length, float *out_ptr);

#define SLICE_LENGTH_MS      250        // 4 inferences per second
#define SLICE_LENGTH_VALUES  (EI_CLASSIFIER_RAW_SAMPLE_COUNT / (1000 / SLICE_LENGTH_MS))

static bool use_debug = false; // Set this to true to see features generated from the raw signal
bool sentMessage = false;
time_t lastDetection = 0;

static int16_t classifier_buffer[EI_CLASSIFIER_RAW_SAMPLE_COUNT * sizeof(int16_t)]; // full classifier buffer

// libalsa state
static snd_pcm_t *capture_handle;
static int channels = 1;
static unsigned int rate = EI_CLASSIFIER_FREQUENCY;
static snd_pcm_format_t format = SND_PCM_FORMAT_S16_LE;
static char *card;

// Initialize the alsa library
int init_alsa(bool debug = false) {
    int err;

    snd_pcm_hw_params_t *hw_params;

    if ((err = snd_pcm_open(&capture_handle, card, SND_PCM_STREAM_CAPTURE, 0)) < 0) {
        fprintf(stderr, "cannot open audio device %s (%s)\n",
                card,
                snd_strerror(err));
        return 1;
    }

    if (debug) {
        fprintf(stdout, "audio interface opened\n");
    }

    if ((err = snd_pcm_hw_params_malloc(&hw_params)) < 0) {
        fprintf(stderr, "cannot allocate hardware parameter structure (%s)\n",
                snd_strerror(err));
        return 1;
    }

    if (debug) {
        fprintf(stdout, "hw_params allocated\n");
    }

    if ((err = snd_pcm_hw_params_any(capture_handle, hw_params)) < 0)
    {
        fprintf(stderr, "cannot initialize hardware parameter structure (%s)\n",
                snd_strerror(err));
        return 1;
    }

    if (debug) {
        fprintf(stdout, "hw_params initialized\n");
    }

    if ((err = snd_pcm_hw_params_set_access(capture_handle, hw_params, SND_PCM_ACCESS_RW_INTERLEAVED)) < 0)
    {
        fprintf(stderr, "cannot set access type (%s)\n",
                snd_strerror(err));
        return 1;
    }

    if (debug) {
        fprintf(stdout, "hw_params access set\n");
    }

    if ((err = snd_pcm_hw_params_set_format(capture_handle, hw_params, format)) < 0)
    {
        fprintf(stderr, "cannot set format (%s)\n",
                snd_strerror(err));
        return 1;
    }

    if (debug) {
        fprintf(stdout, "hw_params format set\n");
    }

    if ((err = snd_pcm_hw_params_set_rate(capture_handle, hw_params, rate, 0)) < 0) {
        fprintf(stderr, "cannot set sample rate (%s)\n",
                snd_strerror(err));
        return 1;
    }
    else {
        unsigned int read_rate;
        int read_dir;

        snd_pcm_hw_params_get_rate(hw_params, &read_rate, &read_dir);

        if (debug) {
            fprintf(stdout, "hw_params rate set: %d\n", read_rate);
        }
    }

    if ((err = snd_pcm_hw_params_set_channels(capture_handle, hw_params, channels)) < 0) {
        fprintf(stderr, "cannot set channel count (%s)\n",
                snd_strerror(err));
        return 1;
    }

    if (debug) {
        fprintf(stdout, "hw_params channels set:%d\n", channels);
    }

    if ((err = snd_pcm_hw_params(capture_handle, hw_params)) < 0) {
        fprintf(stderr, "cannot set parameters (%s)\n",
                snd_strerror(err));
        return 1;
    }

    if (debug) {
        fprintf(stdout, "hw_params set\n");
    }

    snd_pcm_hw_params_free(hw_params);

    if (debug) {
        fprintf(stdout, "hw_params freed\n");
    }

    if ((err = snd_pcm_prepare(capture_handle)) < 0)
    {
        fprintf(stderr, "cannot prepare audio interface for use (%s)\n",
                snd_strerror(err));
        return 1;
    }

    if (debug) {
        fprintf(stdout, "audio interface prepared\n");
    }

    return 0;
}

void close_alsa(int signum) {
    snd_pcm_drop(capture_handle);
    snd_pcm_close(capture_handle);
    exit(0);
}


void classify_buffer(){
    signal_t signal;
    ei_impulse_result_t result = { 0 };  // Used to store inference output
    EI_IMPULSE_ERROR res;                // Return code from inference

    // Assign callback function to fill buffer used for preprocessing/inference
    signal.total_length = EI_CLASSIFIER_RAW_SAMPLE_COUNT;
    signal.get_data = &get_microphone_data;

    // Perform DSP pre-processing and inference
    res = run_classifier(&signal, &result, false);

    // Print the prediction results (classification)
    printf("%d ms. ", result.timing.dsp + result.timing.classification);
    for (size_t i = 0; i < EI_CLASSIFIER_LABEL_COUNT; i++) {
        printf("%s: %.05f", result.classification[i].label, result.classification[i].value);
        if (i != EI_CLASSIFIER_LABEL_COUNT - 1) {
            printf(", ");
        }

        if (result.classification[i].value >= 0.9 && ei_classifier_inferencing_categories[i] == "dong"){
            time_t currentTime = time(nullptr);

            if((currentTime - lastDetection) >= 30){
                sentMessage = false;
                printf("Sent message: %d \n", (currentTime - lastDetection));
            }

            if(!sentMessage){
            printf("\n");
            printf("Begin sending \n");
            Py_Initialize();
            char filename[] = "FCM_dong.py";
            FILE* fp;
            // Open the file, and run it
            fp = _Py_fopen(filename, "r");
            PyRun_SimpleFile(fp, filename);
            printf("Notification sent \n");
            //Close the python instance
            Py_Finalize();

            sentMessage = true;
            }

            lastDetection = currentTime;

        }
        else if(result.classification[i].value >= 0.9 && ei_classifier_inferencing_categories[i] == "firealarm"){
            time_t currentTime = time(nullptr);

            if((currentTime - lastDetection) >= 30){
                sentMessage = false;
                printf("Sent message: %d \n", (currentTime - lastDetection));
            }

            if(!sentMessage){
                printf("\n");
                printf("Begin sending \n");
                Py_Initialize();
                char filename[] = "FCM_firealarm.py";
                FILE* fp;
                // Open the file, and run it
                fp = _Py_fopen(filename, "r");
                PyRun_SimpleFile(fp, filename);
                printf("Notification Sent \n");
                //Close the python instance
                Py_Finalize();

                sentMessage = true;
            }

            lastDetection = currentTime;

        }
    }

    // Print anomaly result (if it exists)
    #if EI_CLASSIFIER_HAS_ANOMALY == 1
        printf("Anomaly prediction: %.3f\r\n", result.anomaly);
        printf("Anomaly timing:  %d ms\r\n", result.timing.anomaly); 
    #endif

    printf("\n");
}

int main(int argc, char **argv) {

    card = "plughw:1,0";

    if (init_alsa(use_debug) != 0) {
        exit(1);
    }

    signal(SIGINT, close_alsa);

    // allocate buffers for the slice
    int16_t slice_buffer[SLICE_LENGTH_VALUES * sizeof(int16_t)];
    uint32_t classify_count = 0;

    while (1) {
        int x = snd_pcm_readi(capture_handle, slice_buffer, SLICE_LENGTH_VALUES);
		if (x ==-EPIPE){
			snd_pcm_prepare(capture_handle);
			x=snd_pcm_readi(capture_handle,slice_buffer, SLICE_LENGTH_VALUES);
			if (x<0) printf("Failed to read audio data (%d)\n", x);
		}
        /*
        if (x != SLICE_LENGTH_VALUES) {
            printf("Failed to read audio data (%d)\n", x);
            return 1;
        }*/

        // 1. roll -SLICE_LENGTH_VALUES here
        numpy::roll(classifier_buffer, EI_CLASSIFIER_RAW_SAMPLE_COUNT, -SLICE_LENGTH_VALUES);

        // 2. copy slice buffer to the end
        const size_t classifier_buffer_offset = EI_CLASSIFIER_RAW_SAMPLE_COUNT - SLICE_LENGTH_VALUES;
        memcpy(classifier_buffer + classifier_buffer_offset, slice_buffer, SLICE_LENGTH_VALUES * sizeof(int16_t));

        // ignore the first N slices we classify, we don't have a complete frame yet
        if (++classify_count < EI_CLASSIFIER_RAW_SAMPLE_COUNT / SLICE_LENGTH_VALUES) {
            continue;
        }

        // 3. Classify
        classify_buffer ();
    }

    close_alsa(0);
}


// Callback: fill a section of the out_ptr buffer when requested
int get_microphone_data(size_t offset, size_t length, float *out_ptr) {
    for (size_t i = 0; i < length; i++) {
        out_ptr[i] = (classifier_buffer + offset)[i];
    }
    return EIDSP_OK;
}
