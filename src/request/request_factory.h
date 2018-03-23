#ifndef SRC_REQUEST_REQUEST_FACTORY_H_
#define SRC_REQUEST_REQUEST_FACTORY_H_

#include <memory>

#include "src/request/request.h"

namespace rhsa{

class RequestFactory {
 public:

  auto BuildInitRequest() {
    auto req = std::make_unique<Request>();
    auto msg = new InitMessage();
    req->req_->set_allocated_init(msg); 
    msg->set_type(1);
    return std::move(req);

  }

  /**
   * BuildQueryAgentRequest creates a new QueryAgent Request
   */
  auto BuildQueryAgentRequest() {
    auto req = std::make_unique<Request>();
    auto msg = new QueryAgent();
    req->req_->set_allocated_queryagent(msg); 
    return std::move(req);
  }
};

}

#endif  // SRC_REQUEST_REQUEST_FACTORY_H_
