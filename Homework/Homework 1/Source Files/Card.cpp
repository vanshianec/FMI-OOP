#ifndef _CARD_CPP
#define _CARD_CPP

#include "Card.h"

Card::Card() : suit(Suit::CLUBS), rank(Rank::ACE)
{
	serialNumber[0] = '\0';
}

Card::Card(const Suit _suit, const Rank _rank, const char* _serialNumber) : suit(_suit), rank(_rank)
{
	copySerialNumber(_serialNumber);
}

Card::Card(const Card& other) : suit(other.suit), rank(other.rank)
{
	copySerialNumber(other.serialNumber);
}

Card& Card::operator=(const Card& other)
{
	if (this != &other)
	{
		copySerialNumber(other.serialNumber);
		suit = other.suit;
		rank = other.rank;
	}

	return *this;
}

Suit Card::getSuit() const
{
	return suit;
}

Rank Card::getRank() const
{
	return rank;
}

size_t Card::getPoints() const
{
	switch (rank)
	{
	case Rank::TWO:
		return 2;
	case Rank::THREE:
		return 3;
	case Rank::FOUR:
		return 4;
	case Rank::FIVE:
		return 5;
	case Rank::SIX:
		return 6;
	case Rank::SEVEN:
		return 7;
	case Rank::EIGHT:
		return 8;
	case Rank::NINE:
		return 9;
	case Rank::TEN:
		return 10;
	case Rank::JACK:
		return 10;
	case Rank::QUEEN:
		return 10;
	case Rank::KING:
		return 10;
	case Rank::ACE:
		return 11;
	}
}

void Card::copySerialNumber(const char* _serialNumber)
{
	serialNumber[0] = '\0';

	if (_serialNumber != nullptr)
	{
		size_t len = strlen(_serialNumber);
		strcpy_s(serialNumber, len + 1, _serialNumber);
	}
}

const char* suitToStr(Suit s)
{
	switch (s)
	{
	case Suit::CLUBS:
		return "clubs";
	case Suit::DIAMONDS:
		return "diamonds";
	case Suit::HEARTS:
		return "hearts";
	case Suit::SPADES:
		return "spades";
	}
}

const char* rankToStr(Rank r)
{
	switch (r)
	{
	case Rank::TWO:
		return "2";
	case Rank::THREE:
		return "3";
	case Rank::FOUR:
		return "4";
	case Rank::FIVE:
		return "5";
	case Rank::SIX:
		return "6";
	case Rank::SEVEN:
		return "7";
	case Rank::EIGHT:
		return "8";
	case Rank::NINE:
		return "9";
	case Rank::TEN:
		return "10";
	case Rank::JACK:
		return "Jack";
	case Rank::QUEEN:
		return "Queen";
	case Rank::KING:
		return "King";
	case Rank::ACE:
		return "Ace";
	}
}

std::ostream& operator<<(std::ostream& out, const Card& card)
{
	out << rankToStr(card.getRank());
	out << '(';
	out << suitToStr(card.getSuit());
	out << ')';
	return out;
}

#endif

