cmake_minimum_required(VERSION 3.4)

project(rhsa)

list(APPEND CMAKE_MODULE_PATH
    "${PROJECT_SOURCE_DIR}/cmake")
include(gtest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_DEBUG_POSTFIX "")
set(CMAKE_CXX_STANDARD 14)
set(GTEST_ROOT ${PROJECT_SOURCE_DIR}/gtest/googletest)
set(GMOCK_ROOT ${PROJECT_SOURCE_DIR}/gtest/googlemock)

find_package(Boost 1.65 COMPONENTS fiber REQUIRED)

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_BINARY_DIR}")
include_directories("/opt/rocm/include")
include_directories("${GTEST_ROOT}/include")
include_directories("${GMOCK_ROOT}/include")
include_directories(${Boost_INCLUDE_DIR})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -pthread")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

find_library(PROTOBUF protobuf)
find_library(HSA_RUNTIME hsa-runtime64
  HINTS /opt/rocm/lib/
)
message(${HSA_RUNTIME})

add_subdirectory(src)
