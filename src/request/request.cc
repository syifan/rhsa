#include "src/request/request.h"

#include <google/protobuf/message.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>

namespace rhsa {

Request::Request() {
  req_ = new RequestMessage();
}

Request::Request(const std::string &req) {
  req_ = new RequestMessage();
  req_->ParseFromString(req);
}

Request::~Request() { delete req_; }

std::unique_ptr<uint8_t []> Request::Encode() { 
  int size = req_->ByteSize() + 8;
  auto buf = std::make_unique<uint8_t []>(size);

  google::protobuf::io::ArrayOutputStream aos(buf.get(), size);
  google::protobuf::io::CodedOutputStream coded_output(&aos);
  coded_output.WriteVarint64(req_->ByteSize());
  req_->SerializeToCodedStream(&coded_output);

  return std::move(buf);
}

}