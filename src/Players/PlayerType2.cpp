#include "Player.h"

#include <iostream>

using namespace std;

/* Default constructor */
PlayerType2::PlayerType2(int newPosition, string newName, Game &newGame) : Player(newPosition, newName, 2, newGame) {

}

PlayerType2::PlayerType2(PlayerType2 &other) : Player(other.getPosition(), other.getName(), 1, other.getGame()) {

}