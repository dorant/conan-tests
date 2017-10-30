# conan-tests

## Setting Clang 5.0 as default

    sudo update-alternatives --install /usr/bin/clang cc /usr/bin/clang-5.0 100
    sudo update-alternatives --install /usr/bin/clang++ c++ /usr/bin/clang++-5.0 100


## Setup ~/.conan/profiles/default

    compiler=clang
    compiler.version=5.0
    compiler.libcxx=libstdc++11
