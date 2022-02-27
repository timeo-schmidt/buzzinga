## Deployment steps

```bash
# There is no out-of-the-box support for the Raspberry Pi Zero (Arm6)
# You have to export the trained model from the web interface
# Go to the Edge Impulse Web interface > Deployment > Export C++ Library
# Unzip and move the folder to your target

# ...
# Write the code that is running together with the model library
# Adjust the Makefile if necessary
# ...

# Make sure to have libasoud2-dev and libasound2-dev installed,
# otherwise:
$ sudo apt-get update
$ sudo apt-get install libasound2-dev
$ sudo apt-get install libasound2

# Add the Makefile and main.c to the project
$ cp -R ./deployment_pieces/* ./buzzinga-project-1-v5/

# Add the python scripts for Firebase Cloud Messaging to the project
$ cp -R ./FCM_notifications/* ./buzzinga-project-1-v5/

# Make sure to install the requests library in order to execute HTTP requests
# by running:       
$ sudo pip3 install requests

# Go to the project directory 
$ cd ./buzzinga-project-1-v5

# Compile the library together with your custom source
$ make -j 2 # Do not use more cores, this will cause errors

# Execute and test your compilation
$ ./build/app
```
