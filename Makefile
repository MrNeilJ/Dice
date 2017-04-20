output: main.o Game.o Players.o Die.o LoadedDie.o menuMaker.o validator.o
	g++ main.o Board.o menuMaker.o validator.o -std=c++11 -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Game.o: Game.cpp Game.hpp
	g++ -std=c++11 -c Game.cpp

Players.o: Players.cpp Players.hpp
	g++ -std=c++11 -c Players.cpp

Die.o: Die.cpp Die.hpp
	g++ -std=c++11 -c Die.cpp

LoadedDie.o: LoadedDie.cpp LoadedDie.hpp
	g++ -std=c++11 -c LoadedDie.cpp

menuMaker.o: menuMaker.cpp menuMaker.hpp
	g++ -std=c++11 -c  menuMaker.cpp

validator.o: validator.cpp validator.hpp
	g++ -std=c++11 -c validator.cpp

clean:
	rm *.o output