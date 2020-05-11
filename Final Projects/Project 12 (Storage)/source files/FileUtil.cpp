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

#endif