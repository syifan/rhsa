#ifndef SRC_REQUEST_REQUEST_H_
#define SRC_REQUEST_REQUEST_H_
#include <cstdint>
#include <memory>

#include "src/common/agent.h"
#include "src/proto/request.pb.h"

namespace rhsa {

/**
 * Request is the unit that comminicate between the client and the server.
 * It is a wrapper of the protobuf request.
 */
class Request {
 friend class RequestFactory;

 protected:
  std::unique_ptr<RequestMessage> req_;

 public:
  Request();
  Request(const std::string &req);
  virtual ~Request(){};

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

  /**
   * Encode generate the binary representation of the request
   */
  std::unique_ptr<uint8_t[]> Encode();

  /**
   * Add an agent into the QueryAgent request
   */
  void AddAgent(Agent *agent) {
    auto query_agent = req_->mutable_queryagent();
    *query_agent->add_agents() = *agent->GetAgentMesg();
  }
};

}

#endif  // SRC_REQUEST_REQUEST_H_
