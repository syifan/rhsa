#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include "../include/hsa.h"
#include "request.pb.h"

#define PORT 9001

using namespace std;

int sock;
struct sockaddr_in connection;
int connlen = sizeof(connection);

void AddSuccess(rhsa::Request r) {
	InitResponse* response;
	response->set_type(InitResponse::HSA_STATUS_SUCCESS);
	r.set_allocated_initresponse(response);
}

int main() 
{
	int new_socket, valread;
	char buffer[1024] = {0};
	memset(&connection, 0, sizeof(connection));

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket");
		return 1;
	}

	connection.sin_family = AF_INET;
	connection.sin_addr.s_addr = INADDR_ANY;
	connection.sin_port = htons( PORT );

	if (bind(sock, (struct sockaddr *)&connection, sizeof(struct sockaddr)) < 0)
	{
		perror("bind");
		return 1;
	}

	if (listen(sock, 10) < 0)
	{
		perror("listen");
		return 1;
	}

	if ((new_socket = accept(sock, (struct sockaddr *)&connection, (socklen_t*)&connlen)) < 0)
	{
		perror("accept");
		return 1;
	}
	valread = read(new_socket, buffer, 1024);
	cout << strncmp(buffer, "init", 4);
	
	if (strncmp(buffer, "init", 4) == 0)
	{
		string* sresponse;
		rhsa::Request request;
		AddSuccess(request);
		request.SerializeToString(sresponse);
		send(new_socket, sresponse, 1024, 0);
	}
	return 0;
}
