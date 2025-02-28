#pragma once
#include "Joker.h"
#include "Card.h"
#include "PlayingCard.h"
#include "HelperFunctions.h"

class Player
{
private:
	double money = 4;
	int  hands = 4, discards = 4, jokerLimit = 5, deckSize = 52, handSize = 8;
	int8_t score[0xffff], chips[0xfff], mult[0xfff];
	Card deck[0xfff], consumeables[0xfff], currentHand[0xff];
	Joker jokers[0xff];

public:
	Player() {
		for (int i = 0; i < deckSize; i++) {
			int rank = i % 13 + 1;
			deck[i] = PlayingCard(rank, (rank == 1) ? 11 : (rank > 10) ? 10 : rank, 0, (Suit)(i % 4), NO_ENHANCEMENT, NO_EDITION, NO_SEAL);
		}
	}
	~Player() {
		
	}
	

};


