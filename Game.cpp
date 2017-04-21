//
// Created by Neil Johnson on 4/18/17.
//

#include <iostream>
#include "Game.hpp"
#include "validator.hpp"

Game::Game() {
	rounds = 10;
}
Game::Game(int userRounds){
	rounds = userRounds;
}

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

void Game::play() {
	for (int i = 0; i < rounds; i++){
		match();
	}
}

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
	else {
		winningPlayer = 2;
	}
	std::cout << "The winner is Player " << winningPlayer << ". Congratulations!!" << std::endl;
}

void Game::begin() {
	play();
	results();
}

void Game::makePlayer(int playerInput, int userSides, bool userLoaded){
	players[playerInput] = new Players(userSides, userLoaded);
}

void Game::clearBoard() {
	// Delete object stored in playerDie for each player
	players[0]->clearDie();
	players[1]->clearDie();

	delete[] *players;


}


