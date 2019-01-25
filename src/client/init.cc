#include <stdio.h>
#include <boost/fiber/fiber.hpp>
#include <cstring>
#include <iostream>
#include <memory>

#include "include/hsa.h"

#include "src/client/client.h"
#include "src/client/receiver.h"
#include "src/client/rsp_handler.h"
#include "src/proto/msg.pb.h"

extern "C" {

hsa_status_t hsa_init() {
  using namespace rhsa;

  printf("API hsa_init\n");

  auto &client = Client::GetInstance();

  auto succeed = client.EstablishConnection();
  if (!succeed) {
    printf("Establish connection to server failed\n");
    return HSA_STATUS_ERROR_OUT_OF_RESOURCES;
  }

  RspHandler rsp_handler;
  client.receiver->RegisterHandler(&rsp_handler);

  printf("hsa_init sending\n");
  auto msg = std::make_unique<Msg>();
  auto req_init_connection = new ReqInitConnection();
  msg->set_allocated_reqinitconnection(req_init_connection);
  client.conn->Send(*msg);
  printf("hsa_init send done\n");

  printf("start receiving %p\n", &rsp_handler.chan);
  auto rsp = rsp_handler.chan.value_pop();
  printf("rsp type %d\n", rsp->Payload_case());

  // printf("rsp type %d\n", rsp->Payload_case());
  rsp_handler.chan.push(std::unique_ptr<Msg>(nullptr));
  client.receiver->UnregisterHandler(&rsp_handler);

  std::this_thread::sleep_for(std::chrono::seconds(1));

  printf("hsa_init returning\n");
  return HSA_STATUS_SUCCESS;
}
}
