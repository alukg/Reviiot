
#include "Player.h"

#include <iostream>

/* Default constructor */
Player::Player(int newPosition, string &newName, Game &newgame) :
        position(newPosition), name(newName), game(newgame) {}

string Player::getName() {
    return name;
}