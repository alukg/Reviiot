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

protected:
    void askForCard(string card, Player* player);
    list<Card*> checkForCard(string cardNum);

public:
    Player(int newPosition, string &newName, Game &newgame);
    string getName();
    void playTurn();

};

class PlayerType1 : public Player {  //For strategy 1
public:
    PlayerType1(int newPosition, string newName, Game &newgame);
};

class PlayerType2 : public Player {  //For strategy 2
public:
    PlayerType2(int newPosition, string newName, Game &newgame);
};

class PlayerType3 : public Player {  //For strategy 3
public:
    PlayerType3(int newPosition, string newName, Game &newgame);
};

class PlayerType4 : public Player {  //For strategy 4
public:
    PlayerType4(int newPosition, string newName, Game &newgame);
};

#endif