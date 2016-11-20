

#include "../include/Card.h"
#include <iostream>
using namespace std;

Card::Card(Shape shape1, Type type1) {
    shape = shape1;
    type = type1;
};

char Card::getShape() {
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

Card::~Card() {
    
};

