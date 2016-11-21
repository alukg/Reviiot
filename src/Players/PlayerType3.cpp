#include "Player.h"

#include <iostream>

using namespace std;

/* Default constructor */
PlayerType3::PlayerType3(int newPosition, string newName, Game &newGame) : Player(newPosition, newName, 3, newGame) {

}

PlayerType3::PlayerType3(PlayerType3 &other) : Player(other.getPosition(), other.getName(), 1, other.getGame()) {

}

void PlayerType3::playTurn() {
    string chosenCard = getCards().back()->toString().substr(0, getCards().back()->toString().length() - 1);

    //Player *chosenPlayer = game.getPlayerWithMostCards(*this);
//    askForCard(chosenCard, chosenPlayer);
}