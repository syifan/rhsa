#include <cstdint>
#include <memory>

#include "src/proto/request.pb.h"

namespace rhsa {

/**
 * Request is the unit that comminicate between the client and the server.
 * It is a wrapper of the protobuf request.
 */
class Request {
 protected:
  RequestMessage *req_;

 public:
  Request();
  Request(const std::string &req);
  virtual ~Request();

  /**
   * ByteSize returns the serialized request size in bytes.
   *
   * This size include the 64-bit unsigned integer that represent the size
   * of the payload.
   */
  int ByteSize() { return req_->ByteSize() + 8; }

  std::unique_ptr<uint8_t[]> Encode();
};

class InitRequest : public Request {
 public:
  InitRequest() : Request() {
    InitMessage *init_msg = new InitMessage();
    req_->set_allocated_init(init_msg);
  }
};
}
