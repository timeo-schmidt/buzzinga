import sounddevice as sd
import matplotlib.pyplot as plt
from scipy.fft import fft, fftfreq
import numpy as np


# configuration
recording_duration = 1         # The amount of time for wich data is recorded
recording_channels = 1          # The number of audio channels that are recorded
recording_fs = 44100            # The sample rate / frequency of the recording

# Record the audio from the system microphone
recording_raw = sd.rec(recording_duration * recording_fs,
                       samplerate=recording_fs,
                       channels=recording_channels)

sd.wait()  # Wait for recording to finish

print(recording_raw.shape)
# As only one channel is used, flatten the data
recording_flattened = np.reshape(recording_raw, recording_raw.shape[0])


print(recording_flattened.shape)

# Play the recorded audio back
# sd.play(recording_raw, recording_fs)
# sd.wait()  # Wait for playback to finish

# Plot the raw time-domain audio data
# plt.plot(recording_raw, 'r')
# plt.xlabel("channel, sample #")
# plt.tight_layout()
# plt.show()

recording_raw_subset = recording_flattened

print(recording_raw_subset)

print("Calculating the FFT ...")
fft = fft(recording_raw_subset)
fft_abs = np.abs(fft)
freq = fftfreq(recording_raw_subset.size, d=1./recording_raw_subset)

print(fft_abs)
# fft_spectrum_abs = np.abs(fft_spectrum)


# print("Plotting...")
# plt.plot(freq, fft_abs)
# plt.xlabel("frequency, Hz")
# plt.ylabel("Amplitude, units")
# plt.show()


powerSpectrum, freqenciesFound, time, imageAxis = plt.specgram(recording_raw_subset,
                                                               Fs=recording_fs)

plt.show()
