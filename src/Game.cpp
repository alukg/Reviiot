#include <Game.h>
#include <sstream>
#include <algorithm>

//Game::Game(const Game &other) :
//        deck(other.deck), highestNumValue(other.highestNumValue), verbalOn(other.verbalOn) {
//
//    for (vector<Player *>::iterator it = other.players.begin(); it != other.players.end(); it++) {
//        switch (other.players[it]->getType()) {
//            case 1:
//                this->players[it] = new PlayerType1(*other.players[it]);
//                break;
//            case 2:
//                this->players[it] = new PlayerType2(*other.players[it]);
//                break;
//            case 3:
//                this->players[it] = new PlayerType3(*other.players[it]);
//                break;
//            case 4:
//                this->players[it] = new PlayerType4(*other.players[it]);
//                break;
//        }
//    }
//}

Game::Game(char *configurationFile) : numberOfTurns(0) {
    istringstream f(configurationFile);
    string line;

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
    //delete configurationFile;
}

void Game::insertCardsToDeck(Deck &deck, string deckCards) {
    long length = deckCards.length();
    int iterator = 0;
    int subIterator = 0;
    while (abs(length - iterator) > 1) {
        if (deckCards.at(iterator) != ' ') {
            subIterator = iterator;
            while (abs(length - subIterator) > 1 && deckCards.at(subIterator) != ' ') {
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

Player *Game::getPlayerWithMostCards(Player* me) {
    Player* chosenPlayer = nullptr;
    int maxNumOfCards = 0;
    int playerNumOfCards = 0;
    for (vector<Player *>::iterator it = players.begin(); it != players.end(); it++) {
        if(*it != me){
            playerNumOfCards = (*it)->getNumberOfCards();
            if(playerNumOfCards>=maxNumOfCards){
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
    }
}

void Game::giveCards(Player &player) {
    for (int i = 1; i <= 7; i++) {
        player.addCard(deck.fetchCard());
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
        cout <<(*it)->getName() + ' ' + (*it)->toString() << endl;
    }
}

void Game::printNumberOfTurns() {
    cout << numberOfTurns << endl;
}

bool Game::isFinished() const {
    for (vector<Player *>::const_iterator it = players.begin(); it != players.end(); it++) {
        if((*it)->getNumberOfCards() == 0)
            return true;
    }
    return false;
}

void Game::play() {
    while(!isFinished())
    {
        for (vector<Player *>::iterator it = players.begin(); it != players.end(); it++) {
            if ((*it)->getPosition() == (numberOfTurns % players.size()) + 1) {
                (*it)->playTurn();
                numberOfTurns++;
                printState();
                break;
            }
        }
    }
    printWinner();
}


void Game::printWinner() {

    string winnerLine = " ";
    int numOfWinners =0;
    for (vector<Player *>::const_iterator it = players.begin(); it != players.end(); it++) {
        if ((*it)->getNumberOfCards() == 0){
            if(numOfWinners ==0)
                winnerLine.append((*it)->getName());
            else {
                winnerLine.append(" and " + (*it)->getName());
            }
            numOfWinners++;
        }
        if (numOfWinners>1){
            cout << "***** The winners are:" + winnerLine + " ***" << endl;
        }
        else
            cout << "***** The Winner is:" + winnerLine + " *****" <<endl;
    }
}
