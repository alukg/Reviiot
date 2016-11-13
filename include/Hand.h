#ifndef HAND_H_
#define HAND_H_

#include <iostream>
#include <vector>

#include "Card.h"

using namespace std;

class Hand {
private:
	void sortCards();
	int Hand::compare(Card &left, Card &right);
	vector<Card *> cards;  //The list of the players

public:
	bool addCard(Card *card);
	bool removeCard(Card &card);
	int getNumberOfCards(); // Get the number of cards in hand
	string toString(); // Return a list of the cards, separated by space, in one line, in a sorted order, ex: "2S 5D 10H"
};

#endif
