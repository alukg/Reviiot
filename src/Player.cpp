
#include "Player.h"

#include <iostream>

/* Default constructor */
Player::Player(int newPosition, string &newName, int newType, Game &newGame) :
        position(newPosition), name(newName), type(newType), game(newGame) {}

string Player::getName() {
    return name;
}

int Player::getType() {
    return type;
}