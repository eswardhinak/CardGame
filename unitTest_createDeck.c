/*
 * Filename: unitTest_creatDeck.c
 * Author: Eswar Dhinakaran
 * Description: Tests the C Function createDeck located in Dealer.c
 				and in Dealer.h (header)
 * How to run: To run this file, view the README.

*/


#include <stdio.h>
#include <stdlib.h>
#include "Dealer.h"
int cardsDealt = 4; //number of cards dealt
int *cardsDealtptr = &cardsDealt; //pointer to the number of cards dealt
int cards[4][13];//array with the cards ordered by suit(rows) and ranks(cols)
int seq[52];//array with the order of the cards in the deck
int card_Wrong; //if the card array is set wrong
int seq_Wrong; //if the seq array is set wrong

int main(void){
	testCreateDeck();
	if (card_Wrong == 1 || seq_Wrong == 1){
		if (card_Wrong == 1){
			fprintf(stderr, "Card Array is not being set right!!!\n");
		}
		if(seq_Wrong == 1){
			fprintf(stderr, "Sequence Array is not being set right!!!!\n");
		}
	}
	else{
		fprintf(stderr, "Test Passed with correct card and sequence array sizes\n");
	}
	

}
/* function name: testCreateDeck()
   function description: testCreateDeck()
   Description: checks if cards array has all values set to 0 
   				meaning the cards are not dealt
  				checks if the sequence array is sorted by making
  				sure all the elements are in ascending order from
  				1 to 52
*/
int testCreateDeck(){
	createDeck(cards, seq, cardsDealtptr);
	int card_Wrong=0;
	int i=0;
	/*checks if the card array is correct*/
	for (i=0; i<4; i++){
		int k;
		for(k=0;k<13;k++){
			if (cards[i][k] !=0){
				card_Wrong = 1;
			}

		}
	}
	/*checks if the sequence array is correct*/
	int l;
	for (l=0; l<52; l++){
		if (seq[l]!=l)
			seq_Wrong = 1;

	}
}
