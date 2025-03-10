#pragma once
#include <map>
#include <string>


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

extern std::map<std::string, EffectID> effectMap;
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