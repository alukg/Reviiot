#include <iostream>

#include "../include/Game.h"

using namespace std;

int main(int argc, char **argv) {

    //string configurationFile(argv[1]);

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
//	game.init();
// 	Game initializedGame = game;
// 	game.play();
//
//	cout << std::endl;
// 	game.printWinner();
//	game.printNumberOfTurns();
//	cout << "----------" << endl;
//	cout<<"Initial State:"<<endl;
//  	initializedGame.printState();
//	cout<<"----------"<<endl;
//	cout<<"Final State:"<<endl;
//	game.printState();

    return 0;
}

