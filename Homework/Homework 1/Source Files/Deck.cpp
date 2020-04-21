#ifndef _DECK_CPP
#define _DECK_CPP

#include "Deck.h"
#include <ctime>

Deck::Deck() : deckSize(52), drawnCards(0)
{
	cards = new Card[deckSize];
	copySeries("Default");
	addCards(deckSize);
	shuffleCards();
}

Deck::Deck(const size_t k, const char* _series) : deckSize(k), drawnCards(0)
{
	cards = new Card[k];

	if (strlen(_series) != 0)
	{
		copySeries(_series);
	}
	else
	{
		copySeries("Custom");
	}

	addCards(k);
	shuffleCards();
}

Deck::Deck(const Deck& other) : deckSize(other.deckSize), drawnCards(other.drawnCards)
{
	copyCards(other.cards, other.deckSize);
	copySeries(other.series);
}

Deck& Deck::operator=(const Deck& other)
{
	if (this != &other)
	{
		delete[]cards;
		deckSize = other.deckSize;
		drawnCards = other.drawnCards;
		copyCards(other.cards, deckSize);
		copySeries(other.series);
	}

	return *this;
}

Deck::~Deck()
{
	delete[]cards;
}

Card Deck::draw()
{
	Card top = cards[deckSize - 1];
	for (int i = deckSize - 1; i >= 1; i--)
	{
		cards[i] = cards[i - 1];
	}

	cards[0] = top;
	drawnCards++;
	return top;
}

void Deck::swap(const size_t firstNum, const size_t secondNum)
{
	if (firstNum > 0 && secondNum > 0 && firstNum <= deckSize && secondNum <= deckSize)
	{
		swapCards(firstNum - 1, secondNum - 1);
	}
}

size_t Deck::suitCount(const Suit suit) const
{
	size_t count = 0;
	for (size_t i = 0; i < deckSize; i++)
	{
		if (cards[i].getSuit() == suit)
		{
			count++;
		}
	}

	return count;
}

size_t Deck::rankCount(const Rank rank) const
{
	size_t count = 0;
	for (size_t i = drawnCards; i < deckSize; i++)
	{
		if (cards[i].getRank() == rank)
		{
			count++;
		}
	}

	return count;
}

double Deck::probabilityToWin(const size_t currentPoints) const
{
	size_t requiredPoints = 21 - currentPoints;

	if (requiredPoints > 11)
	{
		return 0;
	}

	size_t occurences = 0;

	for (size_t i = drawnCards; i < deckSize; i++)
	{
		if (requiredPoints == 1 && cards[i].getRank() == Rank::Ace)
		{
			occurences++;
		}
		else if (cards[i].getPoints() == requiredPoints)
		{
			occurences++;
		}
	}

	return (occurences) / ((double)(deckSize)-drawnCards);
}

void Deck::copySeries(const char* _series)
{
	size_t len = strlen(_series);
	strcpy_s(series, len + 1, _series);
}

void Deck::copyCards(const Card* otherCards, const size_t size)
{
	cards = new Card[size];
	for (size_t i = 0; i < size; i++)
	{
		cards[i] = otherCards[i];
	}
}

void Deck::addCards(const size_t k)
{
	size_t index = 0;
	int cyclesCount = (k - 1) / 52;
	size_t len = 52;

	for (size_t cycle = 0; cycle <= cyclesCount; cycle++)
	{
		if (cycle == cyclesCount && k % 52 != 0)
		{
			len = k % 52;
		}
		for (size_t i = 0; i < len; i++)
		{
			char serialNumber[16];
			generateUniqueSerialNumber(serialNumber, index);
			cards[index++] = Card(static_cast<Suit>(i % 4), static_cast<Rank>(i / 4), serialNumber);
		}
	}
}

void Deck::generateUniqueSerialNumber(char* serialNumber, size_t id)
{
	strcpy_s(serialNumber, 16, series);
	size_t seriesLen = strlen(series);
	while (id > 9)
	{
		serialNumber[seriesLen++] = (id % 10 + '0');
		id /= 10;
	}

	serialNumber[seriesLen] = id + '0';
	serialNumber[seriesLen + 1] = '\0';
}

void Deck::shuffleCards()
{
	srand(time(NULL));
	size_t randomIndex = 0;
	for (size_t i = 1; i < deckSize; i++)
	{
		swapCards(randomIndex, i);
		randomIndex = rand() % deckSize;
	}
}

void Deck::swapCards(const size_t firstIndex, const size_t secondIndex)
{
	Card temp = cards[firstIndex];
	cards[firstIndex] = cards[secondIndex];
	cards[secondIndex] = temp;
}

#endif