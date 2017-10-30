# Test of building Boost::Regex

## Add new remote to conan:

    conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan

## Build:

    mkdir build
    cd build
    conan install --build=missing ..


    export CC=/usr/bin/clang
    export CXX=/usr/bin/clang++
    cmake ..
    make

## Run:

    bin/example

Stdin:

    Subject: Hello

Gives:

    Hello


## More info:

    https://bincrafters.github.io/2017/09/22/boost-modular-packages-conan/
