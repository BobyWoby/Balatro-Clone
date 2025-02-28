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
	YELLOW,
};

class Card {
private:
	
public:
	Enhancement enhancement = NO_ENHANCEMENT;
	Edition edition = NO_EDITION;
	Seal seal = NO_SEAL;
	double sellValue = 0;
	Card() {

	}
	
	~Card() {

	}
	
};

