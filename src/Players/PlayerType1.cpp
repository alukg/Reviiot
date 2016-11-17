#include "Player.h"

#include <iostream>

using namespace std;

/* Default constructor */
PlayerType1::PlayerType1(int newPosition, string newName, Game &newGame) : Player(newPosition, newName, 1, newGame) {

}