//
// Created by shahar on 11/11/16.
//

#include "../include/Card.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
NumericCard::NumericCard(int num, Shape shape) : Card(shape, Num), number(num){

};

NumericCard::NumericCard(Card &other) : Card(other) {
    number = stoi(other.getCardValue());
}

string NumericCard::toString() const {
    std::string s = to_string(this->number);
  return s + this->getShape();
};

string NumericCard::getCardValue() const {
    return to_string(this->number);

}