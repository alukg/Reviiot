#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <vector>

#include "Deck.h"
#include "Player.h"

using namespace std;

class Game {
private:
	vector<Player *> players;  //The list of the players
	Deck deck;                 //The deck of the game
	bool verbalOn;

	void insertCardsToDeck(Deck &deck, string line);
	void addPlayer(string playerName, int playerStrategy, int playerCounter, Game &game);
	void giveCards(Player player);
public:
	Game(char* configurationFile);
	void init();
	void play();
	void printState();        //Print the state of the game as described in the assignment.
	void printWinner();       //Print the winner of the game as describe in the assignment.
    void printNumberOfTurns(); //Print the number of played turns at any given time.
};

#endif
