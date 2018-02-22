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

  int GetPayloadCase() { return (int)req_->Payload_case(); } 

  std::unique_ptr<uint8_t[]> Encode();
};

class InitRequest : public Request {
 public:
  InitRequest() : Request() {
    InitMessage *init_msg = new InitMessage();
	  init_msg->set_type(1);
    req_->set_allocated_init(init_msg);
  }
};

class QueryAgentRequest : public Request {
 public:
  QueryAgentRequest() : Request() {
    QueryAgent *msg = new QueryAgent();
    req_->set_allocated_queryagent(msg); 
  }
};

}
