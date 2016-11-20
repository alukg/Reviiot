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

class Card {
protected:
    Shape shape;
    char getShape() const;
public:
    Card(Shape shape1);
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
    virtual string toString() const override;
    virtual string getCardValue() const override;
};

class NumericCard : public Card {
private:
    int number;
public:
    NumericCard(int num, Shape shape);
    virtual string getCardValue() const override;
    virtual string toString() const override;
};

#endif
