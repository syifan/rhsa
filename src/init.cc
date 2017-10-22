#include "hsa.h"

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#define PORT 9001

extern "C" {

int sock;
struct sockaddr_in connection;



hsa_status_t hsa_init() { 
	printf("Begin server connection...");
	
	memset(&connection, 0, sizeof(connection));
	connection.sin_family = AF_INET;
	connection.sin_addr.s_addr = inet_addr("127.0.0.1");
	connection.sin_port = htons(PORT);

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("Socket creation failed.");
		return HSA_STATUS_ERROR_OUT_OF_RESOURCES;
	}

	if (connect(sock, (struct sockaddr *)&connection, sizeof(struct sockaddr)) < 0) {
		perror("Connection failed.");
		return HSA_STATUS_ERROR_OUT_OF_RESOURCES;
	}

	printf("Connected to server\n");

	send(sock, "ping", 4, 0);
	// recv(sock) 
	
	close(sock);
	return HSA_STATUS_SUCCESS;
}

int main() {
	hsa_init();
}

}
