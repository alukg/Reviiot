
#include "../include/Hand.h"

bool Hand::addCard(Card *card) {
    bool ans = false;
}

bool Hand::compare(const Card &left, const Card &right) {

}

void Hand::sortCards() {
    cards.sort(compare);
}

int Hand::getNumberOfCards() {
    return cards.size();
}

//string Hand::toString() {
//    string ans = "";
//    for (int i = 0; i < cards.size(); i++) {
//        if (i == cards.size() - 1)
//            ans = ans + cards.at(i)->toString();
//        else
//            ans = ans + cards.at(i)->toString() + " ";
//    }
//}
//
//bool Hand::removeCard(Card &card) {
//    bool found = false;
//    for (int i = 0; !found & i < cards.size(); i++) {
//        if (cards.at(i)->toString() == card.toString()) {
//            found = true;
//            //delete card from vector;
//        }
//    }
//}

