namespace rhsa {

#include "src/proto/request.pb.h"

/**
 * Message is the unit that comminicate between the client and the server.
 * It is a wrapper of the protobuf request.
 */
class Message {
  Request *req_;
 public:
  Message(const std::string &req);
  std::string Encode();
}

}
