# Record a single audio sample
import sounddevice as sd
import soundfile as sf
import numpy as np

recording_duration = 2         # The amount of time for wich data is recorded
recording_channels = 1          # The number of audio channels that are recorded
recording_fs = 44100            # The sample rate / frequency of the recording
recording_base_file = "base.wav"

print("Listening ...")
# Record the audio from the system microphone
recording_raw = sd.rec(recording_duration * recording_fs,
                       samplerate=recording_fs,
                       channels=recording_channels)

sd.wait()  # Wait for recording to finish
print("Recording finished.")

sf.write(recording_base_file, recording_raw, recording_fs)
