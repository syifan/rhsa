cmake_minimum_required(VERSION 3.4)

add_library(proto
  request.pb.cc
  init.pb.cc
)
set_property(TARGET proto PROPERTY POSITION_INDEPENDENT_CODE ON)
