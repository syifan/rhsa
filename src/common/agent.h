#ifndef SRC_COMMON_AGENT_H_
#define SRC_COMMON_AGENT_H_

#include <memory>

#include "src/proto/agent.pb.h"

namespace rhsa {

class Agent {
  std::unique_ptr<AgentMesg> agent_mesg_;

 public:
  Agent() { agent_mesg_ = std::make_unique<AgentMesg>(); }

  void SetName(const char *name) { agent_mesg_->set_name(name); }
  const std::string &GetName() { return agent_mesg_->name(); }

  void SetVendorName(const char *name) { agent_mesg_->set_vendor_name(name); }
  const std::string &GetVendorName() { return agent_mesg_->vendor_name(); }
};

}

#endif  // SRC_COMMON_AGENT_H_
