#include "message.h"

namespace rhsa {

Message::Message(const std::string &req) {
  req_ = new Request();
  req_->ParseFromString(req);
}

Message::~Message() {
  delete req_;
}

void Encode(std::string *req) {
  req_->SerializeToString(req)
}

}
