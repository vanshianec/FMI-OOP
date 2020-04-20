#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <fstream>

class Player
{
private:
	char* name;
	size_t nameLength;
	size_t age;
	bool newPlayer;
	size_t wins;
	size_t gamesPlayed;
	double winPercentage;
	size_t currentPoints;

public:
	Player();
	Player(const char* _name, const size_t _age);
	Player(const Player& other);
	Player& operator=(const Player& other);
	~Player();
	void save(std::ofstream& outStream);
	void retrieve(std::ifstream& inStream);
	const char* getName() const;
	const size_t getAge() const;
	const bool isNewPlayer() const;
	const size_t getWins() const;
	const size_t getGamesPlayed() const;
	const double getWinPercentage() const;
	const size_t getCurrentPoints() const;
	void setIsNewPlayer(const bool _newPlayer);
	void setWinPercentage(const double newWinPercentage);
	void setWins(const size_t newWins);
	void setGamesPlayed(const size_t newGamesPlayed);
	void setCurrentPoints(const size_t newPoints);
	void addPoints(const size_t points);

private:
	void copyName(const char* _name);
};

std::ostream& operator<<(std::ostream& out, const Player& player);

#endif 
