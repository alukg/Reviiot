
#include "Player.h"

#include <iostream>

/* Default constructor */
Player::Player(int newPosition, string &newName) :
        position(newPosition), name(newName) {}

string Player::getName() {
    return name;
}