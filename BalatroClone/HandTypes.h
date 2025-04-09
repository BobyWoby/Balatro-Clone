#pragma once
#include <string>
#include "PlayingCard.h"
#include <vector>

namespace {
	int straightThresh = 5, flushThresh = 5, straightGaps = 1;
	struct HandType {
	public:
		std::string name;
		int chips, mult;
		int chipScaling, multScaling;
		int lvl;

		HandType(std::string n, int c, int m, int cs, int ms) {
			name = n;
			chips = c;
			mult = m;
			chipScaling = cs;
			multScaling = ms;
			lvl = 1;
		}
		HandType() {

		}
	};

	 extern std::map<std::string, HandType> handTypes = {
		{"high-card",{"High Card", 5, 1, 10, 1}},
		{"pair",{"Pair", 10, 2, 15, 1}},
		{"two-pair",{"Two Pair", 20, 2, 20, 1}},
		{"three-of-a-kind",{"Three of a Kind", 30, 3, 20, 2}},
		{"straight",{"Straight", 30, 4, 30, 3}},
		{"flush",{"Flush", 35, 4, 15, 2}},
		{"full-house",{"Full House", 40, 4, 25, 2}},
		{"four-of-kind",{"Four of a Kind", 60, 7, 30, 3}},
		{"straight-flush",{"Straight Flush", 100, 8, 40, 4}},
		{"five-of-a-kind",{"Five of a Kind", 120, 12, 35, 3}},
		{"flush-house",{"Flush House", 140, 14, 40, 4}},
		{"flush-five",{"Flush Five", 160, 16, 50, 3}},
	};
	void levelUpHand(std::string id) {
		handTypes[id].lvl++;
	}
	void setHandLevel(std::string id, int lvl) {
		handTypes[id].lvl = lvl;
	}

	HandType findHandType(std::vector<PlayingCard> cards, std::vector<PlayingCard> &scoredCards) {
		//assumes empty scored cards vector
		
		// sort the cards in ascending order of rank
		std::sort(cards.begin(), cards.end(), [](PlayingCard& a, PlayingCard& b) {return a.rank < b.rank; });

		int counter = 0, flushCounter = 0, rankCounter = 0, numRanks = 0, c = 0, straightCounter = 0;
		int ranks[5] = { 0,0,0,0,0 };
		int r = cards.at(0).rank, countMode = 0, rankMode = cards.at(0).rank;
		int s = cards.at(0).suit, suitCounter = 0, suitModeCount = 0, suitMode = cards.at(0).suit;
		//check for flush five, flushes, five-of-a-kind
		for (int i = 0; i < cards.size(); i++) {
			if (i + 1 < cards.size() && cards.at(i) == cards.at(i + 1)) counter++;
			if (i + 1 < cards.size() && cards.at(i).suit == cards.at(i + 1).suit) flushCounter++;

			if (cards.at(i).rank == r) {
				rankCounter++;
			}
			else {
				if (rankCounter > countMode) {
					countMode = rankCounter;
					rankMode = r;
				}
				rankCounter = 1;
				r = cards[i].rank;
			}

			if (cards.at(i).suit == s) {
				suitCounter++;
			}
			else {
				if (suitCounter > suitModeCount) {
					suitModeCount = suitCounter;
					suitMode = r;
				}
				suitCounter = 1;
				s = cards[i].suit;
			}

			c = 0;
			for (int j : ranks) {
				if (j != cards.at(i).rank) c++;
			}
			if (c >= 5) {
				numRanks++;
				for (int j = 0; j < sizeof(ranks) / sizeof(ranks[0]); j++) {
					if (ranks[j] == 0) {
						ranks[j] = cards.at(i).rank;
						break;
					}
				}
			}
		}
		if (rankCounter > countMode) {
			countMode = rankCounter;
			rankMode = r;
		}

		// check if the hand is straight
		for (int i = 0; i < cards.size() - 1; i++) {
			if (cards.at(i + 1).rank - cards.at(i).rank <= straightGaps)
			{
				scoredCards.push_back(cards.at(i));
				straightCounter++;
			}
			else if (i == cards.size() - 2 && cards.at(i).rank == 13 && cards.at(0).rank == 1)
			{
				scoredCards.push_back(cards.at(i));
				straightCounter++;
			}
		}


		if (counter == 5)
		{
			scoredCards = cards;
			return handTypes["flush-five"];
		}
		if ((countMode == 2 || countMode == 3)  && numRanks == 2 && flushCounter == 5) 
		{
			scoredCards = cards;
			return handTypes["flush-house"];
		}
		if (countMode == 5)
		{
			scoredCards = cards;
			return handTypes["five-of-a-kind"];
		}
		if (straightCounter == straightThresh && suitModeCount == flushThresh)
		{
			//scoredCards = {};
			for (auto card : cards) {
				if (card.suit == suitMode && std::find(scoredCards.begin(), scoredCards.end()) == scoredCards.end()) {
					scoredCards.push_back(card);
				}
			}
			return handTypes["straight-flush"];
		}
		if (countMode == 4) 
		{
			return handTypes["four-of-a-kind"];
		}
		if (countMode == 3 && numRanks == 2 && cards.size() >= 5) 
		{
			scoredCards = cards;
			return handTypes["full-house"];
		}
		if (flushCounter == flushThresh) return handTypes["flush"];
		if (straightCounter == straightThresh) return handTypes["straight"]; 
		if (countMode == 3) return handTypes["three-of-a-kind"]; 
		if (countMode == 2 && numRanks == 3) return handTypes["two-pair"]; 
		if (countMode == 2) return handTypes["pair"]; 
		return handTypes["high-card"];
	}


