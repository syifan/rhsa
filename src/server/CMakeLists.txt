cmake_minimum_required(VERSION 3.4)

add_executable(server
  server.cc
  server_main.cc
)
target_link_libraries(server conn -lstdc++ ${HSA_RUNTIME})
