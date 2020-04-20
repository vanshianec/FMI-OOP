#ifndef _PLAYER_CPP
#define _PLAYER_CPP

#include "Player.h"
#include <cstring>

Player::Player()
{
	name = nullptr;
	nameLength = 0;
	age = 18;
	newPlayer = true;
	wins = 0;
	gamesPlayed = 0;
	winPercentage = 0;
	currentPoints = 0;
}

Player::Player(const char* _name, const size_t _age)
{
	copyName(_name);
	age = _age;
	newPlayer = true;
	wins = 0;
	gamesPlayed = 0;
	winPercentage = 0;
	currentPoints = 0;
}

Player::Player(const Player& other)
{
	copyName(other.name);
	age = other.age;
	newPlayer = other.newPlayer;
	wins = other.wins;
	gamesPlayed = other.gamesPlayed;
	winPercentage = other.winPercentage;
	currentPoints = other.currentPoints;
}

Player& Player::operator=(const Player& other)
{
	if (this != &other)
	{
		if (name != nullptr)
		{
			delete[]name;
		}

		copyName(other.name);
		age = other.age;
		newPlayer = other.newPlayer;
		wins = other.wins;
		gamesPlayed = other.gamesPlayed;
		winPercentage = other.winPercentage;
		currentPoints = other.currentPoints;
	}

	return *this;
}

Player::~Player()
{
	delete[]name;
}

void Player::save(std::ofstream& outStream)
{
	outStream.write((char*)&nameLength, sizeof(nameLength));
	outStream.write(name, nameLength);
	outStream.write((char*)&age, sizeof(age));
	outStream.write((char*)&newPlayer, sizeof(newPlayer));
	outStream.write((char*)&wins, sizeof(wins));
	outStream.write((char*)&gamesPlayed, sizeof(gamesPlayed));
	outStream.write((char*)&winPercentage, sizeof(winPercentage));
	outStream.write((char*)&currentPoints, sizeof(currentPoints));
}

void Player::retrieve(std::ifstream& inStream)
{
	inStream.read((char*)&nameLength, sizeof(nameLength));
	if (name != nullptr)
	{
		delete[]name;
	}
	name = new char[nameLength + 1];
	inStream.read(name, nameLength);
	name[nameLength] = '\0';
	inStream.read((char*)&age, sizeof(age));
	inStream.read((char*)&newPlayer, sizeof(newPlayer));
	inStream.read((char*)&wins, sizeof(wins));
	inStream.read((char*)&gamesPlayed, sizeof(gamesPlayed));
	inStream.read((char*)&winPercentage, sizeof(winPercentage));
	inStream.read((char*)&currentPoints, sizeof(currentPoints));
}

const char* Player::getName() const
{
	return name;
}

const size_t Player::getAge() const
{
	return age;
}

const bool Player::isNewPlayer() const
{
	return newPlayer;
}

const size_t Player::getWins() const
{
	return wins;
}

const size_t Player::getGamesPlayed() const
{
	return gamesPlayed;
}

const double Player::getWinPercentage() const
{
	return winPercentage;
}

const size_t Player::getCurrentPoints() const
{
	return currentPoints;
}

void Player::setIsNewPlayer(const bool _newPlayer)
{
	newPlayer = _newPlayer;
}

void Player::setWinPercentage(const double newWinPercentage)
{
	winPercentage = newWinPercentage;
}

void Player::setWins(const size_t newWins)
{
	wins = newWins;
}

void Player::setGamesPlayed(const size_t newGamesPlayed)
{
	gamesPlayed = newGamesPlayed;
}

void Player::setCurrentPoints(const size_t newPoints)
{
	currentPoints = newPoints;
}

void Player::addPoints(const size_t points)
{
	currentPoints += points;
}

void Player::copyName(const char* _name)
{
	name = nullptr;
	nameLength = 0;

	if (_name != nullptr)
	{
		size_t len = strlen(_name);
		name = new char[len + 1];
		strcpy_s(name, len + 1, _name);
		nameLength = len;
	}
}

std::ostream& operator<<(std::ostream& out, const Player& player)
{
	out << player.getName() << " " << player.getGamesPlayed()
		<< " " << player.getWinPercentage() << std::endl;
	return out;
}

#endif