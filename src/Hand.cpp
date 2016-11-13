
#include "../include/Hand.h"

void Hand::sortCards() {
    int j;
    Card *temp;

    for (int i = 0; i < cards.size(); i++) {
        j = i;

        while (j > 0 && comperator(cards.at(j), cards.at(j - 1)) < 1) {
            temp = cards.at(j);
            cards.at(j) = cards.at(j - 1);
            cards.at(j - 1) = temp;
            j--;
        }
    }
}

int Hand::comperator(Card &left, Card &right) {

}

int Hand::getNumberOfCards() {
    return cards.size();
}

string Hand::toString() {
    string ans = "";
    for (int i = 0; i < cards.size(); i++) {
        if (i == cards.size() - 1)
            ans = ans + cards.at(i)->toString();
        else
            ans = ans + cards.at(i)->toString() + " ";
    }
}

bool Hand::removeCard(Card &card) {
    bool found = false;
    for(int i=0;!found & i<cards.size();i++){
        if(cards.at(i)->toString() == card.toString()){
            found = true;
            //delete card from vector;
        }
    }
}

