#include <cstdint>
#include <memory>

#include "src/proto/request.pb.h"
#include "src/common/agent.h"

namespace rhsa {

/**
 * Request is the unit that comminicate between the client and the server.
 * It is a wrapper of the protobuf request.
 */
class Request {
 protected:
   std::unique_ptr<RequestMessage> req_;

 public:
  Request();
  Request(const std::string &req);
  virtual ~Request() {};

  /**
   * ByteSize returns the serialized request size in bytes.
   *
   * This size include the 64-bit unsigned integer that represent the size
   * of the payload.
   */
  int ByteSize() { return req_->ByteSize() + 8; }

  /**
   * Return the payload case to tell what type of the request it is.
   */
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
 private:
  QueryAgent *msg_;

 public:

  /**
   * Constructor. 
   *
   * This constructor is used to convert a general request to a 
   * QueryAgentRequest. After calling this constructor, the general
   * request is invalidated.
   */
  QueryAgentRequest(Request *request) {
    req_ = std::move(request->req_);
    msg_ = req_->mutable_queryagent();
  }

  QueryAgentRequest() : Request() {
    msg_ = new QueryAgent();
    req_->set_allocated_queryagent(msg_); 
  }

  void AddAgent(Agent *agent) {
    *msg_->add_agents() = *agent->GetAgentMesg();
  }
};

}
