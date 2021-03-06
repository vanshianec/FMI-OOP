#ifndef _CARD_H
#define _CARD_H

#include<iostream>
#include<cstring>

#include "Suit.h"
#include "Rank.h"

class Card
{
private:
	Suit suit;
	Rank rank;
	char serialNumber[16];

public:
	Card();
	Card(const Suit _suit, const Rank _rank, const char* _serialNumber);
	Card(const Card& other);
	Card& operator=(const Card& other);
	Suit getSuit() const;
	Rank getRank() const;
	size_t getPoints() const;

private:
	void copySerialNumber(const char* _serialNumber);
};

const char* suitToStr(Suit suit);
const char* rankToStr(Rank rank);
std::ostream& operator<<(std::ostream& out, const Card& card);

#endif