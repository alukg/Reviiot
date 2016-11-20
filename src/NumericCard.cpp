//
// Created by shahar on 11/11/16.
//

#include "../include/Card.h"
#include <iostream>
#include <string>

using namespace std;

//Constructor
NumericCard::NumericCard(int num, Shape shape) : Card(shape, Num), number(num) {

};

NumericCard::NumericCard(const NumericCard &other) : Card(other.shape, other.type), number(other.number) {

}

string NumericCard::toString() {
    std::string s = to_string(this->number);
    return s + this->getShape();
};
