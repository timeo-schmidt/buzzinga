import os

API_KEY = "ei_b25f62c7d6f4de0d632c648eec250ff37584f86e59ea2bba5d123393ef7f9ec4"
DATA_DIR = "./local_data/"

for (dir_path, dir_names, file_names) in os.walk(DATA_DIR):
    for file_name in file_names:
        if(".wav" in file_name):
            print("Trying to upload: " + file_name)
            os.system(
                "edge-impulse-uploader --label unclassified --api-key " + API_KEY + " " + os.path.join(DATA_DIR, file_name))
