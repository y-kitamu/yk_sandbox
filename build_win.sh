#!/bin/bash

BASEDIR=$(dirname "$0")

# build libtiff
# mkdir -p ${BASEDIR}/ext/build_win/libtiff
# cd ${BASEDIR}/ext/build_win/libtiff
# rm -rf CMake*
# cmake -GNinja\
#       -DCMAKE_TOOLCHAIN_FILE=../../../cmake/mingw.cmake\
#       -DBUILD_SHARED_LIBS=OFF\
#       -Dzlib=OFF\
#       -Djbig=OFF\
#       ../../libtiff/
# ninja

# build opencv
OPENCV_BUILD_DIR=${BASEDIR}/ext/build_win/opencv
if [ ! -e ${OPENCV_BUILD_DIR} ]; then
    mkdir -p ${OPENCV_BUILD_DIR}
fi
cd ${OPENCV_BUILD_DIR}
# rm -rf CMake*
cmake -GNinja\
      -DCMAKE_TOOLCHAIN_FILE=../../../cmake/mingw.cmake\
      -DBUILD_SHARED_LIBS=OFF\
      -DWITH_GTK=OFF\
      -DWITH_V4L=OFF\
      -DWITH_FFMPEG=OFF\
      -DWITH_IPP=OFF\
      -DWITH_ITT=OFF\
      -DWITH_WEBP=OFF\
      -DWITH_OPENXR=OFF\
      -DWITH_OPENJPEG=OFF\
      -DWITH_JASPER=OFF\
      -DBUILD_opencv_highgui=OFF\
      -DBUILD_LIST=core,imgcodecs,imgproc\
      -DBUILD_opencv_world=ON\
      ../../opencv/
ninja
