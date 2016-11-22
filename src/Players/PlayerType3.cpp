#include "Player.h"
#include "../../include/Game.h"

#include <iostream>

using namespace std;

/* Default constructor */
PlayerType3::PlayerType3(int newPosition, string newName, Game &newGame) : Player(newPosition, newName, 3, newGame), nextPlayer(0) {

}

PlayerType3::PlayerType3(const Player &other) : Player(other.getPosition(), other.getName(), 1, other.getGame()), nextPlayer(0) {

}

void PlayerType3::playTurn() {
    string chosenCard = getCards().back()->toString().substr(0, getCards().back()->toString().length() - 1);
    if(game.getPlayers()[nextPlayer % game.getPlayers().size()] == this){
        nextPlayer++;
    }
    Player* chosenPlayer = game.getPlayers()[nextPlayer % game.getPlayers().size()];
    nextPlayer++;
    askForCard(chosenCard, chosenPlayer);
    cout << getName() + " asked " + chosenPlayer->getName() + " for the value " + chosenCard<< endl;
    cout << endl;
}