#ifndef _CONSOLEREADER_H
#define _CONSOLEREADER_H

#include <vector>
#include <string>

class ConsoleReader
{
public:
	static const std::vector<std::string> readParams(const char delimeter);
};

#endif