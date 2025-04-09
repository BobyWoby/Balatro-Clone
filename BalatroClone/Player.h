#include <vector>
#include <random>
#include "Joker.h"
#include "PlayingCard.h"
#include "BigInteger.h"
#include "HandTypes.h"
#include <stdlib.h>
#include <time.h>

#define DEFAULT_DECK_SIZE 52
#define DEFAULT_CONSUMABLE_SLOTS 2


class Player {
private:

public:
	int seed = 0;
	std::vector<Joker> jokers;
	std::vector<PlayingCard> deck, currentHand, discardPile, playedCards;
	std::vector<Card> consumeables;
	std::default_random_engine rng;
	int selectedCards[5] = { -1, -1, -1,-1, -1 };
	double money = 4;
	int hands = 4, discards = 4, jokerLimit = 5, handSize = 8, deckSize = DEFAULT_DECK_SIZE, consumableSlots = DEFAULT_CONSUMABLE_SLOTS;
	BigInteger score, chips, mult;

	Player() : score(0), chips(0), mult(1), deck(DEFAULT_DECK_SIZE), consumeables(DEFAULT_CONSUMABLE_SLOTS), currentHand(handSize), jokers(0) {
		for (int i = 0; i < deck.size(); i++) {
			int rank = i % 13 + 1;
			deck[i] = PlayingCard(rank, (rank == 1) ? 11 : (rank > 10) ? 10 : rank, 0, (Suit)(i % 4), NO_ENHANCEMENT, NO_EDITION, NO_SEAL);
		}
		jokers.push_back(Joker());
		seed = (int)time(0);
		srand(seed);
	}
	Player(int seed) : Player() {
		this->seed = seed;
		srand(seed);
	}
	~Player() {}

	void selectCard(int cardIndex) {
		int length = sizeof(selectedCards) / sizeof(selectedCards[0]);
		if (cardIndex > currentHand.size() - 1) return;
		int openSlots = 0;
		for (int i = 0; i < length; i++) {
			if (selectedCards[i] == cardIndex) {
				//unselect the card
				selectedCards[i] = -1;
				std::cout << "\nSelected Cards\n------------" << std::endl;
				for (int i : selectedCards) {
					if (i != -1) {
						std::cout << (std::string)currentHand.at(i) << std::endl;
					}
				}
				return;
			}
		}
		for (int i = 0; i < length; i++) {
			int num = selectedCards[i];
			if (num == -1) break;
			else openSlots++;
		}

		if (openSlots >= length) return;

		for (int i = 0; i < length; i++) {
			if (selectedCards[i] == -1) {
				selectedCards[i] = cardIndex;
				break;
			}
		}

		std::cout << "\nSelected Cards\n------------" << std::endl;
		for (int i : selectedCards) {
			if (i != -1) {
				std::cout << (std::string)currentHand.at(i) << std::endl;
			}
		}
	}

	BigInteger calculateScore() {
		//sort selectedCards

		std::vector<PlayingCard> playedCards;

		for (int i : selectedCards) {
			if (i != -1) {
				playedCards.push_back(currentHand.at(i));
				currentHand.erase(currentHand.begin() + i, currentHand.begin() + i + 1);
			}
		}

		// TODO: figure out what the score is of playedCards

		HandType type = findHandType(playedCards);
		BigInteger chip = BigInteger(type.chips + (type.lvl - 1) * (type.chipScaling)); // base chip
 		BigInteger mult = BigInteger(type.mult + (type.lvl - 1)* (type.multScaling)); // base mult

		for (auto card : playedCards) {



			for (auto joker : jokers) {
				//apply when card is scored jokers
				if (joker.triggerState == CARD_PLAYED) {

				}
			}
		}

		for (auto joker : jokers) {
			//apply other jokers
			if (joker.triggerState == DEFAULT) {

			}
		}


		for (auto card : playedCards) {
			discardPile.push_back(card);
		}
		playedCards.clear();
		return mult * chip;
	}
	void logScore() {
		std::vector<PlayingCard> playedCards;
		for (int i : selectedCards) {
			if (i != -1) {
				playedCards.push_back(currentHand.at(i));
			}
		}
		std::cout << "Hand Type: " << findHandType(playedCards).name;
		std::cout << "\nScore: " << calculateScore().getString() << std::endl;
	}

	

	void clearSelection() {
		for (int i = 0; i < 5; i++) {
			selectedCards[i] = -1;
		}
	}
	void playHand() {

	}
	void drawHand() {
		if (!currentHand.empty()) {
			clearHand();
		}
		for (int i = 0; i < handSize; i++) {
			//std::uniform_int_distribution<> dist(0, deck.size() - 1);
			//int index = dist(rng);
			int index = rand() % deck.size();
			currentHand.push_back(deck.at(index));
			deck.erase(deck.begin() + index, deck.begin() + index + 1);
		}
	}

	void clearHand() {
		clearSelection();
		while (!currentHand.empty()) {
			deck.push_back(currentHand.at(currentHand.size() - 1));
			currentHand.pop_back();
		}
	}


};
