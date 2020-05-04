#ifndef __FILEUTIL_H
#define __FILEUTIL_H

#include <string>

class FileUtil
{
public:
	bool isEmpty(const std::string& path) const;
	bool open(const std::string& path);

};

#endif