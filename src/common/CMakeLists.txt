cmake_minimum_required(VERSION 3.4)

add_library(common
)

target_link_libraries(common proto)
set_property(TARGET common PROPERTY POSITION_INDEPENDENT_CODE ON)
