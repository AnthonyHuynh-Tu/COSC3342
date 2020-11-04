#include <stdio.h>
#include <string.h>
#include <stdlib.h> 


enum suits { Clubs, Diamonds, Hearts, Spades };
enum faces { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
             
struct card{
    
    char suits_strTest[9];
    char *faces_strTest;
};
typedef struct card DeckOfCards;

char suits_str[4][9] = {"Clubs", "Diamonds", "Hearts", "Spades"};
char *faces_str[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
            

void shuffle_CardDeck(DeckOfCards []);
void openDeck(DeckOfCards []);
void showCards(const DeckOfCards[]);



int main(int argc, char const *argv[])
{
    char nl='\n';
    DeckOfCards startingDeck[52]= {"",""};
    OpenDeck(startingDeck);
    printf("shuffling deck...\n");
    
    
    while('\n'==nl)
    {
        printf("Here are your cards\n");
        shuffle_CardDeck(startingDeck);
        showCards(startingDeck);
        printf("\n Done...Press any key to end except 'Enter'");
        
        nl=getchar();
    }
    
    
    return 0;
    
}

void OpenDeck(DeckOfCards startingDeck[])
{
    int c=0;
    for(c=0;c<52;c++)
    {
        startingDeck[c].faces_strTest=faces_str[c%13];
        strncpy(startingDeck[c].suits_strTest, suits_str[c/13],9);
    }
}

void shuffle_CardDeck(DeckOfCards startingDeck[])
{
    int swaps=0; 
    int counter=0; 
    DeckOfCards temp={"", ""};
    for(counter=0;counter<52; counter++)
    {
        swaps=rand() % 52;
        temp=startingDeck[counter];
        startingDeck[counter]=startingDeck[swaps];
        startingDeck[swaps]=temp;
    }
}


void showCards(const DeckOfCards startingDeck[])

{
   int display=0;
   for(display=0;display<52;display++)
   {
       printf("%5s of %-10s",startingDeck[display].faces_strTest,startingDeck[display].suits_strTest);
       
       if(((display+1)%3)==0)
       {
           printf("\n");
       }
   }

}
