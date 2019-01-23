#include <stdio.h>
#include <cstring>
#include <memory>
#include <iostream>

#include "include/hsa.h"

#include "src/client/client.h"
#include "src/conn/connector.h"
#include "src/proto/msg.pb.h"

extern "C" {

int port() {
  const char *port_env_str = std::getenv("RHSA_PORT");
  if (port_env_str) {
    return std::stoi(port_env_str);
  }

  return 9001;
}

hsa_status_t hsa_init() {
  using namespace rhsa;

  printf("API hsa_init\n");

  auto &client = Client::GetInstance();

  TCPConnector connector(&client.encoder);
  auto conn = connector.Connect("127.0.0.1", port());
  client.conn = std::move(conn);


  //auto request_factory = client.request_factory.get();
  //auto init_req = request_factory->BuildInitRequest();
  //client.conn->Send(init_req.get());

  printf("hsa_init sending\n");
  auto msg = std::make_unique<Msg>();
  auto req_init_connection = new ReqInitConnection();
  msg->set_allocated_reqinitconnection(req_init_connection);
  client.conn->Send(*msg);
  printf("hsa_init send done\n");


  // conn->Recv();

  return HSA_STATUS_SUCCESS;
}

}
