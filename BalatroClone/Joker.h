#include "Card.h"
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include "Sellable.h"
#pragma once

enum EffectID {
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

std::map<std::string, EffectID> effectMap{
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

typedef struct {
	EffectID id;
	std::string value;
} Effect;



class Joker : public Card
{
private:
	std::string name;
	Edition edition;
	int flatMult = 0, flatChip = 0, effectEnd = 0, handsPlayed = 0, roundsPlayed = 0;
	Effect effects[0xff];
	
public:
	~Joker() {

	}
	Joker() {
		Joker("Jokers/Jimbo.jkr");
	}

	Joker(std::string filepath) {
		std::string fileExtension = filepath.substr(filepath.find(".") + 1);
		if (fileExtension != "jkr") {
			throw std::invalid_argument("Inputed invalid Joker File");
		}
		std::ifstream f;
		f.open(filepath);
		std::stringstream buff;
		buff << f.rdbuf();
		std::string str, id, val;
		std::string delimiter = ":";
		while (std::getline(buff, str)) {

			std::string lower = "";
			for (char c : str) {
				lower += std::tolower(c);
			}
			str = lower;

			int splitPos = str.find(delimiter);
			id = str.substr(0, splitPos);
			val = str.substr(splitPos+1, str.length());
				
			if (effectMap.find(id) != effectMap.end()) {
				effects[effectEnd] = {effectMap[id], val};
				effectEnd++;
			}
			else if (id == "sell value") {
				sellValue = std::stod(val);
			}
		}
	}



};

