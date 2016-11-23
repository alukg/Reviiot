//
// Created by shahar on 11/11/16.
//

#include "../include/Card.h"
#include <iostream>
#include <sstream>
using namespace std;

//Constructor

FigureCard::FigureCard(Figure figure1, Shape shape1) : Card(shape1, Fig) {
    this->figure=figure1;
};

FigureCard::FigureCard(Card &other) : Card(other) {
    figure = other.getFigure();
}

string FigureCard::toString() const{

    return std::string() + this->getFigureChar() + this->getShape();
};

char FigureCard::getFigureChar() const{
    switch (this->figure) {
        case Jack:
            return 'J';
        case Queen:
            return 'Q';
        case King:
            return 'K';
        case Ace:
            return 'A';
    }
    return 0;
};

Figure FigureCard::getFigure() const{
    return figure;
};

string FigureCard::getCardValue() const {
    return string() + getFigureChar();
};

FigureCard::~FigureCard() {}
