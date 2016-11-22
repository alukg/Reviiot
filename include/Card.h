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
public:
    char getShape() const;
    Card(Shape shape1, Type type1);
    Type getType();
    virtual string getCardValue() const =0;
    virtual string toString() const = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
    virtual ~Card();
};

class FigureCard : public Card {
private:
    Figure figure;
    char getFigure() const;
public:
    FigureCard(Figure figure1, Shape shape1);
    FigureCard(FigureCard &other);
    virtual string toString() const;
    virtual string getCardValue() const;
};

class NumericCard : public Card {
private:
    int number;
public:
    NumericCard(int num, Shape shape);
    NumericCard(NumericCard &other);
    virtual string getCardValue() const;
    virtual string toString() const;
};

#endif
