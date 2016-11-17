#ifndef PLAYER_H_
#define PLAYER_H_


#include <iostream>

#include "Hand.h"
class Game;

using namespace std;

class Player : public Hand {
private:
    const string name;
    const int position;
    Game &game;
    int type;

protected:
    void askForCard(string card, Player* player);
    Card* checkForCard(string card);

public:
    Player(int newPosition, string &newName, int type, Game &newGame);
    string getName();
    int getType();
    void playTurn();

};

class PlayerType1 : public Player {  //For strategy 1
public:
    PlayerType1(int newPosition, string newName, Game &newGame);
};

class PlayerType2 : public Player {  //For strategy 2
public:
    PlayerType2(int newPosition, string newName, Game &newGame);
};

class PlayerType3 : public Player {  //For strategy 3
public:
    PlayerType3(int newPosition, string newName, Game &newGame);
};

class PlayerType4 : public Player {  //For strategy 4
public:
    PlayerType4(int newPosition, string newName, Game &newGame);
};

#endif