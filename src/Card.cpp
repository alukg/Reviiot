
#include "../include/Card.h"
#include <iostream>

using namespace std;

Card::Card(Shape shape1, Type type1) :shape(shape1), type(type1) {
};

Card::Card(Card &other): shape(other.shape), type(other.type){

};

char Card::getShape() const {
    switch (this->shape) {
        case Club:
            return 'C';
        case Diamond:
            return 'D';
        case Heart:
            return 'H';
        case Spade:
            return 'S';
    }
    return 0;
};

Type Card::getType(){
    return type;
}

Figure Card::getFigure() const{
    return Ace;
};
Card::~Card() {};