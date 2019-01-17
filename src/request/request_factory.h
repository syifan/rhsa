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
    return req;

  }

  /**
   * BuildQueryAgentRequest creates a new QueryAgent Request
   */
  auto BuildQueryAgentRequest() {
    auto req = std::make_unique<Request>();
    auto msg = new QueryAgent();
    req->req_->set_allocated_queryagent(msg); 
    return req;
  }

  enum ProgramCommand {
    executableCreateCom = 0
  };

  auto BuildProgramRequest(void* msg, ProgramCommand command) {
    auto req = std::make_unique<Request>();
    auto programMsg = new ProgramMesg();
    switch(command) {
      case executableCreateCom:
        programMsg->set_allocated_createexecutable((CreateExecutable*)msg);
        break;
    }
    req->req_->set_allocated_programmesg(programMsg);
    return req;
  }
};

}

#endif  // SRC_REQUEST_REQUEST_FACTORY_H_
