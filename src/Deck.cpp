
#include "../include/Deck.h"
#include <iostream>

using namespace std;

void Deck::addCard(string cardName) {
    Shape shape;
    bool isFigure = true;
    Figure figure;
    int numValue;

    switch (cardName.at(cardName.length()-1)){
        case 'C':
            shape = Club;
            break;
        case 'D':
            shape = Diamond;
            break;
        case 'H':
            shape = Heart;
            break;
        case 'S':
            shape = Spade;
            break;
    }
    switch (cardName.at(0)){
        case 'J':
            figure = Jack;
            break;
        case 'Q':
            figure = Queen;
            break;
        case 'K':
            figure = King;
            break;
        case 'A':
            figure = Ace;
            break;
        default:
            isFigure = false;
            numValue = std::stoi(cardName.substr(0,(int)(cardName.length() -1)));
            break;
    }

    Card *card;

    if (isFigure){
        card = new FigureCard(figure,shape);
    }
    else{
        card = new NumericCard(numValue,shape);
    }

    Q.push_back(card);
};

Card* Deck::fetchCard() {
    Card *c = this->Q.front();
    this->Q.pop_front();
    return c;
};

int Deck::getNumberOfCards() {
    return this->Q.size();
};

string Deck::toString() {
    //to be deleted
    string s="";
    for (deque<Card *>::iterator it=Q.begin(); it != Q.end(); ++it){
        Card *tmp = *it;
        s= s + tmp->toString() + ' ';
    }
    return s;
}
