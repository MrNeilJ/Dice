/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.23.2017
 *
 * Description: This is the main class for the Dice program.
 * In here we build the main components of the application by
 * asking questions and having the user answer them.  These
 * questions consist of amount of turns, dice type, and sides
 * of the dice.  Once we have pulled this information from the
 * user it executes another class that plays the dice game for
 * us.
**************************************************************/

#include <iostream>
#include "menuMaker.hpp"
#include "validator.hpp"
#include "Game.hpp"
#include <string>
#include <time.h>

int main() {
	srand(time(NULL));
	int welcomeAnswer = 0;
	int turnsAnswer = 0;
	int turns = 0;
	int playAgain = 0;

    std::cout << "*==============================*" << std::endl;
    std::cout << "*           Die Game           *" << std::endl;
    std::cout << "*==============================*" << std::endl;
    std::cout << "Welcome to the die game. Before we begin here are the rules!\n" << std::endl;




	/********************************
	 *  QUESTION 1: ARE YOU READY?
	 ********************************/
	std::string WelcomeQuestion =   "There are two players in this game (Player 1, and Player 2).  The game is simple,\n"
									"it is played in rounds where each player will roll their dice, and the one with\n"
									" the higher number wins that round. The one to win the most rounds wins!\n\n"
									"Are you ready to proceed?";

    menuMaker welcomeMenu(WelcomeQuestion, "Yes", "No");
    welcomeMenu.prompt();

	do {
		welcomeAnswer = welcomeMenu.getResponse();
		if (welcomeAnswer == 2) {
			std::cout << "Confused? Here is the prompt again!\n" << std::endl;
			welcomeMenu.prompt();
		}
		else if (welcomeAnswer == 1) {
			std::cout << "Awesome, glad to hear! But before we begin we have a few questions for you.\n" << std::endl;
		}
		else {
			std::cout << "Whoops, I don't know that kind of number, try again please!" << std::endl;
			welcomeMenu.prompt();
		}
	} while(welcomeAnswer != 1);


	do {


		/********************************
		 * QUESTION 2: TURN TIME
		 ********************************/
		menuMaker turnsMenu("First off, how many rounds would you like to play?",
							"Set your own amount of turns? (number value greater than 0)",
							"Use the default amount of rounds? (Default is 10 Rounds)");
		turnsMenu.prompt();

		do {
			turnsAnswer = turnsMenu.getResponse();

			if (turnsAnswer == 1) {
				do {
					std::cout << "\nSounds good to me, how many turns would you like? \nUser Choice: ";
					turns = numberValidator();
				} while (turns <= 0);

				std::cout << "\nSetting turns to " << turns << ". Thank you." << std::endl;

			}
            else if (turnsAnswer == 2) {
				std::cout << "\nI like to keep things simple too, turns has been set to 10" << std::endl;
				turns = 10;
			}
            else {
				std::cout << "\nWhoops, I don't know that kind of number, try again please!" << std::endl;
				turnsMenu.prompt();
			}
		} while (turnsAnswer < 1 || turnsAnswer > 3);

		Game gameTime(turns);

		/********************************
		 * QUESTION 3: PLAYER CREATION
		 ********************************/
		menuMaker playerSides("how many sides will their Dice have?");
		menuMaker playerDieType("is their dice loaded?", "Yes, of course!", "No never! Keeping it fair!");
		int sides = 0;
		int playerDie = 0;
		bool isLoaded = false;


		std::cout << "Time to build our players!" << std::endl;
		for (int i = 0; i < 2; i++) {
			do {
                std::cout << "For player " << i + 1 << ", ";
                playerSides.prompt(-1);
                sides = playerSides.getResponse();

                if (sides < 2) {
                    std::cout << "That number of sides is not possible, try another number.";
                }
            } while (sides < 2);

            do {
                std::cout << "And as for Player " << i + 1 << " dice...";
                playerDieType.prompt();
                playerDie = playerDieType.getResponse();

                if (playerDie != 1 || playerDie != 2) {
                    std::cout << "Sorry, I did not understand that response, try again." << std::endl;
                }
            } while(playerDie < 0 || playerDie > 2);

			if (playerDie == 1) {
				isLoaded = true;
			}
			 else {
				isLoaded = false;
			}

			gameTime.makePlayer(i, sides, isLoaded);

		}


		/********************************
		 * GAME CREATION TIME!
		 ********************************/
		std::cout << "\n\nThe Results are in! Here they are:\n" << std::endl;
		gameTime.begin();

		/********************************
		 * QUESTION: PLAY AGAIN?
		 ********************************/
		menuMaker playMenu("\nWould you like to play again?", "Yes", "No");
		playMenu.prompt();
		playAgain = playMenu.getResponse();


	}while(playAgain == 1);




    return 0;
}

