## Deployment steps

```bash
$ git clone https://github.com/edgeimpulse/example-standalone-inferencing-linux
$ cd example-standalone-inferencing-linux && git submodule update --init --recursive
$ sudo apt install libasound2

# Copy the folders of the exported C++ library into the root folder of this new repo
$ cp -r  ../buzzinga-project-1-v5/* ./

# Build a model file by running this command in the example-standalone-inferencing-linux/ folder
$ APP_EIM=1 make -j
```
