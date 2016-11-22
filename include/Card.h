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
    Card(Card &other);
    Type getType();
    virtual Figure getFigure() const;
    virtual string getCardValue() const =0;
    virtual string toString() const = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
    virtual ~Card();
};

class FigureCard : public Card {
private:
    Figure figure;
    char getFigureChar() const;
public:
    FigureCard(Figure figure1, Shape shape1);
    FigureCard(Card &other);
    Figure getFigure() const;
    virtual string toString() const;
    virtual string getCardValue() const;
};

class NumericCard : public Card {
private:
    int number;
public:
    NumericCard(int num, Shape shape);
    NumericCard(Card &other);
    virtual string getCardValue() const;
    virtual string toString() const;
};

#endif
