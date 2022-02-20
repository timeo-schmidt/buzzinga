## Deployment steps

```bash
$ git clone https://github.com/edgeimpulse/example-standalone-inferencing-linux
$ cd example-standalone-inferencing-linux && git submodule update --init --recursive
$ sudo apt install libasound2

# Copy the folders of the exported C++ library into the root folder of the repo

# Build a model file:
$ APP_EIM=1 make -j
```
