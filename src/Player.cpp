
#include "../include/Player.h"
#include "../include/Game.h"
#include <map>

/* Default constructor */
Player::Player(int newPosition, string newName, int newType, Game &newGame) :Hand(),
        position(newPosition), name(newName), type(newType), game(newGame) {}

string Player::getName(){
    return name;
}

int Player::getType() const {
    return type;
}

int Player::getPosition() const {
    return position;
}

Game &Player::getGame() const {
    return game;
}

list<Card *> *Player::checkForCard(string cardRequested) {
    int countCardsToTake = 0;
    std::list<Card *> &l = getCards();
    std::list<Card *> *returnedCards = new list<Card *>();
    for (list<Card *>::iterator it = l.begin(); it != l.end();) {
        Card *tmp = *it;
        if (tmp->getCardValue() == cardRequested) {
            returnedCards->push_back(tmp);
            it++;
            removeCard(*tmp);
            countCardsToTake++;
        }
        else{
            it++;
        }
    }

    if(getNumberOfCards()!=0) {
        for (int i = 0; i < countCardsToTake; i++) {
            if (game.getGameDeck().getNumberOfCards() > 0) {
                addCard(*(game.getGameDeck().fetchCard()));
            }
        }
    }
    isFour();
    if (returnedCards->size() != 0)
        return returnedCards;
    else
        delete returnedCards;
        return nullptr;
}


void Player::askForCard(string card, Player *player) {
    std::list<Card *> *cardsFromPlayer = player->checkForCard(card);
    if (cardsFromPlayer == nullptr) {
        if(getNumberOfCards()!=0) {
            if (game.getGameDeck().getNumberOfCards() > 0) {
                addCard(*(game.getGameDeck().fetchCard()));
            }
        }
    } else {
        for (list<Card *>::iterator it = cardsFromPlayer->begin(); it != cardsFromPlayer->end(); it++) {
            Card *tmp = *it;
            this->addCard(*tmp);
            *it = nullptr;
        }
    }

    delete cardsFromPlayer;
    cardsFromPlayer =nullptr;
    isFour();
}

//need to be Checked
void Player::isFour() {

    typedef map<string, int> myMap;
    myMap counts;
    for (list<Card *>::const_iterator it = getCards().begin(); it != getCards().end(); it++) {
        counts[(*it)->getCardValue()]++;
    }

    for (list<Card *>::iterator it = getCards().begin(); it != getCards().end();) {
        if (counts[(*it)->getCardValue()] == 4) {
            delete(*it);
            it = getCards().erase(it);
        }
        else {
            it++;
        }
    }
}
string Player::toString(){
    string ans = getName() + ": ";
    for (list<Card *>::iterator it = getCards().begin(); it != getCards().end(); it++){
        ans = ans + (*it)->toString() + " ";
    }
    return ans;
}

Player::~Player() {};