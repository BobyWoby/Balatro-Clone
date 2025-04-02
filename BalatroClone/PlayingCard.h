#pragma once
#include "Card.h"
#include <map>
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
	std::map<Suit, std::string> suitDict{
	{SPADES, "Spades"},
	{HEARTS, "Hearts"},
	{CLUBS, "Clubs"},
	{DIAMONDS, "Diamonds"},
	};
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

	operator std::string() {
		std::string str = "";
		switch (rank) {
		case 11:
			str += "Jack";
			break;
		case 12:
			str += "Queen";
			break;
		case 13:
			str += "King";
			break;
		case 1:
			str += "Ace";
			break;
		default:
			str += std::to_string(rank);
			break;
		}
		str += " of ";
		str += suitDict[this->suit];

		return str;
	}

};

