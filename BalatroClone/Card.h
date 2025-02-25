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
private:
	int value = 1, chips = 11, mult = 1;
	// 11 = Jack, 12 = Queen, 13 = Kings, 1 = Aces
	Enhancement enhancement = NO_ENHANCEMENT;
	Edition edition = NO_EDITION;
	Seal seal = NO_SEAL;
public:
	Card() {
		
	}
	~Card() {
		
	}
};

