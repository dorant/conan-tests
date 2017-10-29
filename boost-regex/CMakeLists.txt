project(example)
cmake_minimum_required(VERSION 2.8)
add_definitions("-std=c++11")

#set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})
#include(conanbuildinfo)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(example main.cpp)
target_link_libraries(example ${CONAN_LIBS})
