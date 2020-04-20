#ifndef _FILEUTIL_CPP
#define _FILEUTIL_CPP

#include "FileUtil.h"

void FileUtil::printPlayers()
{
	inStream.open(FILE_NAME, std::ios::binary | std::ios::in);

	Player p;
	p.retrieve(inStream);

	while (inStream)
	{
		std::cout << p;
		p.retrieve(inStream);
	}

	inStream.close();
}

bool FileUtil::choosePlayer(Player& player, const char* name)
{
	Player p;
	inStream.open(FILE_NAME, std::ios::binary | std::ios::in);
	p.retrieve(inStream);
	while (inStream)
	{
		if (strcmp(name, p.getName()) == 0)
		{
			player = p;
			player.setIsNewPlayer(false);
			inStream.close();
			return true;
		}
		p.retrieve(inStream);
	}

	inStream.close();
	return false;
}

void FileUtil::updatePlayerData(Player& player)
{
	inStream.open(FILE_NAME, std::ios::binary | std::ios::in);
	outStream.open(NEW_FILE_NAME, std::ios::binary | std::ios::out);
	Player p;
	p.retrieve(inStream);
	while (inStream)
	{
		if (strcmp(player.getName(), p.getName()) == 0)
		{
			player.save(outStream);
		}
		else
		{
			p.save(outStream);
		}
		p.retrieve(inStream);
	}

	inStream.close();
	outStream.close();

	std::remove(FILE_NAME);
	std::rename(NEW_FILE_NAME, FILE_NAME);
	std::cout << "All changes are saved successfully in the file!\n";
}

void FileUtil::addPlayer(Player& player)
{
	outStream.open(FILE_NAME, std::ios::binary | std::ios::out | std::ios::app);
	player.save(outStream);
	outStream.close();
	std::cout << "All changes are saved successfully in the file!\n";
}

#endif