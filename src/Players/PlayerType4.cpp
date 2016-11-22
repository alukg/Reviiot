#include "Player.h"
#include "../../include/Game.h"

#include <iostream>

using namespace std;

/* Default constructor */
PlayerType4::PlayerType4(int newPosition, string newName, Game &newGame) : Player(newPosition, newName, 4, newGame) {

}

PlayerType4::PlayerType4(const Player &other) : Player(other.getPosition(), other.getName(), 1, other.getGame()) {

}

void PlayerType4::playTurn() {
    string chosenCard = getCards().front()->toString().substr(0, getCards().front()->toString().length()-1);

//    askForCard(chosenCard,chosenPlayer);
}