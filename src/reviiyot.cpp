#include <iostream>

#include "../include/Game.h"

using namespace std;

int main(int argc, char **argv) {
//
//	char* configurationFile = argv[1];
//
//	Game game = Game(configurationFile);
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

	Card *c1 = new NumericCard(5,Heart);
	Card *c2 = new FigureCard(Jack,Club);

	std::cout << c1->toString() <<endl;
	std::cout << c2->toString() << endl;
	return 0;
}

