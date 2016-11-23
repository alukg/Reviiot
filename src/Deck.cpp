
#include "../include/Deck.h"
#include <iostream>

using namespace std;


Deck::Deck() : Q() {

};

Deck::Deck(Deck &other): Q() {
    for (deque<Card *>::iterator it = other.Q.begin(); it != other.Q.end(); ++it) {
        if ((*it)->getType() == Num) {
            NumericCard *card = new NumericCard(static_cast<NumericCard&>(**it));
            Q.push_back(card);
        } else {
            FigureCard *card = new FigureCard(static_cast<FigureCard&>(**it));
            Q.push_back(card);
        }
    }
}

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


    if (isFigure){
        FigureCard *card = new FigureCard(figure,shape);
        Q.push_back(card);
    }
    else{
        NumericCard *card = new NumericCard(numValue,shape);
        Q.push_back(card);
    }


};

Card* Deck::fetchCard() {
    Card *c = Q.front();
    Q.pop_front();
    return c;
};

int Deck::getNumberOfCards() {
    return Q.size();
};

string Deck::toString() {
    //to be deleted
    string s = "";
    for (deque<Card *>::iterator it = Q.begin(); it != Q.end(); it++) {
        Card *tmp = *it;
        s= s + tmp->toString() + ' ';
    }
    return s;
}

Deck::~Deck() {
}
