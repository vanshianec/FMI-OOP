#ifndef _CONSOLEREADER_H
#define _CONSOLEREADER_H

#include <vector>
#include <string>

/// @brief Class used to read user input from the console.

class ConsoleReader
{
public:
	/// @brief Reads a string and splits it by a character delimeter .
	static const std::vector<std::string> readParams(const char delimeter);
};

#endif