#include <vector>
#include "Joker.h"
#include "PlayingCard.h"
#include "BigInteger.h"

class Player {
private:
	
public:
	std::vector<Joker> jokers;
	std::vector<PlayingCard> deck, currentHand;
	std::vector<Card> consumeables;
	double money = 4;
	int hands = 4, discards = 4, jokerLimit = 5, deckSize = 52, handSize = 8;
	BigInteger score, chips, mult;
	Player() : score(0), chips(0), mult(1), deck(1000), consumeables(1000), currentHand(0xff), jokers(0xff) {
		for (int i = 0; i < deckSize; i++) {
			int rank = i % 13 + 1;
			deck[i] = PlayingCard(rank, (rank == 1) ? 11 : (rank > 10) ? 10 : rank, 0, (Suit)(i % 4), NO_ENHANCEMENT, NO_EDITION, NO_SEAL);
		}
		jokers[0] = Joker();
	}
	~Player() {}
};
