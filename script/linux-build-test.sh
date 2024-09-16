#!/bin/sh

echo "------------------------------ Building ------------------------------"

if [ "$1" = "debug" ]
then
    echo "------------------------------ Debug ------------------------------"
    mkdir -p build/debug
    cd build/debug
    cmake ../../. -DCMAKE_BUILD_TYPE="Debug" -DBUILD_SHARED_LIBS=ON -DBUILD_STATIC_LIBS=OFF
elif [ "$1" = "release" ]
then
    echo "------------------------------ Release ------------------------------"
    mkdir -p build/release
    cd build/release
    cmake ../../. -DCMAKE_BUILD_TYPE="Release" -DBUILD_SHARED_LIBS=ON -DBUILD_STATIC_LIBS=OFF
else
    echo "Build type is not valid. Only debug or release."
    exit 1
fi

make -j6

echo "------------------------------ Running ------------------------------"

./test
