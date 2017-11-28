#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include "hsa.h"
#include "../src/request.pb.h"
#include <iostream>

class Connectio
{
	int sock;
	struct sockaddr_in connection;
	char buffer[1024];

	void sendCommand (int port, char* address, const char* message)
	{
		printf("Begin server connection...\n");
		memset(&connection, 0, sizeof(connection));
		connection.sin_family = AF_INET;
		connection.sin_addr.s_addr = inet_addr(address);
		connection.sin_port =htons(port);

		if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		{
			perror("Socket creation failed.");
			return;
		}

		if (connect(sock, (struct sockaddr *)&connection, sizeof(struct sockaddr)) < 0)
		{
			perror("Connection failed.");
			return;
		}

		printf("Connected to server.\n");

		send(sock, message, 4, 0);

		return;
	}


	rhsa::Request receiveResponse ()
	{
		int reslength = recv(sock, buffer, sizeof(), 0);
		
	}
}
