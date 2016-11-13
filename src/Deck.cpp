
#include "../include/Deck.h"

#include <iostream>

using namespace std;

void Deck::addCard(string cardName) {
    Shape shape;
    bool isFigure = true;
    Figure figure;
    int numValue;

    switch (cardName.at(1)){
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
            numValue = cardName.at(0) - '0';
            break;
    }

    Card *card;

    if (isFigure){
        card = new FigureCard(figure,shape);
    }
    else{
        card = new NumericCard(numValue,shape);
    }

    Q.push(card);
}