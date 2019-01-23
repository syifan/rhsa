cmake_minimum_required(VERSION 3.4)

find_package(Protobuf REQUIRED)

PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS msg.proto)

message ("PROTO_SRCS = ${PROTO_SRCS}")
message ("PROTO_HDRS = ${PROTO_HDRS}")

add_library(proto
  ${PROTO_SRCS}
  ${PROTO_HDRS}
  encoder.cc
  encoder.h
)
set_property(TARGET proto PROPERTY POSITION_INDEPENDENT_CODE ON)
