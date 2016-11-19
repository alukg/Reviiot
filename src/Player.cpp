
#include "Player.h"
#include "Game.h"
#include <iostream>

/* Default constructor */
Player::Player(int newPosition, string &newName, int newType, Game &newGame) :
        position(newPosition), name(newName), type(newType), game(newGame) {}

string Player::getName() {
    return name;
}



int Player::getType() {
    return type;
}

list <Card*> Player::checkForCard(string cardRequested) {
    list <Card *> &l = this->getCards();
    list <Card *> returnedCards;
    for (list<Card *>::iterator it = l.begin(); it != l.end(); it++) {
        Card *tmp = *it;
        if(tmp->toString().substr(0,(int)(tmp->toString().length() -1)) == cardRequested){
            returnedCards.push_back(tmp);
        }
    }
    if(returnedCards.size() != 0)
        return returnedCards;
    else
        return nullptr;
}
/*
void Player::askForCard(string card, Player* playerAsked) {
    vector<Player *> &players = game.getPlayers();
    for (vector<Player *>::iterator it = players.begin(); it < players.end(); it++) {
        Player *tmp = *it;
        if(tmp == playerAsked){
            as
        }
    }
}
 */

void Player::askForCard(string card, Player *player) {
    list<Card*> cardsFromPlayer = player->checkForCard(card);
    if(cardsFromPlayer== nullptr)
    {
        Card *d =game.getGameDeck().fetchCard();
        this->addCard(d);
    }
    else {
        for (list<Card *>::iterator it = cardsFromPlayer.begin(); it != cardsFromPlayer.end(); it++) {
            Card *tmp = *it;
            this->addCard(tmp);
        }
    }
}



