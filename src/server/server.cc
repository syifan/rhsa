#include "src/server/server.h"

#include <iostream>

#include "hsa/hsa.h"
#include "hsa/hsa_ext_finalize.h"

#include "src/conn/disconnect_exception.h"
#include "src/proto/msg.pb.h"

namespace rhsa {

void loadAgentName(hsa_agent_t agent, Agent *agent_info) {
  char name[64];
  hsa_agent_get_info(agent, HSA_AGENT_INFO_NAME, name);
  agent_info->set_name(name);
}

void loadVendorName(hsa_agent_t agent, Agent *agent_info) {
  char name[64];
  hsa_agent_get_info(agent, HSA_AGENT_INFO_VENDOR_NAME, name);
  agent_info->set_vendor_name(name);
}

void loadFeature(hsa_agent_t agent, Agent *agent_info) {
  int feature;
  hsa_agent_get_info(agent, HSA_AGENT_INFO_FEATURE, &feature);
  if (feature == 1 || feature == 2) {
    agent_info->set_feature((Agent_Feature)feature);
  }
}

void loadMachineModel(hsa_agent_t agent, Agent *agent_info) {
  int machineModel;
  hsa_agent_get_info(agent, HSA_AGENT_INFO_MACHINE_MODEL, &machineModel);
  agent_info->set_machine_model((Agent_Machine_model)machineModel);
}

void loadProfile(hsa_agent_t agent, Agent *agent_info) {
  int profile;
  hsa_agent_get_info(agent, HSA_AGENT_INFO_PROFILE, &profile);
  agent_info->set_profile((Agent_Profile)profile);
}

void loadDefaultFloatRoundingMode(hsa_agent_t agent, Agent *agent_info) {
  int mode;
  hsa_agent_get_info(agent, HSA_AGENT_INFO_DEFAULT_FLOAT_ROUNDING_MODE, &mode);
  agent_info->set_default_float_rounding_mode(
      (Agent_Default_float_rounding_mode)mode);
}

// What happens if this is undef?
void loadFastF16Operation(hsa_agent_t agent, Agent *agent_info) {
  bool support;
  hsa_agent_get_info(agent, HSA_AGENT_INFO_FAST_F16_OPERATION, &support);
  agent_info->set_fast_f16_operation(support);
}

void loadWavefrontSize(hsa_agent_t agent, Agent *agent_info) {
  uint32_t size;
  hsa_agent_get_info(agent, HSA_AGENT_INFO_WAVEFRONT_SIZE, &size);
  agent_info->set_wavefront_size(size);
}

void loadWorkgroupMaxDims(hsa_agent_t agent, Agent *agent_info) {
  uint16_t dims[3];
  hsa_agent_get_info(agent, HSA_AGENT_INFO_WORKGROUP_MAX_DIM, &dims);
  agent_info->set_workgroup_max_dim_x(dims[0]);
  agent_info->set_workgroup_max_dim_y(dims[1]);
  agent_info->set_workgroup_max_dim_z(dims[2]);
}

void loadWorkgroupMaxSize(hsa_agent_t agent, Agent *agent_info) {
  uint32_t size;
  hsa_agent_get_info(agent, HSA_AGENT_INFO_WORKGROUP_MAX_SIZE, &size);
  agent_info->set_workgroup_max_size(size);
}

void loadGridMaxDims(hsa_agent_t agent, Agent *agent_info) {
  hsa_dim3_t dims;
  hsa_agent_get_info(agent, HSA_AGENT_INFO_GRID_MAX_DIM, &dims);
  agent_info->set_grid_max_dim_x(dims.x);
  agent_info->set_grid_max_dim_y(dims.y);
  agent_info->set_grid_max_dim_z(dims.z);
}

void loadGridMaxSize(hsa_agent_t agent, Agent *agent_info) {
  uint32_t size;
  hsa_agent_get_info(agent, HSA_AGENT_INFO_GRID_MAX_SIZE, &size);
  agent_info->set_grid_max_size(size);
}

void loadFBarrierMaxSize(hsa_agent_t agent, Agent *agent_info) {
  uint32_t size;
  hsa_agent_get_info(agent, HSA_AGENT_INFO_FBARRIER_MAX_SIZE, &size);
  agent_info->set_fbarrier_max_size(size);
}

void loadQueuesMax(hsa_agent_t agent, Agent *agent_info) {
  uint32_t max;
  hsa_agent_get_info(agent, HSA_AGENT_INFO_QUEUES_MAX, &max);
  agent_info->set_queues_max(max);
}

void loadQueueMinSize(hsa_agent_t agent, Agent *agent_info) {
  uint32_t min;
  hsa_agent_get_info(agent, HSA_AGENT_INFO_QUEUE_MIN_SIZE, &min);
  agent_info->set_queue_min_size(min);
}

void loadQueueMaxSize(hsa_agent_t agent, Agent *agent_info) {
  uint32_t max;
  hsa_agent_get_info(agent, HSA_AGENT_INFO_QUEUE_MAX_SIZE, &max);
  agent_info->set_queue_max_size(max);
}

void loadQueueType(hsa_agent_t agent, Agent *agent_info) {
  int type;
  hsa_agent_get_info(agent, HSA_AGENT_INFO_QUEUE_TYPE, &type);
  agent_info->set_queue_type((Agent_Queue_type)type);
}

void loadNode(hsa_agent_t agent, Agent *agent_info) {
  uint32_t node;
  hsa_agent_get_info(agent, HSA_AGENT_INFO_NODE, &node);
  agent_info->set_node(node);
}

void loadDeviceType(hsa_agent_t agent, Agent *agent_info) {
  int type;
  hsa_agent_get_info(agent, HSA_AGENT_INFO_DEVICE, &type);
  agent_info->set_device((Agent_Device_type)type);
}

void loadCacheSize(hsa_agent_t agent, Agent *agent_info) {
  uint32_t sizes[4];
  hsa_agent_get_info(agent, HSA_AGENT_INFO_CACHE_SIZE, &sizes);
  agent_info->set_cache_size_l1(sizes[0]);
  agent_info->set_cache_size_l2(sizes[1]);
  agent_info->set_cache_size_l3(sizes[2]);
  agent_info->set_cache_size_l4(sizes[3]);
}

void loadISA(hsa_agent_t agent, Agent *agent_info) {
  uint64_t handle;
  hsa_agent_get_info(agent, HSA_AGENT_INFO_ISA, &handle);
  agent_info->set_isa(handle);
}

void loadExtensions(hsa_agent_t agent, Agent *agent_info) {
  uint8_t extensions[128];
  hsa_agent_get_info(agent, HSA_AGENT_INFO_EXTENSIONS, &extensions);

  for (int i = 0; i < 128; i++) {
    agent_info->add_agent_extensions(extensions[i]);
  }
}

void loadVersionMajor(hsa_agent_t agent, Agent *agent_info) {
  uint16_t version;
  hsa_agent_get_info(agent, HSA_AGENT_INFO_VERSION_MAJOR, &version);
  agent_info->set_version_major(version);
}

void loadVersionMinor(hsa_agent_t agent, Agent *agent_info) {
  uint16_t version;
  hsa_agent_get_info(agent, HSA_AGENT_INFO_VERSION_MINOR, &version);
  agent_info->set_version_minor(version);
}

hsa_status_t storeAgent(hsa_agent_t agent, void *data) {
  auto agents = static_cast<std::vector<std::unique_ptr<rhsa::Agent>> *>(data);

  auto agent_info = std::make_unique<rhsa::Agent>();

  loadDeviceType(agent, agent_info.get());
  std::cout << agent_info->device() << "\n";
  if (agent_info->device() == 1) {
    loadAgentName(agent, agent_info.get());
    loadVendorName(agent, agent_info.get());
    loadFeature(agent, agent_info.get());
    loadMachineModel(agent, agent_info.get());
    loadProfile(agent, agent_info.get());
    loadDefaultFloatRoundingMode(agent, agent_info.get());
    loadFastF16Operation(agent, agent_info.get());
    loadWavefrontSize(agent, agent_info.get());
    loadWorkgroupMaxDims(agent, agent_info.get());
    loadWorkgroupMaxSize(agent, agent_info.get());
    loadGridMaxDims(agent, agent_info.get());
    loadGridMaxSize(agent, agent_info.get());
    loadFBarrierMaxSize(agent, agent_info.get());
    loadQueuesMax(agent, agent_info.get());
    loadQueueMinSize(agent, agent_info.get());
    loadQueueMaxSize(agent, agent_info.get());
    loadQueueType(agent, agent_info.get());
    loadNode(agent, agent_info.get());
    loadCacheSize(agent, agent_info.get());
    loadISA(agent, agent_info.get());
    loadExtensions(agent, agent_info.get());
    loadVersionMajor(agent, agent_info.get());
    loadVersionMinor(agent, agent_info.get());

    std::cout << agent_info->name() << "\n";
    // std::cout << agent_info->GetVendorName() << "\n";
    // std::cout << agent_info->GetFeature() << "\n";
    // std::cout << agent_info->GetMachineModel() << "\n";
    // std::cout << agent_info->GetProfile() << "\n";
    // std::cout << agent_info->GetDefaultFloatRoundingMode() << "\n";
    // std::cout << agent_info->GetFastF16Operation() << "\n";
    // std::cout << agent_info->GetWavefrontSize() << "\n";
    // std::cout << agent_info->GetWorkgroupMaxDimX() << "\n";
    // std::cout << agent_info->GetWorkgroupMaxDimY() << "\n";
    // std::cout << agent_info->GetWorkgroupMaxDimZ() << "\n";
    // std::cout << agent_info->GetWorkgroupMaxSize() << "\n";
    // std::cout << agent_info->GetGridMaxDimX() << "\n";
    // std::cout << agent_info->GetGridMaxDimY() << "\n";
    // std::cout << agent_info->GetGridMaxDimZ() << "\n";
    // std::cout << agent_info->GetGridMaxSize() << "\n";
    // std::cout << agent_info->GetQueuesMax() << "\n";
    // std::cout << agent_info->GetQueueMinSize() << "\n";
    // std::cout << agent_info->GetQueueMaxSize() << "\n";
    // std::cout << agent_info->GetQueueType() << "\n";
    // std::cout << agent_info->GetNode() << "\n";
    // std::cout << agent_info->GetCacheSize(1) << "\n";
    // std::cout << agent_info->GetCacheSize(2) << "\n";
    // std::cout << agent_info->GetCacheSize(3) << "\n";
    // std::cout << agent_info->GetCacheSize(4) << "\n";
    // std::cout << agent_info->GetISA() << "\n";
    // std::cout << agent_info->GetVersionMajor() << "\n";
    // std::cout << agent_info->GetVersionMinor() << "\n";

    agents->push_back(std::move(agent_info));
  }

  return HSA_STATUS_SUCCESS;
}

void Server::Init() {
  hsa_init();
  IterateAgents();
}

void Server::IterateAgents() { hsa_iterate_agents(storeAgent, &agents_); };

// void Server::HandleQueryAgent(Connection *conn, Request *req) {
// for (auto &agent : agents_) {
// req->AddAgent(agent.get());
//}

// conn->Send(req);
//}

void Server::HandleInitConnection(Connection *conn, Msg *msg) {
  auto rsp = std::make_unique<Msg>();
  auto rsp_init_connection = new RspInitConnection();
  rsp->set_allocated_rspinitconnection(rsp_init_connection);
  for (auto& a : this->agents_) {
    auto agent = rsp_init_connection->add_agents();
    agent->CopyFrom(*a);
  }
  conn->Send(*rsp);
}

void Server::Handle(std::unique_ptr<Connection> conn) {
  std::cout << "Connected and handling.\n";
  try {
    while (true) {
      auto msg = conn->Recv();
      std::cout << "Received: " << msg->Payload_case() << "\n";
      switch (msg->Payload_case()) {
        case Msg::kReqInitConnection:
          HandleInitConnection(conn.get(), msg.get());
          break;
        default:
          throw "Unknown message type received.";
      }
    }
  } catch (DisconnectException &e) {
    std::cout << "Client disconnected.\n";
  }
}
}  // namespace rhsa
