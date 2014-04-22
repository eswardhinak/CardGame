/*
 * Filename:Dealer.c
 * Author: Eswar Dhinakaran
 * Description: Is the "Dealer" that shuffles, deals and recreates the deck


*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Dealer.h"
#include "Dealer.h"

/*String values of the suits to be printed to user*/
const char *suits[] = {"Hearts", "Diamonds", "Spades", "Clubs"};
/*String values of the ranks to be printed to user*/
const char *ranks[] = {"Ace", "Two", "Three", "Four", "Five", "Six"
,"Seven", "Eight", "Nine", "Ten", "Jack","Queen", "King"};

/*Function Name: createDeck()
  Function Prototype: int createDeck(int card_array[][13],
  					int seq_array[], int *cardsDealt)
  Description: It resets the value of the cards to UNDEALT
  				and sets the sequence array back to the reordered
  				sequence (0,1,2...51)
  Parameters: 
  			card_array: 2D array of the cards in the deck
  			seq_array: array that holds what order the cards are in
  			cardsDealt: pointer to the number of cards that have been
  						dealt so that it can be reset to 0
  Returns: */

int createDeck(int card_array[][13], int seq_array[], int *cardsDealt){
	int i; //array index
	*cardsDealt=0; //resets number of dealt cards to 0
	/*resets value of all cards to UNDEALT*/
	for (i = 0; i<4; i++){
		int j;
		for (j=0; j<13;j++){
			card_array[i][j] = UNDEALT;
		}
	}
	/*re orders the array of what order deck is in*/
	for (i = 0 ; i < 52; i++){
		seq_array[i]=i;
	}
	

}
/*Function Name: shuffleDeck()
  Function Prototype: int shuffleDeck(int seq_array[], 
  					int *cardsDealt)
  Description: shuffles the values in the sequence array by
  				conducting 2000 random swaps of two random cards
  				from the deck.
  Parameters: 
   			seq_array: array that holds what order the cards are in
  			cardsDealt: pointer to the number of cards that have been
  						dealt 
  Returns: FALSE if only 1 or 0 cards remain. 
  			TRUE after shuffling >=2 cards*/

int shuffleDeck(int seq_array[], int *cardsDealt){
	/*atleast two cards have to remain to shuffle*/
	if(*cardsDealt<51){
		int j = 2000; //number of shuffles to do
		srand(time(NULL));//seed the random number generator
		int i;
		for (i = 0; i < j; i++){
			int first = rand()%52; //first sequence spot to swap
			int second=rand()%52;//second sequence spot to swap
			int temp = seq_array[first]; //holds value of first sequence
			seq_array[first]=seq_array[second]; //swaps first element with second
			seq_array[second]=temp; //swaps second element with first
		}
		return TRUE;
	}
	else return FALSE;

}

/*Function Name: dealDeck()
  Function Prototype: int dealDeck(int card_array, int seq_array[], int num
  					int *cardsDealt)
  Description: deals cards to the user by giving them the number
  				of specified cards off the top of the deck
  Parameters: 
  			card_array: array that holds the cards
  			seq_array: array that holds the order of the cards
			num: the number of cards the user wants to be dealt
  			cardsDealt: pointer to the number of cards that have been
  						dealt 
  Returns: */

int dealDeck(int card_array[][13], int seq_array[], int num, int *cardsDealt){
	int i;
	for (i=0;i<num;i++){
		/*makes sure that not all cards have been dealt*/
		if(*cardsDealt < 52){
			int j;
			for (j=0; j<52; j++){
				/*algorithm to find the suit and rank of the 
				card based on its uniqee sequence number from
				0 to 51*/
				int topCard = seq_array[j]; 
				int cardsuit= topCard/13; //divide to find the suit
				int cardrank = topCard-(13*cardsuit); //find the rank
				/*checks to make sure this card was not dealt already*/
				if(card_array[cardsuit][cardrank] != DEALT){
					card_array[cardsuit][cardrank]=DEALT;
					printDealtCard(cardrank, cardsuit);
					(*cardsDealt)++;
					break;
				}	
				
			}

		}
		else{
			break;
		}

	}	

}

/*Function name: printDealtCard()
Function prototype: printDealtCard(int rank, int suit)
Description: Prints the value of the card based on its location
				in the cards array using the const char arrays
				suits and ranks
				Suits: 0 = Heart, 1 = Diamond, 2 = Spades, 3 = Clubs
				ranks: 0 - 12  corresponds to A - K
Parameters: rank: rank of the card
			suit: suit of the card
*/

int printDealtCard(int rank, int suit){
	fprintf(stdout, "\t%s of %s\n", ranks[rank], suits[suit]);
}