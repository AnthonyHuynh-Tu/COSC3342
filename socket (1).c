#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

extern int randperm(int *, int);

int main(int argc, char const *argv[])
{
	struct sockaddr_in address;
	int mysock; //sockfd
	int flags;  
	int new_sock; //new socket
	int deckofCards[52]; //deckofCards
	int port_number;
	int addrlen = sizeof(address);
	char buffer[1024];
	const char *deal = "deal";
	
	
	if(argc<=1)
	{
		printf("Not enough arguements, try again.");
		exit(1);
	}
	
	port_number=atoi(argv[1]);
	
	mysock = socket(AF_INET,SOCK_STREAM,0);
	
	if(mysock<0)
	{
		printf("Error");
		exit(1);
	}
	
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr= INADDR_ANY;
	address.sin_port = htons(port_number);
	
	
	if (bind(mysock, (struct sockaddr*) &address, sizeof(address))<0)
	
	{
		printf("binding error");
		exit(1);
	}
	
	if (listen(mysock, 10)<0)
	
	{
		printf("listening error");
		exit(1);
	}
	
	fprintf(stdout,"Connecting...\n");
	
	while(1)
	{
		new_sock=accept(mysock, (struct sockaddr*) &address, (socklen_t*) &addrlen);
		if(new_sock<0)
		{
			printf("Acceptance error");
			exit(1);
		}
		
		flags=read(new_sock,buffer,sizeof(buffer));
		
		int comparingString=strcmp(buffer,deal);
		
		if(comparingString==0)
		{
			sprintf(buffer,"Take a seat, dealing has begun\n");
			send(new_sock,buffer,strlen(buffer),0);
			
			for(int i=0;i<52;i++)
			{
					deckofCards[i]=i+1;
			}
			
			randperm(deckofCards,52);
			
			for(int j=0;j<52;j++)
			{
				sprintf(buffer, "Card %d %d\r\n", j+1, deckofCards[j]);
				send(new_sock,buffer,strlen(buffer), 0);
			}
		}
	
	else
	{
			sprintf(buffer,"Server error, unresponsive\n");
			send(new_sock,buffer,strlen(buffer),0);
	}
	
	
}
	
return 0;	
	
}
