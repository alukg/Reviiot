
#include "Player.h"
#include "Game.h";
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

Card* Player::checkForCard(string cardRequested) {
    list <Card *> &l = this->getCards();
    for (list<Card *>::iterator it = l.begin(); it != l.end(); it++) {
        Card *tmp = *it;
        if(tmp->toString() == cardRequested){
            return tmp;
        }
    }
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
    Card* d = player->checkForCard(card);
    if(d== nullptr)
    {
        d = game.getGameDeck().fetchCard();

    }
}