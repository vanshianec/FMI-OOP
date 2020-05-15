#ifndef _DATETIME_CPP
#define _DATETIME_CPP

#include "DateTime.h"
#include <cstring>

void DateTime::currentDateISO8601(char* dateFormat)
{
	std::time_t rawtime;
	std::tm* timeinfo;
	char buffer[11];

	std::time(&rawtime);
	timeinfo = std::localtime(&rawtime);

	std::strftime(buffer, 11, "%Y-%m-%d", timeinfo);
	strcpy_s(dateFormat, 11, buffer);
}

#endif