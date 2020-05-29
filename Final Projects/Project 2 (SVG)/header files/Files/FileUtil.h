#ifndef __FILEUTIL_H
#define __FILEUTIL_H

#include <string>

/// @brief Utility class used for file path management.

class FileUtil
{
public:
	///@brief The path of the file.
	static std::string path;
	///@brief Checks if the file is empty.
	static bool isEmpty();
	///@brief Checks if the file can be opened.
	static bool open();
	///@brief Extracts the file name from the file path.
	static const std::string fileName();
};

#endif