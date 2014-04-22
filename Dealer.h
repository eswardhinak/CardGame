/*
 * Filename:Dealer.c
 * Author: Eswar Dhinakaran
 * Description: Header file for Dealer.c so its functions  and definitions
 				can be accessed by unit test files and main.c 

*/

#define UNDEALT 0
#define DEALT 1
#define TRUE 1
#define FALSE 0 


int createDeck(int card_array[][13], int seq_array[],  int *cardsDealt);
int shuffleDeck(int seq_array[], int *cardsDealt);
int dealDeck(int card_array[][13], int seq_array[], int num,  int *cardsDealt);
int printDealtCard(int rank, int suit);
