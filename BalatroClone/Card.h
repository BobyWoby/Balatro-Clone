#pragma once
enum Edition {
	NO_EDITION,
	FOIL,
	POLYCHROME,
	NEGATIVE
};
enum Enhancement {
	NO_ENHANCEMENT,
	MULT,
	LUCKY,
	BONUS,
	STEEL,
	GOLD
};
enum Seal {
	NO_SEAL,
	RED,
	PURPLE,
	YELLOW
};

class Card
{
	int value, chips, mult;
	// 11 = Jack, 12 = Queen, 13 = Kings, 14 = Aces
	Enhancement enhancement;
	Edition edition;
	Seal seal;


};

