#include "../../include/Player.h"
#include "../../include/Game.h"

#include <iostream>

using namespace std;

/* Default constructor */
PlayerType4::PlayerType4(int newPosition, string newName, Game &newGame) : Player(newPosition, newName, 4, newGame),
                                                                           nextPlayer(0) {

}

PlayerType4::PlayerType4(Player &other) : Player(other.getPosition(), other.getName(), 1, other.getGame()), nextPlayer(0) {
    for (list<Card *>::iterator it = other.getCards().begin(); it != other.getCards().end(); it++) {
        switch ((*it)->getType()) {
            case Num:
                this->addCard(*(new NumericCard(**it)));
                break;
            case Fig:
                this->addCard(*(new FigureCard(**it)));
                break;
        }
    }
}

void PlayerType4::playTurn() {
    string chosenCard = getCards().front()->toString().substr(0, getCards().front()->toString().length() - 1);
    if (game.getPlayers()[nextPlayer % game.getPlayers().size()] == this) {
        nextPlayer++;
    }
    Player *chosenPlayer = game.getPlayers()[nextPlayer % game.getPlayers().size()];
    nextPlayer++;
    askForCard(chosenCard, chosenPlayer);
    cout << getName() + " asked " + chosenPlayer->getName() + " for the value " + chosenCard << endl;
    cout << endl;
}

PlayerType4::~PlayerType4() {};