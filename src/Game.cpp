#include <Game.h>
#include <sstream>
#include <algorithm>

Game::Game(char *configurationFile) {
    istringstream f(configurationFile);
    string line;

    int highestNumValue;

    int counter = 1;
    while (getline(f, line) && counter != 5) {
        if (!line.empty() && line.at(0) != '#') {
            if (counter == 1) {
                verbalOn = stoi(line);
            } else if (counter == 2) {
                highestNumValue = stoi(line);
            } else if (counter == 3) {
                insertCardsToDeck(deck, line);
            } else if (counter == 4) {
                int playerCounter = 1;
                do {
                    if (!line.empty() && line.at(0) != ' ') {
                        string delimiter = " ";
                        string playerName = line.substr(0, line.find(delimiter));
                        int playerStrategy = stoi(line.substr(line.find(delimiter) + 1, 1));
                        addPlayer(playerName, playerStrategy, playerCounter);
                        playerCounter++;
                    }
                } while (getline(f, line));
            }
            counter++;
        }
    }

    // need to check how to delete that kind of variable
    delete configurationFile;
}

void Game::insertCardsToDeck(Deck &deck, string deckCards) {
    long length = deckCards.length();
    int iterator = 0;
    int subIterator = 0;
    while (abs(length - iterator) > 1) {
        if (deckCards.at(iterator) != ' ') {
            subIterator = iterator;
            while(abs(length - subIterator) > 1 && deckCards.at(subIterator) != ' '){
                subIterator++;
            }
            deck.addCard(deckCards.substr(iterator, subIterator - iterator));
            iterator = subIterator;
        }
        iterator++;
    }
}

//need to check how to insert the players, in the order we get them? or by astrategy?
void Game::addPlayer(string playerName, int playerStrategy, int position) {
    switch (playerStrategy) {
        case 1:
            players.push_back(new PlayerType1(position, playerName));
            break;
        case 2:
            players.push_back(new PlayerType2(position, playerName));
            break;
        case 3:
            players.push_back(new PlayerType3(position, playerName));
            break;
        case 4:
            players.push_back(new PlayerType4(position, playerName));
            break;
    }
}

void Game::init() {
    for (Player *player : players) {
        giveCards(*player);
    }
}

void Game::giveCards(Player &player) {
    for (int i = 1; i <= 7; i++) {
        player.addCard(deck.fetchCard());
    }
}