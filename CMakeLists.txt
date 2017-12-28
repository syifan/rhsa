cmake_minimum_required(VERSION 3.4)

project(rhsa)

set(CMAKE_CXX_STANDARD 14)

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}")

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -pthread")

find_library(PROTOBUF protobuf)

add_subdirectory(src)
