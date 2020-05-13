#ifndef _STRINGTRIMMER_H
#define _STRINGTRIMMER_H

#include <string>

class StringTrimmer
{
public:
	static std::string& ltrim(std::string& str, const std::string& chars);
	static std::string& rtrim(std::string& str, const std::string& chars);
	static std::string& trim(std::string& str);
};

#endif