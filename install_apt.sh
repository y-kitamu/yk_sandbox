#!/bin/bash

sudo apt-get install -y\
     binutils-mingw-w64-x86-64\
     mingw-w64-common\
     mingw-w64-x86-64-dev\
     mingw-w64-tools\
     gcc-mingw-w64-base\
     gcc-mingw-w64-x86-64\
     g++-mingw-w64-x86-64

sudo update-alternatives --set x86_64-w64-mingw32-g++ /usr/bin/x86_64-w64-mingw32-g++-posix
sudo update-alternatives --set x86_64-w64-mingw32-gcc /usr/bin/x86_64-w64-mingw32-gcc-posix
