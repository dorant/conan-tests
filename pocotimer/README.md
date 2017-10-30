# Test of building Poco::Timer

## Build:

    mkdir build
    cd build
    conan install --build=missing ..


    export CC=/usr/bin/clang
    export CXX=/usr/bin/clang++
    cmake ..
    make

## Run:

    bin/timer
