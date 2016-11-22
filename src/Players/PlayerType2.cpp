#include "Player.h"
#include "../../include/Game.h"

#include <iostream>

using namespace std;

/* Default constructor */
PlayerType2::PlayerType2(int newPosition, string newName, Game &newGame) : Player(newPosition, newName, 2, newGame) {

}

PlayerType2::PlayerType2(const Player &other) : Player(other.getPosition(), other.getName(), 1, other.getGame()) {

}

void PlayerType2::playTurn() {
    int minCards = 5;
    string chosenCard = "";
    int counter = 0;
    string presentCard = "";
    string cardValue = "";

    for (list<Card *>::iterator it = getCards().begin(); it != getCards().end(); it++) {
        Card *tmp = *it;
        cardValue = tmp->toString().substr(0, tmp->toString().length()-1);
        if(presentCard == "")
            presentCard = cardValue;
        if(cardValue != presentCard){
            if(counter < minCards){
                chosenCard = presentCard;
                minCards = counter;
            }
            presentCard = cardValue;
            counter = 0;
        }
        counter++;
    }

    if(presentCard != chosenCard)
        if(counter < minCards)
            chosenCard = presentCard;

    Player* chosenPlayer = game.getPlayerWithMostCards(*this);
    askForCard(chosenCard,chosenPlayer);
    cout << getName() + " asked " + chosenPlayer->getName() + " for the value " + chosenCard<< endl;
}