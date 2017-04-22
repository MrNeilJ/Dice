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

#include "Players.hpp"
#include <string>
/**************************************************************
 *                  Players::Players()
 * Description: Constructor for the Players class.  It will
 * initialize a player object with a specific type of dice
 * (either normal or loaded) and store that information.
 * it will also initialize that dice with a number of sides.
**************************************************************/
Players::Players(int sides, bool loadedDie) {
	if (!loadedDie) {
		playerDie = std::make_shared<Die>(sides);
		diceType = "Standard Dice";
	}
	else {
		playerDie =  std::make_shared<LoadedDie>(sides);
		diceType = "Loaded Dice";
	}

}
/**************************************************************
 *                  Players::wonRounds()
 * Description: Member function for the players class.  It adds
 * 1 to the winner of the round for that specific player.
**************************************************************/
void Players::wonRound() {
	wins ++;

}

/**************************************************************
 *                  Players::getWins()
 * Description: Member function for the players class.  It returns
 * the value stored in the wins variable.
**************************************************************/
int Players::getWins() {
	return wins;
}

/**************************************************************
 *                  Players::addRoll()
 * Description: Member function for the players class. It adds
 * the last roll to the Rolls vector.
**************************************************************/
void Players::addRoll(int userRoll) {
	Rolls.push_back(userRoll);
}

/**************************************************************
 *                  Players::wonRounds()
 * Description: Member function for the players class.  It rolls
 * the specific die for whatever is stored in that players
 * shared pointer and returns the value.
**************************************************************/
int Players::rollDice() {

	if(diceType == "Standard Dice"){
		return playerDie->Roll();
	}
	else
	{
		return std::static_pointer_cast<LoadedDie>(playerDie)->Roll();
	}
}

/**************************************************************
 *                  Players::getRollAt()
 * Description: Member function for the players class.  It returns
 * whatever is stored at that specific section of the Rolls vector
**************************************************************/
int Players::getRollAt(int rollRequest) {
	return Rolls.at(rollRequest);
}

/**************************************************************
 *                  Players::getDiceType()
 * Description: Member function for the players class.  It returns
 * the dice type stored in that players playerDie object
**************************************************************/
std::string Players::getDiceType() {
	return diceType;
}

/**************************************************************
 *                  Players::~Players
 * Description: Destructor for the player class, it frees up
 * an memory dynamically created from this object.
**************************************************************/
Players::~Players() {
	playerDie.reset();
	playerDie = nullptr;
}
