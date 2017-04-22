/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.23.2017
 *
 * Description: This the the Game Class header file for our Dice Program.
 * It hosts the majority of the functionality in this application.
 * It allows the user to build a game with 2 players that are
 * dynamically created through member functions.  From there it
 * can run through the game by making both players roll their
 * dice, and compare the values to see which one is higher.
 * The winner is the one that has won the most matches.
**************************************************************/
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
	// Constructors
	Game();
	Game(int);

	// Game functionality
	void match();
	void play();
	void results();
	void begin();

	// Player Creation
	void makePlayer(int playerInput, int userSides, bool userLoaded);

	// Destructors
	~Game();
};


#endif //DICE_GAME_HPP
