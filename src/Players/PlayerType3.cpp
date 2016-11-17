#include "Player.h"

#include <iostream>

using namespace std;

/* Default constructor */
PlayerType3::PlayerType3(int newPosition, string newName, Game &newGame ) : Player(newPosition, newName, 3, newGame) {

}