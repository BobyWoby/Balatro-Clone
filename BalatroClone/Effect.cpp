#include "Effect.h"

extern std::map<std::string, EffectID> effectMap{
	{"copycat", COPYCAT},
	{"create card", CREATE_CARD},
	{"create joker", CREATE_JOKER},
	{"x mult", X_MULT},
	{"flat mult", FLAT_MULT},
	{"x chip", X_CHIP},
	{"flat chip", FLAT_MULT},
	{"probability", PROBABILITY},
	{"break probability", BREAK_PROB},
	{"max hands", MAX_HANDS},
	{"max rounds", MAX_ROUNDS},
};