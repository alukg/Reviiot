#include "Player.h"

#include <iostream>

using namespace std;

/* Default constructor */
PlayerType4::PlayerType4(int newPosition, string newName, Game &newGame) : Player(newPosition, newName, 4, newGame) {

}

PlayerType4::PlayerType4(PlayerType4 &other) : Player(other.getPosition(), other.getName(), 1, other.getGame()) {

}