namespace rhsa {

#include "src/proto/request.pb.h"

/**
 * Message is the unit that comminicate between the client and the server.
 * It is a wrapper of the protobuf request.
 */
class Message {
  Request *req_;
 public:
  Message() = default;
  Message(const std::string &req);
  virtual ~Message();
  void Encode(std::string *req);
}

}
