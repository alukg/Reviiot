//
// Created by shahar on 11/11/16.
//

#include "../include/Card.h"
#include <iostream>
#include <sstream>
using namespace std;
//Constructor

NumericCard::NumericCard(int num, Shape shape) : Card(shape), number(num){

};

string NumericCard::toString() {
  std::stringstream ss;
    ss << this->number << this->shape;
  return ss.str();
};
