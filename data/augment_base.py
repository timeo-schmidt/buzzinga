import nlpaug.augmenter.audio as naa
import librosa
import nlpaug.flow as naf

from nlpaug.util import Action

file_path = './base.wav'
recording_fs = 44100

data, sr = librosa.load(file_path)


aug = naf.Sometimes([
    naa.LoudnessAug(),
    naa.MaskAug(sampling_rate=recording_fs, mask_with_noise=True),
    naa.NoiseAug(),
    naa.PitchAug(sampling_rate=sr, factor=(0.9, 1.1)),
    naa.ShiftAug(sampling_rate=recording_fs),
])

augmented_data = aug.augment(data, n=3)

print(len(augmented_data))
