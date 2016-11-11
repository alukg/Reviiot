
#include "../include/Player.h"

#include <iostream>

using namespace std;

/* Default constructor */
Player::Player(int newPosition, string &newName) :
        position(newPosition), name(newName) {}