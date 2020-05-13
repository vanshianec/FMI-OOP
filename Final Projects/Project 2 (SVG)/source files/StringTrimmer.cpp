#ifndef _STRINGTRIMMER_CPP
#define _STRINGTRIMMER_CPP

#include "StringTrimmer.h"

std::string& StringTrimmer::ltrim(std::string& str, const std::string& chars)
{
	str.erase(0, str.find_first_not_of(chars));
	return str;
}

std::string& StringTrimmer::rtrim(std::string& str, const std::string& chars)
{
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}

std::string& StringTrimmer::trim(std::string& str)
{
	const std::string chars = "\t\n\v\f\r ";
	return ltrim(rtrim(str, chars), chars);
}

#endif