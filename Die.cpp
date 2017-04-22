/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.23.2017
 *
 * Description: This is the file for the class called Die.
 * This is the base class for this program that creates a dice
 * like object with a set number of sides.  It then has the
 * ability to roll, which allows the user to retrieve a random
 * number between 1 and n.
**************************************************************/

#include <cstdlib>
#include "Die.hpp"


/**************************************************************
 *                  Die::Die()
 * Description: Constructor for the Die Object.  It sets the
 * number of sides to n = 6
**************************************************************/
Die::Die() {
	n = 6;
}

/**************************************************************
 *                  Die::Die()
 * Description: Constructor for the Die Object.  It allows for
 * user input for the number of sides.
**************************************************************/
Die::Die(int userN) {
	n = userN;
}

/**************************************************************
 *                  Die::Roll()
 * Description: Member function for the Die class.  It returns
 * a random integer from 1 to N back to the user.
**************************************************************/
int Die::Roll() {
	int temp = (rand() % n) + 1;
	return  temp;
}
