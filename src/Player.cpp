
#include "../include/Player.h"

#include <iostream>

using namespace std;

class Player
{
public:
    /** Default constructor */
    Player(int newPosition, const string& newName) :
            position (newPosition), name (newName)
    {

    }

    /** Copy constructor */
    Player (const Player& other) :
            position (other.position), name (other.name)
    {

    }

    /** Move constructor - Not needed hear because the player isn't moved
    Player (Player&& other) :
            position (other.position), name (other.name)
    {
        other.name = nullptr;
    }
    */

    /** Destructor */
    ~Player()
    {
        delete position;
        delete name;
    }

    /** Copy assignment operator */
    Player& operator= (const Player& other)
    {
        Player tmp(other);
        *this = move(tmp);
        return *this;
    }

    /** Move assignment operator - Not needed hear because the player isn't moved
    Player& operator= (Player&& other)
    {
        delete position;
        delete name;
        position = other.position;
        name = other.name;
        other.name = nullptr;
        return *this;
    }
    */

private:
    /*
    friend ostream& operator<< (ostream& os, const Player& foo)
    {
        os << Player.data;
        return os;
    }
    */
};