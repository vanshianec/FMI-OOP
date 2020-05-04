#ifndef __FILEUTIL_CPP
#define __FILEUTIL_CPP

#include<fstream>

#include "FileUtil.h"

bool FileUtil::isEmpty(const std::string& path) const
{
	std::ifstream in(path);
	return in.peek() == std::ifstream::traits_type::eof();
}

bool FileUtil::open(const std::string& path)
{
	//TODO
	return true;
}

#endif