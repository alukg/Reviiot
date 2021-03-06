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
    static int highestNumValue;
    int numberOfTurns=0;
	bool verbalOn;
    Deck deck;                 //The deck of the game
	void insertCardsToDeck(Deck &deck, string line);
	void addPlayer(string playerName, int playerStrategy, int playerCounter);
	void giveCards(Player &player);
	bool isFinished() const;
	int getNumberOfPlayers() const;

public:
    static int getHighestNumValue();
	Game( char* configurationFile );
	bool getVerbalOn() const;
	Game( Game &other );
	Game( Game&& other );
	void init();
	void play();
	void printState();        //Print the state of the game as described in the assignment.
	void printWinner();       //Print the winner of the game as describe in the assignment.
    void printNumberOfTurns(); //Print the number of played turns at any given time.
    vector<Player *>& getPlayers();
    Deck& getGameDeck();
    Player* getPlayerWithMostCards(Player &me);
	virtual ~Game();
};

#endif
