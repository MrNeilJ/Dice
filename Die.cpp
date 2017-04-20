//
// Created by Neil Johnson on 4/18/17.
//

#include <cstdlib>
#include "Die.hpp"

Die::Die() {
	n = 6;
}

Die::Die(int userN) {
	n = userN;
}

int Die::Roll() {
	int temp = (rand() % n) + 1;
	return  temp;
}
