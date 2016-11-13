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

string FigureCard::toString() {
    string c = ((&this->shape).)[0];
    return c;
};