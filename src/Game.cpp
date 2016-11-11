#include <Game.h>
#include <string>
#include <iostream>
#include <sstream>

Game::Game(char *configurationFile) {
    istringstream f(configurationFile);
    string line;

    int highestNumValue;
    string deckCards;

    int counter = 1;
    while (getline(f, line)) {
        if (!line.empty()) {
            if (line.at(0) == '#') {
                if (counter == 1) {
                    getline(f, line);
                    verbalOn = stoi(line);
                } else if (counter == 2) {
                    getline(f, line);
                    highestNumValue = stoi(line);
                } else if (counter == 3) {
                    getline(f, line);
                    insertCardsToDeck(deck, highestNumValue, line);
                } else if (counter == 4) {
                    getline(f, line);
                    while (line.at(0) != ' ') {
                        string delimiter = " ";
                        string playerName = line.substr(0, line.find(delimiter));
                        int playerStrategy = stoi(line.substr(line.find(delimiter) + 1, 1));
                        //cout >> playerName >> endl;
                        //cout >> playerStrategy >> endl;
                        getline(f, line);
                    }
                }
                counter++;
            }
        }
    }
}

void Game::insertCardsToDeck(Deck &deck, int &highestNumCard, string line) {
    int length = line.length();
    int iterator = 0;
    while (abs(length - iterator) > 1) {
        if (line.at(iterator) != ' ') {
            deck.addCard(line.substr(iterator, 2));
            iterator = iterator + 2;
        }
        iterator++;
    }
}