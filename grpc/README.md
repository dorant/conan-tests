# Test of building Boost::Regex

## Add new remote to conan:

    conan remote add inexor https://api.bintray.com/conan/inexorgame/inexor-conan

## Build:

    mkdir build
    cd build
    conan install --build=missing ..


    export CC=/usr/bin/clang
    export CXX=/usr/bin/clang++
    cmake ..
    make





