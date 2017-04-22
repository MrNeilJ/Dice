/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.23.2017
 *
 * Description: This the the LoadedDie class for our Dice Program.
 * This program allows the player to intialize a special object
 * for a dice that cheats a little.  Upon initialization it creates
 * a loaded number which is the number it will most often reflect.
 * From here it has a similar roll function taht allows the user
 * to roll the dice and it will have almost double probability
 * to land on that number rather than another number.
**************************************************************/

#ifndef DICE_LOADEDDIE_HPP
#define DICE_LOADEDDIE_HPP

#include <cstdlib>
#include "Die.hpp"

class LoadedDie : public Die {
private:
	int n = -1;
	int loadedNumber = rand() % n;

public:
	//Constructors
	LoadedDie();
	LoadedDie(int);

	// Class functionality
	int Roll();
};


#endif //DICE_LOADEDDIE_HPP
