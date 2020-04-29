#ifndef __LAUNCHER_H
#define __LAUNCHER_H

#include "FileUtil.h"
#include "Storage.h"

class ApplicationLauncher
{

	//TODO IMPORTANT MAKE CONSOLE READER AND WRITER!!!
private:
	FileUtil fileManager;
	Storage storage;
	bool firstLaunch;
	std::string command;
	std::string path;
	void executeCommand();
	void saveDataInCurrentFile();
	void saveDataInAnotherFile();
	void closeCurrentFile();
	void listSupportedCommands();
	void openFile();
public:
	ApplicationLauncher();
	void run();
};

std::string& ltrim(std::string& str, const std::string& chars);
std::string& rtrim(std::string& str, const std::string& chars);
std::string& trim(std::string& str);

#endif
