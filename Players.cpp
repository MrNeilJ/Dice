//
// Created by Neil on 4/19/2017.
//

#include "Players.hpp"
#include <string>

Players::Players(int sides, bool loadedDie) {
	if (!loadedDie) {
		playerDie = new Die(sides);
		diceType = "Standard Dice";
	}
	else {
		playerDie = new LoadedDie(sides);
		diceType = "Loaded Dice";
	}

}

void Players::wonRound() {
	wins ++;

}

int Players::getWins() {
	return wins;
}

void Players::addRoll(int userRoll) {
	Rolls.push_back(userRoll);
}

int Players::rollDice() {
	if(diceType == "Standard Dice"){
		return playerDie->Roll();
	}
	else
	{
		return  loadedDie->LoadedRoll();
	}
}

int Players::getRollAt(int rollRequest) {
	return Rolls.at(rollRequest);
}

std::string Players::getDiceType() {
	return diceType;
}
