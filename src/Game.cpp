#include "../include/Game.h"
#include <sstream>
#include <algorithm>
#include <fstream>


Game::Game(Game &other) :
        players(), verbalOn(other.verbalOn), deck(other.deck) {

    for (vector<Player *>::const_iterator it = other.players.begin(); it != other.players.end(); it++) {
        switch ((*it)->getType()) {
            case 1:
                players.push_back(new PlayerType1(**it));
                break;
            case 2:
                players.push_back(new PlayerType2(**it));
                break;
            case 3:
                players.push_back(new PlayerType3(**it));
                break;
            case 4:
                players.push_back(new PlayerType4(**it));
                break;
        }
    }
}

Game::Game(char *configurationFile) : players(), verbalOn(), deck() {

    string line, content;
    ifstream readConfig(string() + configurationFile);
    content.append((std::istreambuf_iterator<char>(readConfig)),
                   (std::istreambuf_iterator<char>()));
    if (!readConfig.is_open()) {
        cout << "Can't access config file" << endl;
        cout << "Exisitng program" << endl;
        exit(1);
    }
    readConfig.close();
    istringstream f(content);
    int counter = 1;
    while (getline(f, line) && counter != 5) {
        if (!line.empty() && line.at(0) != '#') {
            if (counter == 1) {
                if (stoi(line) == 1)
                    verbalOn = true;
                else
                    verbalOn = false;
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
}

Game::Game(Game &&other) :
        players(), verbalOn(other.verbalOn), deck(other.deck) {

    for (vector<Player *>::const_iterator it = other.players.begin(); it != other.players.end(); it++) {
        switch ((*it)->getType()) {
            case 1:
                players.push_back(new PlayerType1(**it));
                break;
            case 2:
                players.push_back(new PlayerType2(**it));
                break;
            case 3:
                players.push_back(new PlayerType3(**it));
                break;
            case 4:
                players.push_back(new PlayerType4(**it));
                break;
        }
    }
}

void Game::insertCardsToDeck(Deck &deck, string deckCards) {
    long length = deckCards.length();
    int iterator = 0;
    int subIterator = 0;
    while (abs(length - iterator) > 1) {
        if (deckCards.at(iterator) != ' ') {
            subIterator = iterator;
            while (abs(length - subIterator) >= 1 && deckCards.at(subIterator) != ' ') {
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
            players.push_back(new PlayerType1(position, playerName, *this));
            break;
        case 2:
            players.push_back(new PlayerType2(position, playerName, *this));
            break;
        case 3:
            players.push_back(new PlayerType3(position, playerName, *this));
            break;
        case 4:
            players.push_back(new PlayerType4(position, playerName, *this));
            break;
    }
}

Player *Game::getPlayerWithMostCards(Player &me) {
    Player *chosenPlayer = nullptr;
    int maxNumOfCards = 0;
    int playerNumOfCards = 0;
    for (vector<Player *>::iterator it = players.begin(); it != players.end(); it++) {
        if (*it != &me) {
            playerNumOfCards = (*it)->getNumberOfCards();
            if (playerNumOfCards >= maxNumOfCards) {
                maxNumOfCards = playerNumOfCards;
                chosenPlayer = *it;
            }
        }
    }

    return chosenPlayer;
}

void Game::init() {
    for (Player *player : players) {
        giveCards(*player);
        player->isFour();
    }
}

void Game::giveCards(Player &player) {
    for (int i = 1; i <= 7; i++) {
        player.addCard(*(deck.fetchCard()));
    }
}


vector<Player *> &Game::getPlayers() {
    return this->players;
}


Deck &Game::getGameDeck() {
    return this->deck;
}

void Game::printState() {
    cout << "Deck:" + deck.toString() << endl;
    for (vector<Player *>::iterator it = players.begin(); it != players.end(); it++) {
        cout << (*it)->toString() << endl;
    }

}

void Game::printNumberOfTurns() {
    cout << "Number of Turns: " + to_string(numberOfTurns) << endl;
}

bool Game::isFinished() const {
    for (vector<Player *>::const_iterator it = players.begin(); it != players.end(); it++) {
        if ((*it)->getNumberOfCards() == 0)
            return true;
    }
    return false;
}

void Game::play() {
    while (!isFinished()) {
        if (getVerbalOn()) {
            cout << "Turn " + to_string(numberOfTurns + 1) << endl;
            printState();
        }
        players[numberOfTurns % players.size()]->playTurn();
        numberOfTurns++;

    }
}

void Game::printWinner() {

    string winnerLine = " ";
    int numOfWinners = 0;
    for (vector<Player *>::iterator it = players.begin(); it != players.end(); it++) {
        if ((*it)->getNumberOfCards() == 0) {
            if (numOfWinners == 0)
                winnerLine.append((*it)->getName());
            else {
                winnerLine.append(" and " + (*it)->getName());
            }
            numOfWinners++;
        }
    }
    if (getVerbalOn()) {
        cout << "----------" << endl;
    }
    if (numOfWinners > 1) {
        cout << "***** The winners are:" + winnerLine + " *****" << endl;
    } else
        cout << "***** The Winner is:" + winnerLine + " *****" << endl;

}

int Game::getHighestNumValue() {
    return highestNumValue;
}

int Game::highestNumValue;


Game::~Game() {
    for (vector<Player *>::iterator it = players.begin(); it != players.end(); it++) {
        delete (*it);
    }
};

bool Game::getVerbalOn() const {
    return verbalOn;
}