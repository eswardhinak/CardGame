/*
 * Filename: unitTest_dealDeck.c
 * Author: Eswar Dhinakaran
 * Description: Tests the C Function dealDeck located in Dealer.c
 				and in Dealer.h (header)
 				This should be run after verifiying shuffleDeck and
 				createDeck by running their unit tests.
 * How to run: To run this file, view the README.

*/

#include <stdio.h>
#include <stdlib.h>
#include "Dealer.h"

int cards[4][13]; //array of cards: rows = suits; cols = ranks
int sequence[52]; //array with the sequence of the cards
int num=0;//number of cards to deal 
int cardsDealt = 0; //number of cards that has been dealt
int *cdptr = &cardsDealt; //pointer to the number of dealt cards
int test_fail = 0; //indicates if tests fail

int main(void){
	createDeck(cards, sequence, cdptr);//creates the Deck in ordered
	shuffleDeck(sequence, cdptr); //shuffles the Deck
	dealDeck(cards, sequence, 14, cdptr); //this is what we are testing

	/*check how many cards were dealt by checking how many 1's 
	are in the cards 2d array.*/

	if (!testDealDeck(14)){
		fprintf(stderr, "FAIL on test 1 (shuffled deck)\n");
		test_fail++;
	}
	else fprintf(stderr, "PASS ON test 1 (shuffled deck)\n");

	createDeck(cards, sequence, cdptr);
	dealDeck(cards,sequence,14, cdptr);

	if (!testDealDeck(14)){
		fprintf(stderr, "FAIL on test 2 (unshuffled deck)\n");
		test_fail++;
	}
	else fprintf(stderr, "PASS ON test 2 (unshuffled deck)\n");

	shuffleDeck(sequence, cdptr);
	dealDeck(cards, sequence, 20, cdptr);

	if (!testDealDeck(34)){
		fprintf(stderr, "FAIL on test 3 (unshuffled deck)\n");
		test_fail++;
	}
	else fprintf(stderr, "PASS ON test 3 (unshuffled deck)\n");

	if(test_fail == 0){
		fprintf(stderr, "All Tests pass!\n");
	}
	else fprintf(stderr, "Tests did not pass]\n");

}
/* Function name: testDealDeck()
 * prototype: testDealDeck(int num)
 * Description: tests if dealDeck works properly by seeing if it
 				properly sets the value of the dealt card elements
 				in the cards array to one.
*/
int testDealDeck(int num){
	int total=0;//keeps track of how many 1s in the array
	int i=0;
	for (i=0; i<4; i++){
		int k;
		for (k=0;k<13;k++){
			if (cards[i][k]==1){
				total++;

			}

		}
	}
	fprintf(stderr, "%d\n", total);
	if (total == num){
		return 1; //return true
	}
	else return 0; //return false
}