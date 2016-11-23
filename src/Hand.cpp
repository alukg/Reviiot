
#include "../include/Hand.h"
#include <map>
#include "../include/Game.h"

Hand::Hand() : cards() {};

int Hand::figureToInt(char fig) {
    //need to change with N (highest numeric card value)
    switch (fig) {
        case 'J':
            return Game::getHighestNumValue() + 1;
        case 'Q':
            return Game::getHighestNumValue() + 2;
        case 'K':
            return Game::getHighestNumValue() + 3;
        case 'A':
            return Game::getHighestNumValue() + 4;
        default:
            return 0;
    }
}

void Hand::addCard(Card &card) {
    bool found = false;
    if(getNumberOfCards()==0)
        cards.push_front(&card);
    else {
        for (list<Card *>::iterator it = this->cards.begin(); it != this->cards.end() && !found; it++) {
            Card *tmp = *it;
            if (compare(card, *tmp)) {
                cards.insert(it, &card);
                found=true;
            }
        }
        if(!found){
            cards.push_back(&card);
        }

    }
}


bool Hand::compare( Card &left1, Card &right1) {

    int left =figureToInt(left1.toString()[0]);
    if (left ==0) {
        left = std::stoi(left1.getCardValue());
    }

    int right =figureToInt(right1.toString()[0]);
    if (right ==0) {
        right = std::stoi(right1.getCardValue());
    }

    if (left<right)
        return true;
    else
        if(left==right){
            if(left1.getShape() < right1.getShape()){
                return true;
            } else
                return false;
        }
        else
            return false;
}

int Hand::getNumberOfCards() const {
    return cards.size();
}

string Hand::toString() {
    string ans = "";
    for (list<Card *>::iterator it = cards.begin(); it != cards.end(); it++){
        ans = ans + (*it)->toString() + " ";
    }
    return ans;
}

//need to be checked
bool Hand::removeCard(Card &card) {
//    bool found = false;
//    for (list<Card *>::iterator it = cards.begin(); it != cards.end() && !found; it++){
//        if(*it == &card){
//            found = true;
//            cards.erase(it);
//        }
//    }
    cards.remove(&card);
    return true;
}

list<Card *>& Hand::getCards() {
    return this->cards;
}

Hand::~Hand() {
    if(cards.size()>0) {
        for (list<Card *>::iterator it = cards.begin(); it != cards.end(); it++) {
            delete *it;
        }
    }
};