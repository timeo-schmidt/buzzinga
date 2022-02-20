import numpy as np
import sounddevice as sd
import wave
from datetime import datetime

DATA_DIR = './local_data/'  # File name to save
API_KEY = ""
MAX_COLLECTIONS = 100
wave_length = 1  # Recording length (seconds)
sample_rate = 16_000  # Sampling frequency

# This will continuously record data until key s is pressed
while True:

    dateTimeObj = datetime.now()
    file_name = DATA_DIR + \
        dateTimeObj.strftime("%d-%b-%Y-%H-%M-%S-%f") + ".wav"

    print("Listening ...")
    # Start recording (wave_length Record for seconds. Wait until the recording is finished with wait)
    data = sd.rec(int(wave_length * sample_rate), sample_rate, channels=1)
    sd.wait()

    # Normalize. Since it is recorded with 16 bits of quantization bit, it is maximized in the range of int16.
    data = data / data.max() * np.iinfo(np.int16).max

    # float -> int
    data = data.astype(np.int16)

    print("Saving as " + file_name + "\n\n")
    with wave.open(file_name, mode='wb') as wb:
        wb.setnchannels(1)  # monaural
        wb.setsampwidth(2)  # 16bit=2byte
        wb.setframerate(sample_rate)
        wb.writeframes(data.tobytes())  # Convert to byte string
