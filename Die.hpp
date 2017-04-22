/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.23.2017
 *
 * Description: This is the head file for the class called Die.
 * This is the base class for this program that creates a dice
 * like object with a set number of sides.  It then has the
 * ability to roll, which allows the user to retrieve a random
 * number between 1 and n.
**************************************************************/

#ifndef DICE_DIE_HPP
#define DICE_DIE_HPP


class Die {
private:
int n;		// Number of Sides

public:
	// Constructors
	Die();
	Die(int);

	// Member Functions
	virtual int Roll();
};


#endif //DICE_DIE_HPP
