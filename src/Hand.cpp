
#include "../include/Hand.h"
#include <map>


int Hand::figureToInt(char fig) {
    //need to change with N (highest numeric card value)
    switch (fig) {
        case 'J':
            return 101;
        case 'Q':
            return 102;
        case 'K':
            return 103;
        case 'A':
            return 104;
        default:
            return 0;
    }
}

void Hand::addCard(Card *card) {
    bool found = false;
    for (list<Card *>::iterator it = this->cards.begin(); it != this->cards.end() && !found; it++) {
        Card *tmp = *it;
        if (compare(*card,*tmp )) {
            cards.insert(it,card);
        }
    }
}


bool Hand::compare( Card &left1, Card &right1) {

    int left =figureToInt(left1.toString()[0]);
    if (left ==0) {
        left = std::stoi(left1.toString().substr(0,(int)(left1.toString().length() -1)));
    }

    int right =figureToInt(right1.toString()[0]);
    if (right ==0) {
        right = std::stoi(right1.toString().substr(0,(int)(right1.toString().length() -1)));
    }

    if (left<right)
        return true;
    else
        return false;


}

int Hand::getNumberOfCards() {
    return cards.size();
}

string Hand::toString() {
    string ans = "";
    for (list<Card *>::iterator it = cards.begin(); it != cards.end(); it++){
        ans = ans + (*it)->toString() + " ";
    }
    return ans;
}

bool Hand::removeCard(Card &card) {
    bool found = false;
    for (list<Card *>::iterator it = cards.begin(); it != cards.end(); it++){
        if(*it == &card){
            found = true;
            removeCard(card);
        }
    }
    return found;
}

list<Card *>& Hand::getCards() {
    return this->cards;
}