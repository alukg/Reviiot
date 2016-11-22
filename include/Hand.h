#ifndef HAND_H_
#define HAND_H_

#include <iostream>
#include <vector>
#include <list>

#include "Card.h"

using namespace std;

class Hand {
private:
	bool compare(Card &left, Card &right);
	list<Card *> cards;  //The list of the cards
    int figureToInt(char fig);

public:
	void addCard(Card *card);
	bool removeCard(Card &card);
	list<Card *>& getCards();
	int getNumberOfCards() const; // Get the number of cards in hand
	string toString(); // Return a list of the cards, separated by space, in one line, in a sorted order, ex: "2S 5D 10H"

};

#endif
