cmake_minimum_required(VERSION 3.4)

add_library(conn
  conn.cc
  connector.cc
  listener.cc
)
target_link_libraries(conn proto)
set_property(TARGET conn PROPERTY POSITION_INDEPENDENT_CODE ON)
