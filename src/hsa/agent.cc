#include <iostream>

#include "include/hsa.h"

#include "src/client/client.h"
//#include "src/request/request.h"

extern "C" {

hsa_status_t hsa_iterate_agents(hsa_status_t (*callback)(hsa_agent_t agent,
                                                         void *data),
                                void *data) {
  //using namespace rhsa;

  //auto &client = Client::GetInstance();
  //auto request_factory = client.request_factory.get();

  //auto query_req = request_factory->BuildQueryAgentRequest();
  //client.conn->Send(query_req.get());

  //auto req = client.conn->Recv();
  //std::cout << "Req received: " << req->GetPayloadCase() << "\n";

  //// All the agents to the client
  //for (int i = 0; i < req->GetNumAgents(); i++) {
    //auto agent = req->GetAgent(i);
    //client.agents.push_back(std::move(agent));
  //}

  //// Traverse all the agents
  //for (auto &agent : client.agents) {
    //// std::cout << agent->GetName() << "\n";
    //if (callback) {
      //hsa_agent_t agent_handle = {uint64_t(agent.get())};
      //callback(agent_handle, data);
    //}
  //}

  return HSA_STATUS_SUCCESS;
}

hsa_status_t hsa_agent_get_info(hsa_agent_t agent, hsa_agent_info_t attribute,
                                void *value) {
  //using namespace rhsa;

  //// auto &client = Client::GetInstance();

  //// auto currentAgent = std::move(client.agents.at(agent.handle));
  //Agent *currentAgent = (Agent *)(agent.handle);

  //switch (attribute) {
    //case HSA_AGENT_INFO_NAME: {
      //std::string name = currentAgent->GetName();
      //strncpy((char *)value, name.c_str(), 64);
      //break;
    //}
    //case HSA_AGENT_INFO_VENDOR_NAME: {
      //std::string vendor = currentAgent->GetVendorName();
      //strncpy((char *)value, vendor.c_str(), 64);
      //break;
    //}
    //case HSA_AGENT_INFO_FEATURE: {
      //*((hsa_agent_feature_t *)value) =
          //(hsa_agent_feature_t)currentAgent->GetFeature();
      //break;
    //}
    //case HSA_AGENT_INFO_MACHINE_MODEL: {
      //*((hsa_machine_model_t *)value) =
          //(hsa_machine_model_t)currentAgent->GetFeature();
      //break;
    //}
    //case HSA_AGENT_INFO_PROFILE: {
      //*((hsa_profile_t *)value) = (hsa_profile_t)currentAgent->GetProfile();
      //break;
    //}
    //case HSA_AGENT_INFO_DEFAULT_FLOAT_ROUNDING_MODE: {
      //*((hsa_default_float_rounding_mode_t *)value) =
          //(hsa_default_float_rounding_mode_t)
              //currentAgent->GetDefaultFloatRoundingMode();
      //break;
    //}
    //case HSA_AGENT_INFO_FAST_F16_OPERATION: {
      //*((bool *)value) = currentAgent->GetFastF16Operation();
      //break;
    //}
    //case HSA_AGENT_INFO_WAVEFRONT_SIZE: {
      //*((uint32_t *)value) = currentAgent->GetWavefrontSize();
      //break;
    //}
    //case HSA_AGENT_INFO_WORKGROUP_MAX_DIM: {
      //uint16_t workgroupMaxDim[3];
      //workgroupMaxDim[0] = currentAgent->GetWorkgroupMaxDimX();
      //workgroupMaxDim[1] = currentAgent->GetWorkgroupMaxDimY();
      //workgroupMaxDim[2] = currentAgent->GetWorkgroupMaxDimZ();
      //value = workgroupMaxDim;
      //break;
    //}
    //case HSA_AGENT_INFO_WORKGROUP_MAX_SIZE: {
      //*((uint32_t *)value) = currentAgent->GetWorkgroupMaxSize();
      //break;
    //}
    //case HSA_AGENT_INFO_GRID_MAX_DIM: {
      //hsa_dim3_t gridMaxDim;
      //gridMaxDim.x = currentAgent->GetGridMaxDimX();
      //gridMaxDim.y = currentAgent->GetGridMaxDimY();
      //gridMaxDim.z = currentAgent->GetGridMaxDimZ();
      //value = &gridMaxDim;
      //break;
    //}
    //case HSA_AGENT_INFO_GRID_MAX_SIZE: {
      //*((uint32_t *)value) = currentAgent->GetGridMaxSize();
      //break;
    //}
    //case HSA_AGENT_INFO_FBARRIER_MAX_SIZE: {
      //*((uint32_t *)value) = currentAgent->GetFBarrierMaxSize();
      //break;
    //}
    //case HSA_AGENT_INFO_QUEUES_MAX: {
      //*((uint32_t *)value) = currentAgent->GetQueuesMax();
      //break;
    //}
    //case HSA_AGENT_INFO_QUEUE_MIN_SIZE: {
      //*((uint32_t *)value) = currentAgent->GetQueueMinSize();
      //break;
    //}
    //case HSA_AGENT_INFO_QUEUE_MAX_SIZE: {
      //*((uint32_t *)value) = currentAgent->GetQueueMaxSize();
      //break;
    //}
    //case HSA_AGENT_INFO_QUEUE_TYPE: {
      //*((hsa_queue_type_t *)value) =
          //(hsa_queue_type_t)currentAgent->GetQueueType();
      //break;
    //}
    //case HSA_AGENT_INFO_NODE: {
      //*((uint32_t *)value) = currentAgent->GetNode();
      //break;
    //}
    //case HSA_AGENT_INFO_DEVICE: {
      //*((hsa_device_type_t *)value) =
          //(hsa_device_type_t)currentAgent->GetDeviceType();
      //break;
    //}
    //case HSA_AGENT_INFO_CACHE_SIZE: {
      //uint16_t cacheSize[4];
      //for (int i = 0; i < 4; i++) {
        //cacheSize[i] = currentAgent->GetCacheSize(i);
      //}
      //value = cacheSize;
      //break;
    //}
    //case HSA_AGENT_INFO_ISA: {
      //hsa_isa_t isa;
      //isa.handle = currentAgent->GetISA();
      //value = &isa;
      //break;
    //}
    //case HSA_AGENT_INFO_EXTENSIONS: {
      //uint8_t extensions[128];
      //for (int i = 0; i < 128; i++) {
        //extensions[i] = currentAgent->GetExtensions(i);
      //}
      //value = extensions;
      //break;
    //}
    //case HSA_AGENT_INFO_VERSION_MAJOR: {
      //*((uint16_t *)value) = currentAgent->GetVersionMajor();
      //break;
    //}
    //case HSA_AGENT_INFO_VERSION_MINOR: {
      //*((uint16_t *)value) = currentAgent->GetVersionMinor();
      //break;
    //}
    //default:
      //std::cout << "Error getting info" << std::endl;
  //}

  return HSA_STATUS_SUCCESS;
}
}
