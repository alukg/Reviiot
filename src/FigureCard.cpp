//
// Created by shahar on 11/11/16.
//

#include "../include/Card.h"
#include <iostream>
#include <sstream>
using namespace std;

//Constructor

FigureCard::FigureCard(Figure figure1, Shape shape1) : Card(shape1) {
    this->figure=figure1;
};

FigureCard::FigureCard(const FigureCard &other) : Card(other.shape, other.type), figure(other.figure) {

}

string FigureCard::toString() const{

    return std::string() + this->getFigure() + this->getShape();
};

char FigureCard::getFigure() {
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

string FigureCard::getCardValue() const {
    return string() + getFigure();
};

