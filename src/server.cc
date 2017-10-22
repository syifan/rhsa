#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#define PORT 9001

int sock;
struct sockaddr_in connection;
int connlen = sizeof(connection);

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
	printf("%s\n",buffer );
	return 0;
}
