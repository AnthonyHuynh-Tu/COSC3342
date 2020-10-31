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
	int new_sock; //new socket
	int flags=0, valread;
	int port_number;
	int addrlen = sizeof(address);
	char *hello = "Hello from client"; 
    char buffer[1024] = {0}; 
    int Inet;
    int Connection;
    int Sending;
	
	if (argc<1)
	{
		printf("Too few arguements");
		exit(1);
	}
	
	new_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (new_sock<0)
    { 
        printf("Socket creation error\n"); 
        exit(1); 
    } 
    
    port_number=atoi(argv[1]);
   


	address.sin_family = AF_INET;
	address.sin_addr.s_addr= INADDR_ANY;
	address.sin_port = htons(port_number);
	
	
	Inet= inet_pton(AF_INET, "127.0.0.1", &address.sin_addr);
	if (Inet<=0)
	{
		printf("Invalid address. Address not supported\n");
		return -1;
	}
	
	
	
	Connection= connect(new_sock, (struct sockaddr *)&address, sizeof(address));
	if (Connection<0)
	{
		printf("Connection failed\n");
		exit(1);
	}
	
	send(mysock, buffer, sizeof(buffer), flags);
	
	
	
	recv(mysock, buffer, sizeof(buffer), flags);
	

	
    return 0;

}
	
	
