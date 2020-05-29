#ifndef __FILEUTIL_CPP
#define __FILEUTIL_CPP

#include<fstream>

#include "FileUtil.h"

/**
*   @brief Sets a static variable path, containing the file path of a file.
*/

std::string FileUtil::path = "";

/**
*   @brief Checks if the file is empty.
*
*	@return   True if the file is empty and false otherwise.
*/

bool FileUtil::isEmpty()
{
	std::ifstream in(FileUtil::path);
	return in.peek() == std::ifstream::traits_type::eof();
}

/**
*   @brief Checks if the file can be opened.
*
*	@return   True if the file was opened and false otherwise.
*/

bool FileUtil::open()
{
	std::ifstream in(path);
	if (in.is_open())
	{
		in.close();
		return true;
	}

	return false;
}

/**
*   @brief Extracts the name of the file from a file path.
*
*	@return  The name of the file.
*/

const std::string FileUtil::fileName()
{
	if (path.find_first_of("\\") == std::string::npos)
	{
		return path;
	}

	return path.substr(path.find_last_of("\\") + 1);
}

#endif