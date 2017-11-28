#include "hsa.h"
#include "sender.h"
#include <iostream>
#include "request.pb.h"
#include "init.pb.h"
#include <cstring>
#include <stdio.h>

extern "C" {

hsa_status_t hsa_init() {
	
	std::string srequest; 
	rhsa::Request* request = new rhsa::Request();

	request->set_init(true);
	(*request).SerializeToString(&srequest);
	sendCommand(9001, "127.0.0.1", srequest.c_str());
	std::string responseSerialized = receiveStatus();
	rhsa::Request response;
	response.ParseFromString(responseSerialized);
	return (hsa_status_t) response.initresponse().type();

}

int main() {
	std::cout << hsa_init();
}

}
