/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.23.2017
 *
 * Description: This is the Players class where it hosts all
 * of the player functionality.  It allows us to create the
 * baseline information for each player, such as their total
 * number of wins, the rolls they have done, as well as
 * what kind of dice they have and even roll their dice for them.
**************************************************************/

#ifndef DICE_PLAYERS_HPP
#define DICE_PLAYERS_HPP


#include <vector>
#include <string>
#include <memory>
#include "Die.hpp"
#include "LoadedDie.hpp"

class Players {
private:
	int wins = 0;						// This stores the amount of wins the player earned
	std::vector<int>Rolls;				// This stores each roll the player makes
	std::shared_ptr<Die> playerDie;		// Shared Pointer to a die class
	std::string diceType;

public:
	// Constructors
	Players(int, bool);

	// Round Tracking
	void wonRound();
	int getWins();

	// Dice Functionality
	int rollDice();
	void addRoll(int userRoll);
	int getRollAt(int rollRequest);
	std::string getDiceType();

	// Destructors
	~Players();
};


#endif //DICE_PLAYERS_HPP
