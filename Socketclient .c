#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>


enum suits { Clubs, Diamonds, Hearts, Spades };
enum faces { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

struct card
{
    char *faces_strTest;
    char suits_strTest[9];
};


typedef struct card MagicCards;

char suits_str[4][9] = {"Clubs", "Diamonds", "Hearts", "Spades"};
char *faces_str[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

void OpenDeck(MagicCards []);
void shuffle(MagicCards []);
void CardReveal(const MagicCards[]);

int main(int argc, char const *argv[])
{
	struct sockaddr_in address;
	int mysock; //sockfd
	int new_sock=0; //new socket
	int flags=0, valread;
	int port_number;
	int addrlen = sizeof(address);
	char message[2000];
	char response[2000];
    char output[1024]; 
    const char *deal="Deal";
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
		exit(1);
	}
	
	
	
	Connection= connect(new_sock, (struct sockaddr *)&address, sizeof(address));
	if (Connection<0)
	{
		printf("Connection has failed\n");
		exit(1);
	}
	
	
	while(1)
	{
		printf("Type 'Deal' to begin: \n");
		scanf("%s",message);

		if(send(new_sock, message, strlen(message),0) <0)
		{
			printf("Message send has failed");
			return 1;	
		}
	
		if(recv(new_sock, response,2000,0)<0)
		{
			printf("Recieving message has failed");
			break;
		}
		else
		{

			puts("Server reply :");
			puts(response);
			int compareStrings=strcmp(message,deal);
			if(compareStrings==0)
			{
				char nl='\t';
				MagicCards MyDeck[52]= {"",""};
				OpenDeck(MyDeck);
	   	 		printf("Shuffling the deck...\n");
				while('\t'==nl)
    				{
			        	printf("Here are your cards:\n");
			        	shuffle(MyDeck);
			        	CardReveal(MyDeck);
        				printf("\n Hooray!...Now type 'Deal' again to deal cards once more");
						nl=getchar();
        				
    				}
			}
			else if(compareStrings!=0){
				char str[1024]="Wrong word, try again...";
				sprintf(output,"%s",str);
				printf("%s", output);
			}
		}
		
		
	}
	
	close(new_sock);
	return 0;
}




void OpenDeck(MagicCards MyDeck[])
{
    int c=0;
    for(c=0;c<52;c++)
    {
        MyDeck[c].faces_strTest=faces_str[c%13];
        strncpy(MyDeck[c].suits_strTest, suits_str[c/13],52);
    }
}
void shuffle(MagicCards MyDeck[])
{
    int swaps=0; 
    int counter=0; 
    MagicCards temp={"", ""};
    
    for(counter=0;counter<52; counter++)
    {
        swaps=rand() % 52;
        temp=MyDeck[counter];
        MyDeck[counter]=MyDeck[swaps];
        MyDeck[swaps]=temp;
    }
}

void CardReveal(const MagicCards MyDeck[])

{
   int display=0;
   for(display=0;display<52;display++)
   {
       printf("%5s of %-10s",MyDeck[display].faces_strTest,MyDeck[display].suits_strTest);
       if(((display+1)%3)==0)
       {
           printf("\n");
       }
   }

}
	
	
