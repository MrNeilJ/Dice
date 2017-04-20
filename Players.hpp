//
// Created by Neil on 4/19/2017.
//

#ifndef DICE_PLAYERS_HPP
#define DICE_PLAYERS_HPP


#include <vector>
#include <string>
#include "Die.hpp"
#include "LoadedDie.hpp"

class Players {
private:
	int wins;					// This stores the amount of wins the player earned
	std::vector<int>Rolls;		// This stores each roll the player makes
	Die *playerDie;				// Pointer to a die class
	LoadedDie *loadedPlayer;
	std::string diceType;

public:
	Players(int, bool);
	void wonRound();
	int getWins();
	int rollDice();

	void addRoll(int userRoll);

	int getRollAt(int rollRequest);

	std::string getDiceType();
};


#endif //DICE_PLAYERS_HPP
