//
// Created by Neil Johnson on 4/18/17.
//

#ifndef DICE_DIE_HPP
#define DICE_DIE_HPP


class Die {
private:
int n;

public:
	Die();
	Die(int);
	virtual int Roll();
};


#endif //DICE_DIE_HPP
