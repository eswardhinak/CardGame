/*
 * Filename: unitTest_shuffleDeck.c
 * Author: Eswar Dhinakaran
 * Description: Tests the C Function shuffleDeck located in Dealer.c
 				and in Dealer.h (header)
 * How to run: To run this file, view the README.

*/

#include <stdio.h>
#include <stdlib.h>
#include "Dealer.h"
int test_array[52]; //array of the cards
int dealtCards=0; //number of dealt cards
int *dcptr = &dealtCards; //pointer to the number of dealt cards
int main(void){
	int i=0;
	/*sets up the sorted array*/
	for (i=0; i<52; i++){
		test_array[i]=i;
	}
	if (!test_shuffleDeck()){
		fprintf(stderr, "FAIL: TEST 1 FAILED on sorted sequence\n");
	}
	else{
		fprintf(stderr, "Test 1 passed on sorted sequence\n");

		if(!test_shuffleDeck()){
			fprintf(stderr, "FAIL: TEST 2 failed on shuffled sequence");
		}
		else{
			fprintf(stderr, "Test 2 passed on shuffled sequence\n");
		}
	}
			

}
/* function name: test_shuffleDeck()
   function prototype: test_shuffleDeck()
   Description: checks if shuffleDeck works properly by making sure
   				there are no repeats in the sequence of cards. This 
   				will ensure that shuffleDeck is correctly swapping 
   				cards.
   	Returns: FALSE on duplicates found (BAD)
   			TRUE if duplicates are not found (GOOD)
 */
int test_shuffleDeck(){
	shuffleDeck(test_array, dcptr);
	/*check if cards are repeated*/
	int i = 0;
	int duplicate = 0;
	for(i=0; i<51; i++){
		int j;
		for (j=i+1; j<52; j++){
			if (test_array[i] == test_array[j]){
				duplicate=1;
				fprintf(stderr, "Duplicates found at indexes %d and %d", i, j);

			}
		}
	}
	if (duplicate == 1){
		return 0;
	}
	else return 1;
}
