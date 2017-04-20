//
// Created by Neil Johnson on 4/18/17.
//

#include "LoadedDie.hpp"

LoadedDie::LoadedDie() {
	n = 6;
	loadedNumber = (rand() % n) + 1;
}

LoadedDie::LoadedDie(int sides) {
	n = sides;
	loadedNumber = (rand() % (sides - 1)) + 1;
}

int LoadedDie::Roll() {
	int temp = (rand() % ((n * 2) - 1) ) + 1;
	if (temp > n) {
		return  loadedNumber;
	}
	else {
		return temp;
	}

}

int LoadedDie::LoadedRoll() {
	int temp = (rand() % ((n * 2) - 1) ) + 1;
	if (temp > n) {
		return  loadedNumber;
	}
	else {
		return temp;
	}
}