#include "hsa.h"
#include "sender.h"
#include <iostream>

extern "C" {

hsa_status_t hsa_init() { 
	sendCommand(9001, "127.0.0.1", "init");
	hsa_status_t response;
	response = receiveStatus();
	return response;

}

int main() {
	std::cout << hsa_init();
}

}
