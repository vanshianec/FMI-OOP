#ifndef _DECK_H
#define _DECK_H

#include "Card.h"

class Deck
{
private:
	Card* cards;
	char series[11];
	size_t deckSize;
	size_t drawnCards;

public:
	Deck();
	Deck(const size_t k, const char* _series);
	Deck(const Deck& other);
	Deck& operator=(const Deck& other);
	~Deck();
	Card draw();
	void swap(const size_t firstNum, const size_t secondNum);
	size_t suitCount(const Suit suit) const;
	size_t rankCount(const Rank rank) const;
	double probabilityToWin(size_t currentPoints) const;

private:
	void copySeries(const char* _series);
	void copyCards(const Card* otherCards, const size_t size);
	void addCards(const size_t k);
	void generateUniqueSerialNumber(char* serialNumber, size_t id);
	void shuffleCards();
	void swapCards(const size_t firstIndex, const size_t secondIndex);
};

#endif
