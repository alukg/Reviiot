

#include "../include/Card.h"
#include <iostream>
using namespace std;

Card::Card(Shape shape1) {
    shape = shape1;
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

Card::~Card() {
    
};

