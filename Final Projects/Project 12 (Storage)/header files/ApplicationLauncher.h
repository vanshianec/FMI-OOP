#ifndef __LAUNCHER_H
#define __LAUNCHER_H

#include "Storage.h"

class ApplicationLauncher
{

private:
	Storage storage;
	bool firstLaunch;
	std::string command;

public:
	ApplicationLauncher();
	void run();

private:
	void executeCommand();
	void saveDataInCurrentFile();
	void saveDataInAnotherFile();
	void clearData();
	void listSupportedCommands();
	void printAvailableProducts();
	void logStorageChanges();
	void cleanStorage();
	void addProduct();
	void removeProduct();
	void createNewStorage();
	void openFile();
};

#endif
