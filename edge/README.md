## Documentation of the Edge Firmware
**This is the code that is running on the RasPi Zero**

---
### Collecting Data

```bash
# Make sure the dependencies are installed
# This command installs all the necessary script requirements
pip install -r requirements.txt

# Install the edge impulse CLI
npm install -g edge-impulse-cli --force

# To start a new recording session, run
#
python3 record_data.py

# To synchronise your local data with Edge Impulse, run
# It will only update new data points. No need to delete local data.
python3 upload_data.py

# Important! Make sure to Label your data point straight away
# Go to Edge Impulse and change the label of the new data-point
```
