#include "src/request/request.h"

#include <google/protobuf/message.h>

namespace rhsa {

Request::Request(const std::string &req) {
  req_ = new RequestMessage();
  req_->ParseFromString(req);
}

Request::~Request() {
  delete req_;
}

void Request::Encode(std::string *req) {
  req_->SerializeToString(req);
}

}
