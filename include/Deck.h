#ifndef DECK_H_
#define DECK_H_

#include <iostream>
#include <deque>

#include "Card.h"

using namespace std;

class Deck {
private:
	deque<Card *> Q;

public:
    Deck();
	Deck(Deck &other);
	void addCard(string cardName);
	Card* fetchCard();   //Returns the top card of the deck and remove it from the deck
	int getNumberOfCards(); // Get the number of cards in the deck
	string toString(); // Return the cards in top-to-bottom order in a single line, cards are separated by a space ex: "12S QD AS 3H"
	virtual ~Deck();
};

#endif
