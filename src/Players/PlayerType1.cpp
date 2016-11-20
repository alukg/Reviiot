#include "Player.h"

#include <iostream>

using namespace std;

/* Default constructor */
PlayerType1::PlayerType1(int newPosition, string newName, Game &newGame) : Player(newPosition, newName, 1, newGame) {

}

PlayerType1::PlayerType1(PlayerType1 &other) : Player(other.getPosition(), other.getName(), 1, other.getGame()) {

}