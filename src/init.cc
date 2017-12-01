#include <stdio.h>
#include <cstring>
#include <iostream>

#include "include/hsa.h"
#include "src/conn/connector.h"

extern "C" {

hsa_status_t hsa_init() {
  using namespace rhsa;

  TCPConnector connector;
  connector.Connect("127.0.0.1", 9001);
}

}
