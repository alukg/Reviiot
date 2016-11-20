#ifndef CARD_H_
#define CARD_H_

#include <iostream>

using namespace std;

enum Shape {
    Club,
    Diamond,
    Heart,
    Spade
};

enum Figure {
    Jack,
    Queen,
    King,
    Ace
};

enum Type {
    Num,
    Fig
};

class Card {
protected:
    Shape shape;
    Type type;
    char getShape();
public:
    Card(Shape shape1, Type type1);
    Type getType();
    virtual string toString() = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
    virtual ~Card();
};

class FigureCard : public Card {
private:
    Figure figure;
    char getFigure();
public:
    FigureCard(Figure figure1, Shape shape1);
    FigureCard(const FigureCard &other);
    virtual string toString() override;

};

class NumericCard : public Card {
private:
    int number;
public:
    NumericCard(int num, Shape shape);
    NumericCard(const NumericCard &other);
    virtual string toString() override;
};

#endif
