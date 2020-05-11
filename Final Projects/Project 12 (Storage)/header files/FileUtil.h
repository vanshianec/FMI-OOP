#ifndef __FILEUTIL_H
#define __FILEUTIL_H

#include <string>

class FileUtil
{
public:
	static std::string path;
	static bool isEmpty();
	static bool open();
};

#endif