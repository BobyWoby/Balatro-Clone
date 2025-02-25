#pragma once
#include "Card.h"
class Joker
{
private:
	Edition edition;
	int xmult = 1, flatMult = 0, flatChip = 0;
public:
	Joker() {

	}
	virtual	double effect(Player player);
	void loadFromFile()
};

