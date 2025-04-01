#pragma once
#include "Card.h"
enum Suit {
	SPADES = 0,
	HEARTS,
	CLUBS,
	DIAMONDS,
};


class PlayingCard :
    public Card
{

private:

public:
	Suit suit = SPADES;
	// 11 = Jack, 12 = Queen, 13 = Kings, 1 = Aces
	int rank = 1, chips = 11, mult = 1;
	PlayingCard() {

	}
	PlayingCard(int r, int c, int m, Suit su, Enhancement enhance, Edition ed, Seal se) {
		rank = r;
		chips = c;
		mult = m;
		suit = su;
		enhancement = enhance;
		edition = ed;
		seal = se;
	}
	~PlayingCard() {
		
	}


};

