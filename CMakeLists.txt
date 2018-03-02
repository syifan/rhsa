cmake_minimum_required(VERSION 3.4)

project(rhsa)

list(APPEND CMAKE_MODULE_PATH
    "${PROJECT_SOURCE_DIR}/cmake")
include(gtest)

set(CMAKE_CXX_STANDARD 14)

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}")
include_directories("/opt/rocm/include")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -pthread")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

find_library(PROTOBUF protobuf)
find_library(HSA_RUNTIME hsa-runtime64
  HINTS /opt/rocm/lib/
)
message(${HSA_RUNTIME})

add_subdirectory(src)
