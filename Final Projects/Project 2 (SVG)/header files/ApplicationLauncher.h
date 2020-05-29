#ifndef _APPLICATIONLAUNCHER_H
#define _APPLICATIONLAUNCHER_H

#include "ShapeStorage.h"

/// @brief Class used for combining all objects required to run the application.

class ApplicationLauncher
{
private:
	/// @brief Stores shapes loaded from a file and created by the user.
	ShapeStorage storage;
	/// @brief The current command entered by the user.
	std::string command;
	/// @brief Keeps the launch state of the application to ensure that proper user commands are used.
	bool firstLaunch;

public:
	ApplicationLauncher();

	/// @brief Enables the user to start using the application.
	void run();

private:
	/// @brief Executes the command entered by the user.
	void executeCommand();
	/// @brief Opens an XML file from the path specified by the user.
	void openFile();
	/// @brief Saves the changes made by the user in the currently opened file.
	void saveDataInCurrentFile();
	/// @brief Saves the changes made by the user in a new file specified by the user.
	void saveDataInAnotherFile();
	/// @brief Reverts all changes made by the user.
	void clearData();
	/// @brief Displays all command supported by the application.
	void listSupportedCommands();
	/// @brief Prints all currently available shapes.
	void printShapes();
	/// @brief Creates a new shape specified by the user.
	void createShape();
	/// @brief Removes a shape specified by the user.
	void eraseShape();
	/// @brief Translates all shapes or a specified shape.
	void translateShape();
	/// @brief Prints all shapes within a surface.
	void withinSurface();

};

#endif