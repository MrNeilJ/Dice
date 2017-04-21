//
// Created by Neil Johnson on 4/18/17.
//

#ifndef DICE_GAME_HPP
#define DICE_GAME_HPP

#include "Die.hpp"
#include "Players.hpp"
#include "LoadedDie.hpp"


class Game {
private:
	int rounds;
	Players* players[2];

public:
	Game();
	Game(int);
	void match();
	void play();
	void results();
	void begin();
	void makePlayer(int playerInput, int userSides, bool userLoaded);
	~Game();
};


#endif //DICE_GAME_HPP
