project(example)
cmake_minimum_required(VERSION 2.8)
#add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(hello main.cpp)
target_link_libraries(example ${CONAN_LIBS})
