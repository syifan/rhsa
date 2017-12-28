#include <stdio.h>
#include <cstring>
#include <iostream>

#include "include/hsa.h"

#include "src/conn/connector.h"
#include "src/request/request.h"

extern "C" {

hsa_status_t hsa_init() {
  using namespace rhsa;

  TCPConnector connector;
  auto conn = connector.Connect("127.0.0.1", 9001);

  auto init_req = std::make_unique<InitRequest>();
  conn->Send(init_req.get());

  conn->Recv();

  return HSA_STATUS_SUCCESS;
}

}
