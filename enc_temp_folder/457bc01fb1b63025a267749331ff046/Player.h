#include <vector>
#include <random>
#include "Joker.h"
#include "PlayingCard.h"
#include "BigInteger.h"

#define DEFAULT_DECK_SIZE 52

class Player {
private:

public:
	std::vector<Joker> jokers;
	std::vector<PlayingCard> deck, currentHand, discardPile;
	std::vector<Card> consumeables;
	std::default_random_engine rng;

	double money = 4;
	int hands = 4, discards = 4, jokerLimit = 5, handSize = 8, deckSize = DEFAULT_DECK_SIZE;
	BigInteger score, chips, mult;
	Player() : score(0), chips(0), mult(1), deck(DEFAULT_DECK_SIZE), consumeables(1000), currentHand(handSize), jokers(0) {
		for (int i = 0; i < deck.size(); i++) {
			int rank = i % 13 + 1;
			deck[i] = PlayingCard(rank, (rank == 1) ? 11 : (rank > 10) ? 10 : rank, 0, (Suit)(i % 4), NO_ENHANCEMENT, NO_EDITION, NO_SEAL);
		}
		jokers.push_back(Joker());
	}
	~Player() {}
	void drawHand() {
		if (!currentHand.empty()) {
			clearHand();
		}
		for (int i = 0; i < handSize; i++) {
			std::uniform_int_distribution<> dist(0, deck.size()-1);
			int index = dist(rng);
			currentHand.push_back(deck.at(index));
			deck.erase(deck.begin() + index, deck.begin() + index + 1);
		}
	}
	void clearHand() {
		while(!currentHand.empty()) {
			deck.push_back(currentHand.at(currentHand.size()-1));
			currentHand.pop_back();
		}
	}


};
