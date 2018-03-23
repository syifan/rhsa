#include <stdio.h>
#include <cstring>
#include <memory>
#include <iostream>

#include "include/hsa.h"

#include "src/client/client.h"
#include "src/conn/connector.h"
#include "src/request/request.h"

extern "C" {

hsa_status_t hsa_init() {
  using namespace rhsa;

  auto &client = Client::GetInstance();

  TCPConnector connector;
  auto conn = connector.Connect("127.0.0.1", 9001);
  client.conn = std::move(conn);


  auto request_factory = client.request_factory.get();
  auto init_req = request_factory->BuildInitRequest();
  client.conn->Send(init_req.get());

  // conn->Recv();

  return HSA_STATUS_SUCCESS;
}

}
