#include "Player.h"
#include "../../include/Game.h"

#include <iostream>

using namespace std;

/* Default constructor */
PlayerType1::PlayerType1(int newPosition, string newName, Game &newGame) : Player(newPosition, newName, 1, newGame) {

}

PlayerType1::PlayerType1(Player &other) : Player(other.getPosition(), other.getName(), 1, other.getGame()) {
    for (list<Card *>::iterator it = other.getCards().begin(); it != other.getCards().end(); it++) {
        switch ((*it)->getType()) {
            case Num:
                this->addCard(new NumericCard(**it));
                break;
            case Fig:
                this->addCard(new FigureCard(**it));
                break;
        }
    }
}

void PlayerType1::playTurn() {
    int maxCards = 0;
    string chosenCard = "";
    int counter = 0;
    string presentCard = "";
    string cardValue = "";

    for (list<Card *>::iterator it = getCards().begin(); it != getCards().end(); it++) {
        Card *tmp = *it;
        cardValue = tmp->toString().substr(0, tmp->toString().length()-1);
        if(cardValue != presentCard){
            if(counter >= maxCards){
                chosenCard = presentCard;
                maxCards = counter;
            }
            presentCard = cardValue;
            counter = 0;
        }
        counter++;
    }

    if(presentCard != chosenCard)
        if(counter >= maxCards)
            chosenCard = presentCard;

    Player* chosenPlayer = game.getPlayerWithMostCards(*this);
    askForCard(chosenCard,chosenPlayer);
    cout << getName() + " asked " + chosenPlayer->getName() + " for the value " + chosenCard<< endl;
    cout << endl;
}