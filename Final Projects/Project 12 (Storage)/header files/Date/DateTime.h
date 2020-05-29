#ifndef _DATETIME_H
#define _DATETIME_H

#include <cstdio>
#include <ctime>

/// @brief Class used to get the current date.

class DateTime
{
public:
	/// @brief Loads the current date in 'YYYY-MM-DD' text format.
	static void currentDateISO8601(char* dateFormat);
};

#endif