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

# Add the Makefile and main.c to the project
$ cp -R ./deployment_pieces/* ./buzzinga-project-1-v5/
$ cd ./buzzinga-project-1-v5

# Compile the library together with your custom source
$ make -j 2 # Do not use more cores, this will cause errors

# Execute and test your compilation
$ ./build/app
```
