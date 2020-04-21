#ifndef _CARD_CPP
#define _CARD_CPP

#include "Card.h"

Card::Card() : suit(Suit::Clubs), rank(Rank::Ace)
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
	case Rank::Two:
		return 2;
	case Rank::Three:
		return 3;
	case Rank::Four:
		return 4;
	case Rank::Five:
		return 5;
	case Rank::Six:
		return 6;
	case Rank::Seven:
		return 7;
	case Rank::Eight:
		return 8;
	case Rank::Nine:
		return 9;
	case Rank::Ten:
		return 10;
	case Rank::Jack:
		return 10;
	case Rank::Queen:
		return 10;
	case Rank::King:
		return 10;
	case Rank::Ace:
		return 11;
	}

	return -1;
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
	case Suit::Clubs:
		return "clubs";
	case Suit::Diamonds:
		return "diamonds";
	case Suit::Hearts:
		return "hearts";
	case Suit::Spades:
		return "spades";
	}

	return "";
}

const char* rankToStr(Rank r)
{
	switch (r)
	{
	case Rank::Two:
		return "2";
	case Rank::Three:
		return "3";
	case Rank::Four:
		return "4";
	case Rank::Five:
		return "5";
	case Rank::Six:
		return "6";
	case Rank::Seven:
		return "7";
	case Rank::Eight:
		return "8";
	case Rank::Nine:
		return "9";
	case Rank::Ten:
		return "10";
	case Rank::Jack:
		return "Jack";
	case Rank::Queen:
		return "Queen";
	case Rank::King:
		return "King";
	case Rank::Ace:
		return "Ace";
	}

	return "";
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

