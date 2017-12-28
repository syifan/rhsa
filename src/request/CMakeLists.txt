cmake_minimum_required(VERSION 3.4)

add_library(request
  request.cc
)
target_link_libraries(request proto)
set_property(TARGET request PROPERTY POSITION_INDEPENDENT_CODE ON)
