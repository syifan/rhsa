cmake_minimum_required(VERSION 3.4)

add_executable(server
  server.cc
)
target_link_libraries(server conn request proto -lstdc++ 
  ${PROTOBUF} ${HSA_RUNTIME})
