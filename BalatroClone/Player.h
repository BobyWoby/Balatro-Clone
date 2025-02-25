#pragma once
#include "Joker.h"
#include "Card.h"
class Player
{
private:
	double money;
	int *chips = 0, hands = 4, discards = 4, jokerLimit = 5, deckSize, handSize;
	Card* deck;
	Joker* jokers;

public:
	
	Player() {

	}
	~Player() {

	}

};


