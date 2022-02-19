import json
import time
import hmac
import hashlib
import requests
import re
import uuid
import math
import numpy as np
import pandas as pd


import sounddevice as sd

# Your API & HMAC keys can be found here (go to your project > Dashboard > Keys to find this)
HMAC_KEY = "474583b7218e9637590c70dcd991a4b4"
API_KEY = "ei_b25f62c7d6f4de0d632c648eec250ff37584f86e59ea2bba5d123393ef7f9ec4"

recording_duration = 2         # The amount of time for wich data is recorded
recording_channels = 1          # The number of audio channels that are recorded
recording_fs = 44100            # The sample rate / frequency of the recording


# empty signature (all zeros). HS256 gives 32 byte signature, and we encode in hex, so we need 64 characters here
emptySignature = ''.join(['0'] * 64)

# use MAC address of network interface as deviceId
device_name = ":".join(re.findall('..', '%012x' % uuid.getnode()))

print("Listening ...")
# Record the audio from the system microphone
recording_raw = sd.rec(recording_duration * recording_fs,
                       samplerate=recording_fs,
                       channels=recording_channels)

sd.wait()  # Wait for recording to finish
print("Recording finished.")

recording_flattened = np.reshape(recording_raw, recording_raw.shape[0])
recording_as_list = recording_flattened.tolist()

print("Sending data to Edge Impulse")
data = {
    "protected": {
        "ver": "v1",
        "alg": "HS256",
        "iat": time.time()  # epoch time, seconds since 1970
    },
    "signature": emptySignature,
    "payload": {
        "device_name":  device_name,
        "device_type": "Raspberry Pi Zero",
        "interval_ms": 1000/44100,
        "sensors": [
            {"name": "USB Microphone", "units": "mV"},
        ],
        "values": recording_as_list
    }
}


# encode in JSON
encoded = json.dumps(data)

# sign message
signature = hmac.new(bytes(HMAC_KEY, 'utf-8'),
                     msg=encoded.encode('utf-8'), digestmod=hashlib.sha256).hexdigest()

# set the signature again in the message, and encode again
data['signature'] = signature
encoded = json.dumps(data)

# and upload the file
res = requests.post(url='https://ingestion.edgeimpulse.com/api/training/data',
                    data=encoded,
                    headers={
                        'Content-Type': 'application/json',
                        'x-file-name': 'idle01',
                        'x-api-key': API_KEY
                    })
if (res.status_code == 200):
    print('Uploaded file to Edge Impulse', res.status_code, res.content)
else:
    print('Failed to upload file to Edge Impulse', res.status_code, res.content)