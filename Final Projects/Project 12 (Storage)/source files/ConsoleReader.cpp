#ifndef _CONSOLEREADER_CPP
#define _CONSOLEREADER_CPP

#include "ConsoleReader.h"
#include "StringTrimmer.h"
#include <sstream>
#include <iostream>

const std::vector<std::string> ConsoleReader::readParams(const char delimeter)
{
	std::string input;
	std::getline(std::cin, input);

	std::stringstream ss(input);
	std::vector<std::string> params;

	while (ss.good())
	{
		std::string substr;
		getline(ss, substr, delimeter);
		StringTrimmer::trim(substr);
		params.push_back(substr);
	}

	return params;
}

#endif