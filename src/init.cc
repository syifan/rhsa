#include "hsa.h"
#include "sender.h"
#include <iostream>
#include "request.pb.h"
#include <cstring>
#include <stdio.h>

extern "C" {

hsa_status_t hsa_init() { 
	sendCommand(9001, "127.0.0.1", "init");
	std::string responseSerialized = receiveStatus();
	InitResponse response = ParseFromString(&responseSerialized);
	return response;

}

int main() {
	std::cout << hsa_init();
}

}
