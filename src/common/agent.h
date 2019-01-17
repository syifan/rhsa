#ifndef SRC_COMMON_AGENT_H_
#define SRC_COMMON_AGENT_H_

#include <memory>

#include "src/proto/request.pb.h"

namespace rhsa {

class Agent {
  std::unique_ptr<AgentMesg> agent_mesg_;

 public:
  Agent() { agent_mesg_ = std::make_unique<AgentMesg>(); }

  Agent(AgentMesg *msg) { 
    agent_mesg_ = std::make_unique<AgentMesg>(); 
    *agent_mesg_.get() = *msg;
  }

  AgentMesg *GetAgentMesg() {
    return agent_mesg_.get();
  }

  void SetName(const char *name) { agent_mesg_->set_name(name); }
  const std::string GetName() { return agent_mesg_->name(); }

  void SetVendorName(const char *name) { agent_mesg_->set_vendor_name(name); }
  const std::string GetVendorName() { return agent_mesg_->vendor_name(); }

  void SetFeature(AgentMesg_Feature feature) {
    agent_mesg_->set_feature(feature);
  }
  const AgentMesg_Feature GetFeature() { return agent_mesg_->feature(); }

  void SetMachineModel(AgentMesg_Machine_model model) {
    agent_mesg_->set_machine_model(model);
  }
  const AgentMesg_Machine_model GetMachineModel() {
    return agent_mesg_->machine_model();
  }

  void SetProfile(AgentMesg_Profile profile) {
    agent_mesg_->set_profile(profile);
  }
  const AgentMesg_Profile GetProfile() { return agent_mesg_->profile(); }

  void SetDefaultFloatRoundingMode(AgentMesg_Default_float_rounding_mode mode) {
    agent_mesg_->set_default_float_rounding_mode(mode);
  }
  const AgentMesg_Default_float_rounding_mode GetDefaultFloatRoundingMode() {
    return agent_mesg_->default_float_rounding_mode();
  }

  void SetFastF16Operation(bool support) {
    agent_mesg_->set_fast_f16_operation(support);
  }
  const bool GetFastF16Operation() { return agent_mesg_->fast_f16_operation(); }

  void SetWavefrontSize(uint32_t size) {
    agent_mesg_->set_wavefront_size(size);
  }
  const uint32_t GetWavefrontSize() { return agent_mesg_->wavefront_size(); }

  void SetWorkgroupMaxDimX(uint32_t dim) {
    agent_mesg_->set_workgroup_max_dim_x(dim);
  }
  const uint32_t GetWorkgroupMaxDimX() {
    return agent_mesg_->workgroup_max_dim_x();
  }

  void SetWorkgroupMaxDimY(uint32_t dim) {
    agent_mesg_->set_workgroup_max_dim_y(dim);
  }
  const uint32_t GetWorkgroupMaxDimY() {
    return agent_mesg_->workgroup_max_dim_y();
  }

  void SetWorkgroupMaxDimZ(uint32_t dim) {
    agent_mesg_->set_workgroup_max_dim_z(dim);
  }
  const uint32_t GetWorkgroupMaxDimZ() {
    return agent_mesg_->workgroup_max_dim_z();
  }

  void SetWorkgroupMaxSize(uint32_t size) {
    agent_mesg_->set_workgroup_max_size(size);
  }
  const uint32_t GetWorkgroupMaxSize() {
    return agent_mesg_->workgroup_max_size();
  }

  void SetGridMaxDimX(uint32_t dim) { agent_mesg_->set_grid_max_dim_x(dim); }
  const uint32_t GetGridMaxDimX() { return agent_mesg_->grid_max_dim_x(); }

  void SetGridMaxDimY(uint32_t dim) { agent_mesg_->set_grid_max_dim_y(dim); }
  const uint32_t GetGridMaxDimY() { return agent_mesg_->grid_max_dim_y(); }

  void SetGridMaxDimZ(uint32_t dim) { agent_mesg_->set_grid_max_dim_z(dim); }
  const uint32_t GetGridMaxDimZ() { return agent_mesg_->grid_max_dim_z(); }

  void SetGridMaxSize(uint32_t size) { agent_mesg_->set_grid_max_size(size); }
  const uint32_t GetGridMaxSize() { return agent_mesg_->grid_max_size(); }

  void SetFBarrierMaxSize(uint32_t size) {
    agent_mesg_->set_fbarrier_max_size(size);
  }
  const uint32_t GetFBarrierMaxSize() {
    return agent_mesg_->fbarrier_max_size();
  }

  void SetQueuesMax(uint32_t max) { agent_mesg_->set_queues_max(max); }
  const uint32_t GetQueuesMax() { return agent_mesg_->queues_max(); }

  void SetQueueMinSize(uint32_t min) { agent_mesg_->set_queue_min_size(min); }
  const uint32_t GetQueueMinSize() { return agent_mesg_->queue_min_size(); }

  void SetQueueMaxSize(uint32_t max) { agent_mesg_->set_queue_max_size(max); }
  const uint32_t GetQueueMaxSize() { return agent_mesg_->queue_max_size(); }

  void SetQueueType(AgentMesg_Queue_type type) {
    agent_mesg_->set_queue_type(type);
  }
  const AgentMesg_Queue_type GetQueueType() {
    return agent_mesg_->queue_type();
  }

  void SetNode(uint32_t node) { agent_mesg_->set_node(node); }
  const uint32_t GetNode() { return agent_mesg_->node(); }

  void SetDeviceType(AgentMesg_Device_type type) {
    agent_mesg_->set_device(type);
  }
  const AgentMesg_Device_type GetDeviceType() { return agent_mesg_->device(); }

  void SetCacheSize(uint32_t size, int type) {
    switch (type) {
      case 1:
        agent_mesg_->set_cache_size_l1(size);
        break;
      case 2:
        agent_mesg_->set_cache_size_l2(size);
        break;
      case 3:
        agent_mesg_->set_cache_size_l3(size);
        break;
      case 4:
        agent_mesg_->set_cache_size_l4(size);
        break;
      default:
        break;
    }
  }

  const uint32_t GetCacheSize(int type) {
    switch (type) {
      case 1:
        return agent_mesg_->cache_size_l1();
      case 2:
        return agent_mesg_->cache_size_l2();
      case 3:
        return agent_mesg_->cache_size_l3();
      case 4:
        return agent_mesg_->cache_size_l4();
      default:
        return 0;
    }
  }

  void SetISA(uint64_t handle) { agent_mesg_->set_isa(handle); }
  const uint64_t GetISA() { return agent_mesg_->isa(); }

  void SetExtension(uint8_t extension) {
    agent_mesg_->add_agent_extensions(extension);
  }
  const uint8_t GetExtensions(int index) {
    return agent_mesg_->agent_extensions(index);
  }

  void SetVersionMajor(uint16_t version) {
    agent_mesg_->set_version_major(version);
  }
  const uint16_t GetVersionMajor() { return agent_mesg_->version_major(); }

  void SetVersionMinor(uint16_t version) {
    agent_mesg_->set_version_minor(version);
  }
  const uint16_t GetVersionMinor() { return agent_mesg_->version_minor(); }
};
}

#endif  // SRC_COMMON_AGENT_H_
