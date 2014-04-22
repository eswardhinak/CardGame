/*
 * Filename:main.c
 * Author: Eswar Dhinakaran
 * Description: Runs the C program that lets the user create a deck of cards
 				shuffle that deck, deal cards from that deck and resort and shuffle
 * How to run: To run this file, view the README.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Dealer.h"

int cards[4][13]; //array of the cards. rows = suits. cols = ranks
int sequence[52];//sequence of ordering.
int cardsDealt=0; //number of cards that has been dealt
int *cardsGiven = &cardsDealt; //pointer to the nuber of cards that has been dealt

int main(void){
	long option; //the option the user chooses
	createDeck(cards, sequence, cardsGiven); //creates a deck to begin

	fprintf(stdout, "52 card deck has been created\n\n");
	/*loops through menu*/
	while(1){
		fprintf(stdout, "\nPlease enter a command Enter EOF(^D) to exit:\n");	
		fprintf(stdout,"(s)huffle, (d)eal, (r)eorder\n");
		option = getchar();
		if(option == EOF)
			break;
		clearbuf();
		switch(option){
			int number; //the number of cards user wants dealt

			/*shuffle case*/
			case 's':
				if(shuffleDeck(sequence, cardsGiven)){
					fprintf(stdout, "Deck has been shuffled\n");
				}
				else{fprintf(stdout, "Cannot shuffle %d cards", 52-cardsDealt);

				}
				break;

			/*deal case*/
			case 'd':
				//not all cards can be dealt
				if(cardsDealt>=52){
					fprintf(stdout,"All cards have been dealt\n");
					break;
				}
				/*prompts user until valid number is intered. number they enter
				cannot be greater than the number of undealt cards*/
				do{
					fprintf(stdout, "Enter (integer) how many cards you want dealt(%d dealt so far): ", cardsDealt);
					scanf("%d", &number);
					clearbuf();
				}while(number>(52-cardsDealt)); 
				fprintf(stdout, "\n\n");
				dealDeck(cards, sequence, number, cardsGiven);
				fprintf(stdout, "\n\n");
				break;
			/*reorder and restore deck*/
			case 'r':
				createDeck(cards, sequence, cardsGiven);
				fprintf(stdout,"Deck has been created again\n");
				break;
		}
	}
}
/*clears stdin buffer*/
int clearbuf(void){
	while(getchar() != '\n');
}


