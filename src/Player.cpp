
#include "Player.h"
#include "Game.h"
#include <iostream>
#include <map>

/* Default constructor */
Player::Player(int newPosition, string newName, int newType, Game &newGame) :
        position(newPosition), name(newName), type(newType), game(newGame) {}

string Player::getName() {
    return name;
}



int Player::getType() {
    return type;
}

int Player::getPosition() {
    return position;
}

Game& Player::getGame() {
    return game;
}

list <Card*> *Player::checkForCard(string cardRequested) {
    int countCardstoTake=0;
    list <Card *> &l = this->getCards();
    list <Card *> *returnedCards =new list<Card *>();
    for (list<Card *>::iterator it = l.begin(); it != l.end(); it++) {
        Card *tmp = *it;
        if(tmp->getCardValue() == cardRequested){
            returnedCards->push_back(tmp);
            countCardstoTake++;
        }
        for (int i=0; i<countCardstoTake; i++) {
            addCard(game.getGameDeck().fetchCard());
        }
        isFour();
    }
    if(returnedCards->size() != 0)
        return returnedCards;
    else
        return nullptr;
}


void Player::askForCard(string card, Player *player) {
    list<Card*> *cardsFromPlayer = player->checkForCard(card);
    if(cardsFromPlayer== nullptr)
    {
        addCard(game.getGameDeck().fetchCard());
    }
    else {
        for (list<Card *>::iterator it = cardsFromPlayer->begin(); it != cardsFromPlayer->end(); it++) {
            Card *tmp = *it;
            this->addCard(tmp);
        }
    }
    isFour();
}

//need to be Checked
void Player::isFour() {

    typedef map <string,int> mymap;
    mymap counts;
    for (list<Card *>:: const_iterator it = getCards().begin(); it != getCards().end(); it++) {
        counts[(*it)->getCardValue()]++;
    }

    for (list<Card *>:: iterator it = getCards().begin(); it != getCards().end();) {
        if(counts[(*it)->getCardValue()] == 4)
            it=getCards().erase(it);
            //delete Card from game
        else{
            it++;
        }
    }
}


