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

#include "LoadedDie.hpp"

/**************************************************************
 *                  LoadedDie::LoadedDie()
 * Description: Constructor for the LoadedDie Object.  It sets the
 * number of sides to 6 and creates a random loadedNumber.
**************************************************************/
LoadedDie::LoadedDie() {
	n = 6;
	loadedNumber = (rand() % n) + 1;
}

/**************************************************************
 *                  LoadedDie::LoadedDie()
 * Description: Constructor for the LoadedDie Object.  It sets the
 * number of sides to the user iput and creates a random loadedNumber.
**************************************************************/
LoadedDie::LoadedDie(int sides) {
	n = sides;
	loadedNumber = (rand() % (sides - 1)) + 1;
}


/**************************************************************
 *                  LoadedDie::Roll()
 * Description: Member function that return to the user a random
 * number between 1 and N.  The chances of it landing on the
 * loadedNumber value is double.
**************************************************************/
int LoadedDie::Roll() {
	int temp = (rand() % ((n * 2) - 1) ) + 1;
	if (temp > n) {
		return  loadedNumber;
	}
	else {
		return temp;
	}

}

