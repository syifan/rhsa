#include "src/proto/request.pb.h"

namespace rhsa {

/**
 * Request is the unit that comminicate between the client and the server.
 * It is a wrapper of the protobuf request.
 */
class Request {
  RequestMessage *req_;
 public:
  Request() = default;
  Request(const std::string &req);
  virtual ~Request();

  void Encode(std::string *req);
};

}
