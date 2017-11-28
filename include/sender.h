#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include "hsa.h"
#include <iostream>

extern "C" 
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


	std::string receiveStatus ()
	{
		int reslength = recv(sock, buffer, sizeof(hsa_status_t), 0);
		for (int i=0;i<reslength;i++) {
			printf("%02x ", buffer[i]);
		}
	}
}
