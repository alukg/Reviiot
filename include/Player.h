#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>

#include "Hand.h"

using namespace std;

class Player : public Hand {
private:
    const string name;
    const int position;
public:
    Player(int newPosition, string &newName);

    string getName();
};

class PlayerType1 : public Player {  //For strategy 1
    PlayerType1(int newPosition, string &newName);
};

class PlayerType2 : public Player {  //For strategy 2
    PlayerType2(int newPosition, string &newName);
};

class PlayerType3 : public Player {  //For strategy 3
    PlayerType3(int newPosition, string &newName);
};

class PlayerType4 : public Player {  //For strategy 4
    PlayerType4(int newPosition, string &newName);
};

#endif
