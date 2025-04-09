#pragma once
#include <string>
#include <map>
namespace {
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
	extern std::map<Edition, std::string> editions = {
		{NO_EDITION, "None"},
		{FOIL, "Foil"},
		{POLYCHROME, "Polychrome"},
		{NEGATIVE, "Negative"},
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
		explicit operator std::string() {

		}
	};


}
