project(example)
cmake_minimum_required(VERSION 2.8)
add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


# Protobuf
set(protobuf_MODULE_COMPATIBLE TRUE)
find_package(protobuf CONFIG REQUIRED)
message(STATUS "Using protobuf ${protobuf_VERSION}")

# gRPC
find_package(gRPC CONFIG REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")

# gRPC C++ plugin
get_target_property(gRPC_CPP_PLUGIN_EXECUTABLE gRPC::grpc_cpp_plugin
  IMPORTED_LOCATION_RELEASE)

# Proto file
get_filename_component(hw_proto "helloworld.proto" ABSOLUTE)
get_filename_component(hw_proto_path "${hw_proto}" PATH)

# Generated sources
protobuf_generate_cpp(hw_proto_srcs hw_proto_hdrs "${hw_proto}")
set(hw_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/helloworld.grpc.pb.cc")
set(hw_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/helloworld.grpc.pb.h")
add_custom_command(
      OUTPUT "${hw_grpc_srcs}" "${hw_grpc_hdrs}"
      COMMAND protobuf::protoc
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}" -I "${hw_proto_path}"
        --plugin=protoc-gen-grpc="${gRPC_CPP_PLUGIN_EXECUTABLE}"
        "${hw_proto}"
      DEPENDS "${hw_proto}")

# Generated include directory
include_directories("${CMAKE_CURRENT_BINARY_DIR}")


add_executable(example main.cpp
      ${hw_proto_srcs}
      ${hw_grpc_srcs})

target_link_libraries(example ${CONAN_LIBS} pthread)
