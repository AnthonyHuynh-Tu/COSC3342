#include <stdio.h>
#include <string.h>
#include <stdlib.h> 


enum suits { Clubs, Diamonds, Hearts, Spades };
enum faces { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
             
struct card{
    
    char suits_strTest[9];
    char *faces_strTest;
};
typedef struct card MagicCards;

char suits_str[4][9] = {"Clubs", "Diamonds", "Hearts", "Spades"};
char *faces_str[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
            

void shuffle(MagicCards []);
void openDeck(MagicCards []);
void CardReveal(const MagicCards[]);



int main(int argc, char const *argv[])
{
    char nl='\n';
    MagicCards MyDeck[52]= {"",""};
    OpenDeck(MyDeck);
    printf("shuffling deck...\n");
    
    
    while('\n'==nl)
    {
        printf("Here are your cards\n");
        shuffle(MyDeck);
        CardReveal(MyDeck);
        printf("\n Done...Press any key to end except 'Enter'");
        
        nl=getchar();
    }
    
    
    return 0;
    
}

void OpenDeck(MagicCards MyDeck[])
{
    int c=0;
    for(c=0;c<52;c++)
    {
        MyDeck[c].faces_strTest=faces_str[c%13];
        strncpy(MyDeck[c].suits_strTest, suits_str[c/13],9);
    }
}

void shuffle(MagicCards MyDeck[])
{
     
    int counter=0; 
    int swaps=0;
    MagicCards temp={"", ""};
    for(counter=0;counter<52; counter++)
    {
        swaps=rand() % 52;
        temp=MyDeck[counter];
        MyDeck[swaps]=temp;
        MyDeck[counter]=MyDeck[swaps];
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
