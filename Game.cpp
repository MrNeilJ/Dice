/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.23.2017
 *
 * Description: This the the Game Class file for our Dice Program.
 * It hosts the majority of the functionality in this application.
 * It allows the user to build a game with 2 players that are
 * dynamically created through member functions.  From there it
 * can run through the game by making both players roll their
 * dice, and compare the values to see which one is higher.
 * The winner is the one that has won the most matches.
**************************************************************/

#include <iostream>
#include "Game.hpp"
#include "validator.hpp"

/**************************************************************
 *                  Game::Game()
 * Description: Constructor for the Game Object.  It sets the
 * number of rounds to 10.
**************************************************************/
Game::Game() {
	rounds = 10;
}

/**************************************************************
 *                  Game::Game()
 * Description: Constructor for the Game Object.  It sets the
 * number of rounds to whatever the user inputs.
**************************************************************/
Game::Game(int userRounds){
	rounds = userRounds;
}

/**************************************************************
 *                  Game::match()
 * Description: Member Function for the game class.  It
 * lays out what happens in each match, which is it will
 * pull a roll from each user and add that value to their rolls
 * array.  It will then compare the two rolls and see which
 * one is higher.  The higher value gets a win for that round.
**************************************************************/
void Game::match() {
	int playerOneRoll = players[0]->rollDice();
	int playerTwoRoll = players[1]->rollDice();

	players[0]->addRoll(playerOneRoll);
	players[1]->addRoll(playerTwoRoll);

	if (playerOneRoll > playerTwoRoll) {
		players[0]->wonRound();
	}
	else if (playerOneRoll == playerTwoRoll) {
		players[0]->wonRound();
		players[1]->wonRound();
	}
	else {
		players[1]->wonRound();
	}
}

/**************************************************************
 *                  Game::play()
 * Description: Member function for the game class.  It loops
 * the amount of matches depending on what the user inputs.
**************************************************************/
void Game::play() {
	for (int i = 0; i < rounds; i++){
		match();
	}
}

/**************************************************************
 *                  Game::results()
 * Description: Prints the results of the game in an easy to
 * read format to the console, it also lets the user know who
 * won the game.
**************************************************************/
void Game::results() {
	int winningPlayer;

	for(int i = 0; i < 2; i++) {
		std::cout << "Player " << i + 1 << std::endl;
		std::cout << "Dice Type: " << players[i]->getDiceType() << std::endl;
		std::cout << "Rolls:     ";
		for (int j = 0; j < rounds; j++) {
			std::cout << " " << players[i]->getRollAt(j);
		}
		std::cout << "\n-------------------------------------" << std::endl;
		std::cout << std::endl;
	}
	if (players[0]->getWins() > players[1]->getWins()) {
		winningPlayer = 1;
	}
	else if(players[0]->getWins() == players[1]->getWins()){
		winningPlayer = 3;
	}
	else {
		winningPlayer = 2;
	}
	if (winningPlayer == 1 || winningPlayer == 2) {
		std::cout << "The winner is Player " << winningPlayer << ". Congratulations!!" << std::endl;
	}
	else {
		std::cout << "By some amazing feet, the game has come to a draw!!" << std::endl;
	}
}

/**************************************************************
 *                  Game::begin()
 * Description: Class member function that allows the game to
 * start, and then prints the results to the console.
**************************************************************/
void Game::begin() {
	play();
	results();
}

/**************************************************************
 *                  Game::makePlayer()
 * Description: Dynamically creates a player using a pointer
 * to point to it.
**************************************************************/
void Game::makePlayer(int playerInput, int userSides, bool userLoaded){
	players[playerInput] = new Players(userSides, userLoaded);
}

/**************************************************************
 *                  Game::~Game()
 * Description: Detructor for the Game Object.  It frees all
 * of the used memory in the Game Class Object and sets the
 * pointers to null.
**************************************************************/
Game::~Game() {
	delete players[0];
	delete players[1];
	players[0] = nullptr;
	players[1] = nullptr;
}


