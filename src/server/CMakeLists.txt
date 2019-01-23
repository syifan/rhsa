cmake_minimum_required(VERSION 3.4)

add_executable(server
  server.cc
  server_main.cc
)
target_link_libraries(server conn proto -lstdc++ 
  ${PROTOBUF} ${HSA_RUNTIME})
