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
    int type;
    void isFour();

protected:
    void askForCard(string card, Player* player);
    list<Card*> *checkForCard(string cardNum);
    Game &game;

public:
    Player(int newPosition, string newName, int type, Game &newGame);
    string getName() const;
    int getPosition() const ;
    int getType() const;
    Game& getGame() const;
    virtual void playTurn() = 0; //remember to check this again
    string toString();
    virtual ~Player();
};

class PlayerType1 : public Player {  //For strategy 1
public:
    PlayerType1(int newPosition, string newName, Game &newGame);
    PlayerType1(Player &other);
    void playTurn();
    virtual ~PlayerType1();
};

class PlayerType2 : public Player {  //For strategy 2
public:
    PlayerType2(int newPosition, string newName, Game &newGame);
    PlayerType2(Player &other);
    void playTurn();
    virtual ~PlayerType2();
};

class PlayerType3 : public Player {  //For strategy 3
private:
    int nextPlayer;
public:
    PlayerType3(int newPosition, string newName, Game &newGame);
    PlayerType3(Player &other);
    void playTurn();
    virtual ~PlayerType3();

};

class PlayerType4 : public Player {  //For strategy 4
private:
    int nextPlayer;
public:
    PlayerType4(int newPosition, string newName, Game &newGame);
    PlayerType4(Player &other);
    void playTurn();
    virtual ~PlayerType4();
};

#endif