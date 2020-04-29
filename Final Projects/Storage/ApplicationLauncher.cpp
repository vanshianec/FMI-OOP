#ifndef __DATE_CPP
#define __DATE_CPP

#include<iostream>
#include<fstream>

#include "ApplicationLauncher.h"

//todo see without class init
ApplicationLauncher::ApplicationLauncher() : fileManager(), storage(), firstLaunch(true), command(), path() {}

void ApplicationLauncher::executeCommand()
{
	if (!firstLaunch)
	{
		if (command == SAVE_COMMAND)
		{
			saveDataInCurrentFile();
		}
		else if (command == SAVE_AS_COMMAND)
		{
			saveDataInAnotherFile();
		}
		else if (command == CLOSE_COMMAND)
		{
			closeCurrentFile();
		}
		else if (command == HELP_COMMAND)
		{
			listSupportedCommands();
		}
	}
	else if (command == OPEN_COMMAND)
	{
		openFile();
	}
	else
	{
		std::cout << USER_ALERT_MESSAGE;
	}
}

void ApplicationLauncher::saveDataInCurrentFile()
{
	fileManager.save(storage.getDataInTextFormat());
}

void ApplicationLauncher::saveDataInAnotherFile()
{
	std::getline(std::cin, path);
	trim(path);
	bool saved = fileManager.saveAs(storage.getDataInTextFormat(), path);
}

void ApplicationLauncher::closeCurrentFile()
{
	//TODO !!!clear storage data
	fileManager.close();
	firstLaunch = true;
}

void ApplicationLauncher::listSupportedCommands()
{
	std::cout << "TODO HELP COMMANDS";
}

void ApplicationLauncher::openFile()
{
	std::getline(std::cin, path);
	trim(path);
	if (fileManager.open(path))
	{
		//storage.init(fileManager.getFileContent());

		firstLaunch = false;
	}
}

std::string& ltrim(std::string& str, const std::string& chars)
{
	str.erase(0, str.find_first_not_of(chars));
	return str;
}

std::string& rtrim(std::string& str, const std::string& chars)
{
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}

std::string& trim(std::string& str)
{
	const std::string chars = "\t\n\v\f\r ";
	return ltrim(rtrim(str, chars), chars);
}

void ApplicationLauncher::run()
{
	std::cout << USER_ALERT_MESSAGE;
	std::cin >> command;

	while (command != EXIT_COMMAND)
	{
		executeCommand();
		std::cin >> command;
	}
}

#endif