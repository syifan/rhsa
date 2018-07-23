cmake_minimum_required(VERSION 3.4)

set(HSA_RUNTIME_NAME "hsa-runtime64")
set(VERSION_MAJOR "1")
set(VERSION_MINOR "1")
set(VERSION_PATCH "6")
set(LIB_VERSION_STRING "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

set(DRVDEF "${CMAKE_CURRENT_SOURCE_DIR}/hsacore.so.def")

set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--version-script=${DRVDEF}")

add_library(${HSA_RUNTIME_NAME} SHARED
  agent.cc
  init.cc
  queue.cc
  program.cc
)
set_property(TARGET ${HSA_RUNTIME_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)
set_property(TARGET ${HSA_RUNTIME_NAME} PROPERTY VERSION ${LIB_VERSION_STRING})
set_property(TARGET ${HSA_RUNTIME_NAME} PROPERTY SOVERSION "${VERSION_MAJOR}")
target_link_libraries(${HSA_RUNTIME_NAME} conn proto ${PROTOBUF})

if (${ENABLE_TESTING})
  add_executable(client_test init_test.cc agent_test.cc)
  target_link_libraries(client_test gtest_main gmock request ${HSA_RUNTIME_NAME})
  add_test(NAME client_test COMMAND client_test)
endif ()
