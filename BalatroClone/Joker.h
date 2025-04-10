#pragma once
#include "Effect.h"
#include "Card.h"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include "Sellable.h"
#include <map>


namespace {
	extern enum TriggerState {
		DEFAULT, // after the scored cards and such
		CARD_PLAYED,
		CARD_SCORED,
		CARD_DISCARDED,
		END_ROUND,
		END_SHOP,
		BEGIN_ROUND,
		OPEN_PACK

	};
	extern std::map<std::string, TriggerState> triggerStates{
		{"default", DEFAULT},
		{"card played", CARD_PLAYED},
		{"card scored", CARD_PLAYED},
		{"card discarded", CARD_DISCARDED},
		{"end round", END_ROUND},
		{"end shop", END_SHOP},
		{"begin round", BEGIN_ROUND},
		{"open pack", OPEN_PACK},

	};
	class Joker : public Card
	{
	private:
		std::string name, description;

	public:
		int flatMult = 0, flatChip = 0, effectEnd = 0, handsPlayed = 0, roundsPlayed = 0;
		Edition edition;
		Effect effects[0xff];
		TriggerState triggerState;
		~Joker() {

		}
		Joker() : Joker("Jokers/Jimbo.jkr") {}

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
				/*std::string lower = "";
				for (char c : str) {
					lower += std::tolower(c);
				}
				str = lower;*/

				int splitPos = str.find(delimiter);
				id = str.substr(0, splitPos);
				val = str.substr(splitPos + 1, str.length());

				if (effectMap.find(id) != effectMap.end()) {
					effects[effectEnd] = Effect(effectMap[id], val);
					effectEnd++;
				}
				else if (id == "sell value") {
					sellValue = std::stod(val);
				}
				else if (id == "name") {
					name = val;
				}
				else if (id == "trigger state") {
					triggerState = triggerStates[val];
				}
			}
		}

		explicit operator std::string() {
			std::string out = "";
			out += "Name: " + name + "\nEdition: " + editions[edition].c_str();
			return out;
		}
	};

}
