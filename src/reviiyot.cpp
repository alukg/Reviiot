#include <iostream>

#include "../include/Game.h"

using namespace std;

int main(int argc, char **argv) {
//
//	char* configurationFile = argv[1];
//
//	Game game = Game(configurationFile);

    //string configurationFile(argv[1]);
/*
    char *configurationFile = (char *) "#Verbal ON\n"
                "1\n"
                "\n"
                "#Highest numeric value\n"
                "3\n"
                "\n"
                "#Deck\n"
                "KC QH 3D AH JH 2C 3S KS AS JS 3C KH AD QC JD QS 3H KD AC JC 2D 2H 2S QD \n"
                "\n"
                "#Players\n"
                "Alice 1\n"
                "Bob 2\n"
                "Charlie 3";

    Game game = Game(configurationFile);
	game.init();
*/
    Hand *hand = new Hand();
    Deck *d = new Deck();
    d->addCard("2S");
    d->addCard("KH");
    d->addCard("AD");

    cout << hand->getNumberOfCards() << endl;
    string s = hand->toString();
    cout << s<< endl;

    return 0;
}

