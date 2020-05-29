#ifndef __LAUNCHER_H
#define __LAUNCHER_H

#include "Storage.h"

/// @brief Class used for combining all objects required to run the application.

class ApplicationLauncher
{

private:
	/// @brief Stores products loaded from a file and created by the user.
	Storage storage;
	/// @brief The current command entered by the user.
	std::string command;
	///  @brief Keeps the launch state of the application to ensure that proper user commands are used.
	bool firstLaunch;

public:
	ApplicationLauncher();
	/// @brief Enables the user to start using the application.
	void run();

private:
	/// @brief Executes the command entered by the user.
	void executeCommand();
	/// @brief Opens a binary file from the path specified by the user.
	void openFile();
	/// @brief Saves the changes made by the user in the currently opened file.
	void saveDataInCurrentFile();
	/// @brief Saves the changes made by the user in a new file specified by the user.
	void saveDataInAnotherFile();
	/// @brief Reverts all changes made by the user.
	void clearData();
	/// @brief Displays all command supported by the application.
	void listSupportedCommands();
	/// @brief Prints all products which are present in the storage.
	void printAvailableProducts();
	/// @brief Creates a new product specified by the user.
	void addProduct();
	/// @brief Removes a product specified by the user.
	void removeProduct();
	/// @brief Prints all changes made in the storage between two dates specified by the user.
	void logStorageChanges();
	/// @brief Removes all products from the storage which are about to expire or are already expired.
	void cleanStorage();
	/// @brief Creates a new storage when empty file is specified by the user.
	void createNewStorage();
};

#endif
