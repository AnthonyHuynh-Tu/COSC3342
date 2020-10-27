#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>




int main(int argc, char const *argv[])
{
	struct sockaddr_in address;
	int mysock; //sockfd
	int flags=0, valread;
	int port_number;
	int addrlen = sizeof(address);
	char *hello = "Hello from client"; 
    char buffer[1024] = {0}; 
	
	
	
	if ((mysock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   


	address.sin_family = AF_INET;
	address.sin_addr.s_addr= INADDR_ANY;
	address.sin_port = htons(port_number);
	
	
	if (inet_pton(AF_INET, "127.0.0.1", &address.sin_addr)<=0)
	{
		printf("Invalid address. Address not supported\n");
		return -1;
	}
	
	
	
	if (connect(mysock, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		printf("Connection failed\n");
		return -1;
	}
	
	if ssize_t (send(mysock, const void *buf, size_t len, flags));
	{
		printf("Send failure\n");
		return -1;
	}
	
	
	if ssize_t (recv(mysock, void *buf, size_t len, flags));
	{
		printf("Receiving failure\n");
		return -1;
	}

	
    return 0;

}
	
	