	HandType findHandType(std::vector<PlayingCard> cards) {
		// sort the cards in ascending order of rank
		std::sort(cards.begin(), cards.end(), [](PlayingCard& a, PlayingCard& b) {return a.rank < b.rank; });

		int counter = 0, flushCounter = 0, rankCounter = 0, numRanks = 0, c = 0, straightCounter = 0;
		int ranks[5] = { 0,0,0,0,0 };
		int r = cards.at(0).rank, countMode = 0, rankMode = cards.at(0).rank;
		int s = cards.at(0).suit, suitCounter = 0, suitModeCount = 0, suitMode = cards.at(0).suit;
		//check for flush five, flushes, five-of-a-kind
		for (int i = 0; i < cards.size(); i++) {
			if (i + 1 < cards.size() && cards.at(i) == cards.at(i + 1)) counter++;
			if (i + 1 < cards.size() && cards.at(i).suit == cards.at(i + 1).suit) flushCounter++;

			if (cards.at(i).rank == r) {
				rankCounter++;
			}
			else {
				if (rankCounter > countMode) {
					countMode = rankCounter;
					rankMode = r;
				}
				rankCounter = 1;
				r = cards[i].rank;
			}

			if (cards.at(i).suit == s) {
				suitCounter++;
			}
			else {
				if (suitCounter > suitModeCount) {
					suitModeCount = suitCounter;
					suitMode = r;
				}
				suitCounter = 1;
				s = cards[i].suit;
			}

			c = 0;
			for (int j : ranks) {
				if (j != cards.at(i).rank) c++;
			}
			if (c >= 5) {
				numRanks++;
				for (int j = 0; j < sizeof(ranks) / sizeof(ranks[0]); j++) {
					if (ranks[j] == 0) {
						ranks[j] = cards.at(i).rank;
						break;
					}
				}
			}
		}
		if (rankCounter > countMode) {
			countMode = rankCounter;
			rankMode = r;
		}

		for (int i = 0; i < cards.size() - 1; i++) {
			if (cards.at(i + 1).rank - cards.at(i).rank <= straightGaps)
			{
				
				straightCounter++;
			}
			else if (i == cards.size() - 2 && cards.at(i).rank == 13 && cards.at(0).rank == 1) 
			{

				straightCounter++;
			}
		}

		if (counter == 5) return handTypes["flush-five"];
		//TODO: check for flush house
		if ((countMode == 2 || countMode == 3) && numRanks == 2 && flushCounter == flushThresh) return handTypes["flush-house"];
		if (countMode == 5) return handTypes["five-of-a-kind"];
		if (straightCounter == 5 && flushCounter == 5) return handTypes["straight-flush"];
		if (countMode == 4) return handTypes["four-of-a-kind"];
		if (countMode == 3 && numRanks == 2) return handTypes["full-house"];
		if (flushCounter == 5) return handTypes["flush"];
		if (straightCounter == 5) return handTypes["straight"];
		if (countMode == 3) return handTypes["three-of-a-kind"];
		if (countMode == 2 && (numRanks == cards.size() - 2)) return handTypes["two-pair"];
		if (countMode == 2) return handTypes["pair"];
		return handTypes["high-card"];
	}
}

