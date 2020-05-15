#ifndef __FILEUTIL_CPP
#define __FILEUTIL_CPP

#include<fstream>

#include "FileUtil.h"

std::string FileUtil::path = "";

bool FileUtil::isEmpty()
{
	std::ifstream in(FileUtil::path);
	return in.peek() == std::ifstream::traits_type::eof();
}

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

const std::string FileUtil::fileName()
{
	if (path.find_first_of("\\") == std::string::npos)
	{
		return path;
	}

	return path.substr(path.find_last_of("\\") + 1);
}

#endif