cmake_minimum_required(VERSION 3.4)

project(rhsa)

set(CMAKE_CXX_STANDARD 14)

set(HSA_RUNTIME_NAME "hsa-runtime64")

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}")

set(VERSION_MAJOR "1")
set(VERSION_MINOR "1")
set(VERSION_PATCH "6")
set(LIB_VERSION_STRING "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

set(DRVDEF "${CMAKE_CURRENT_SOURCE_DIR}/hsacore.so.def")

set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--version-script=${DRVDEF}")

find_library(PROTOBUF protobuf)

add_library(${HSA_RUNTIME_NAME} SHARED 
  src/init.cc
  src/conn/conn.cc
  src/conn/connector.cc
)
set_property(TARGET ${HSA_RUNTIME_NAME} PROPERTY VERSION ${LIB_VERSION_STRING})
set_property(TARGET ${HSA_RUNTIME_NAME} PROPERTY SOVERSION "${VERSION_MAJOR}")
target_link_libraries(${HSA_RUNTIME_NAME} ${PROTOBUF})

message(${PROTOBUF})
add_executable(server
  src/request.pb.cc src/init.pb.cc src/server.cc)
target_link_libraries(server ${PROTOBUF})
