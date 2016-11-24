all: reviiot

reviiot: bin/reviiyot.o bin/Card.o bin/Deck.o bin/FigureCard.o bin/Game.o bin/Hand.o bin/NumericCard.o bin/Player.o bin/PlayerType1.o bin/PlayerType2.o bin/PlayerType3.o bin/PlayerType4.o
	g++ -o bin/reviiot bin/reviiyot.o bin/Card.o bin/Deck.o bin/FigureCard.o bin/Game.o bin/Hand.o bin/NumericCard.o bin/Player.o bin/PlayerType1.o bin/PlayerType2.o bin/PlayerType3.o bin/PlayerType4.o

bin/reviiyot.o: src/reviiyot.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/reviiyot.o src/reviiyot.cpp
	
bin/Card.o: src/Card.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Card.o src/Card.cpp
	
bin/Deck.o: src/Deck.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Deck.o src/Deck.cpp
	
bin/FigureCard.o: src/FigureCard.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/FigureCard.o src/FigureCard.cpp
	
bin/Game.o: src/Game.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Game.o src/Game.cpp
	
bin/Hand.o: src/Hand.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Hand.o src/Hand.cpp
	
bin/NumericCard.o: src/NumericCard.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/NumericCard.o src/NumericCard.cpp
	
bin/Player.o: src/Player.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Player.o src/Player.cpp
	
bin/PlayerType1.o: src/Players/PlayerType1.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PlayerType1.o src/Players/PlayerType1.cpp
	
bin/PlayerType2.o: src/Players/PlayerType2.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PlayerType2.o src/Players/PlayerType2.cpp
	
bin/PlayerType3.o: src/Players/PlayerType3.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PlayerType3.o src/Players/PlayerType3.cpp
	
bin/PlayerType4.o: src/Players/PlayerType4.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PlayerType4.o src/Players/PlayerType4.cpp

clean: 
	rm -f bin/*