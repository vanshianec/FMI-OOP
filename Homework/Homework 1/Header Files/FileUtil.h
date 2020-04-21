#ifndef _FILEUTIL_H
#define _FILEUTIL_H

#include "Player.cpp"

class FileUtil
{
private:
	const char* FILE_NAME = "players.dat";
	const char* NEW_FILE_NAME = "playersCopy.dat";

	std::ifstream inStream;
	std::ofstream outStream;

public:
	void printPlayers();
	bool choosePlayer(Player& player, const char* name);
	void updatePlayerData(Player& player);
	void addPlayer(Player& player);
};

#endif