#ifndef _APPLICATIONLAUNCHER_H
#define _APPLICATIONLAUNCHER_H

#include "ShapeStorage.h"

class ApplicationLauncher
{
private:
	ShapeStorage storage;
	std::string command;
	bool firstLaunch;

public:
	ApplicationLauncher();
	void run();

private:
	void executeCommand();
	void saveDataInCurrentFile();
	void saveDataInAnotherFile();
	void listSupportedCommands();
	void translateShape();
	void withinSurface();
	void clearData();
	void openFile();
	void createShape();
	void eraseShape();
	void printShapes();

};

#endif