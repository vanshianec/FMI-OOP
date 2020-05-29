#ifndef _STRINGTRIMMER_H
#define _STRINGTRIMMER_H

#include <string>

/// @brief Class used to trim characters from a string.

class StringTrimmer
{

public:
	/// @brief Removes leading characters from a specified string.
	static std::string& ltrim(std::string& str, const std::string& chars);
	/// @brief Removes trailing characters from a specified string.
	static std::string& rtrim(std::string& str, const std::string& chars);
	/// @brief Removes trailing and leading characters from a specified string.
	static std::string& trim(std::string& str);
};

#endif