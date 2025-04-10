#pragma once
#include <map>
#include <string>

namespace {
	enum EffectID {
		NONE,
		COPYCAT,
		CREATE_CARD,
		CREATE_JOKER,
		X_MULT,
		FLAT_MULT,
		X_CHIP,
		FLAT_CHIP,
		BREAK_PROB,
		MAX_ROUNDS,
		MAX_HANDS,
		PROBABILITY,
	};

	extern std::map<std::string, EffectID> effectMap{
		{"copycat", COPYCAT},
		{"create card", CREATE_CARD},
		{"create joker", CREATE_JOKER},
		{"x mult", X_MULT},
		{"x chip", X_CHIP},
		{"flat mult", FLAT_MULT},
		{"flat chip", FLAT_CHIP},
		{"break probability", BREAK_PROB},
		{"probability", PROBABILITY},

	};
	class Effect {
	public:
		EffectID id;
		std::string value;
		Effect() {
			id = NONE;
			value = "";
		}
		Effect(EffectID id, std::string val) {
			this->id = id;
			value = val;
		}
	};
}