//
// Created by Neil Johnson on 4/18/17.
//

#ifndef DICE_LOADEDDIE_HPP
#define DICE_LOADEDDIE_HPP

#include <cstdlib>
#include "Die.hpp"

class LoadedDie : public Die {
private:
	int n = -1;
	int loadedNumber = rand() % n;

public:
	LoadedDie();
	LoadedDie(int);


	int LoadedRoll();
};


#endif //DICE_LOADEDDIE_HPP
