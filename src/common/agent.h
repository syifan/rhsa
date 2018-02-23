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

		void SetFeature(AgentMesg_Feature feature) { agent_mesg_->set_feature(feature); }
		const AgentMesg_Feature GetFeature() { return agent_mesg_->feature(); } 

		void SetMachineModel(AgentMesg_Machine_model model) { agent_mesg_->set_machine_model(model); }
		const AgentMesg_Machine_model GetMachineModel() { return agent_mesg_->machine_model(); }

		void SetProfile(AgentMesg_Profile profile) { agent_mesg_->set_profile(profile); }
		const AgentMesg_Profile GetProfile() { return agent_mesg_->profile(); }

		void SetDefaultFloatRoundingMode(AgentMesg_Default_float_rounding_mode mode) { agent_mesg_->set_default_float_rounding_mode(mode); }
		const AgentMesg_Default_float_rounding_mode GetDefaultFloatRoundingMode() { return agent_mesg_->default_float_rounding_mode(); }

		void SetFastF16Operation(bool support) { agent_mesg_->set_fast_f16_operation(support); }
		const bool GetFastF16Operation() { return agent_mesg_->fast_f16_operation(); }
	};

}

#endif  // SRC_COMMON_AGENT_H_
