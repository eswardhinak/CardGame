default:
	gcc -o CardGame main.c Dealer.c Dealer.h


unittest_createDeck:
	gcc -o unitTest_createDeck unitTest_createDeck.c Dealer.c Dealer.h


unittest_shuffleDeck:
	gcc -o unitTest_shuffleDeck unitTest_shuffleDeck.c Dealer.c Dealer.h

unittest_dealDeck:
	gcc -o unitTest_dealDeck unitTest_dealDeck.c Dealer.c Dealer.h