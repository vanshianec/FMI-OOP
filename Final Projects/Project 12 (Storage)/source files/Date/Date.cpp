#ifndef __DATE_CPP
#define __DATE_CPP

#include <cstring>
#include <cmath>
#include <iostream>
#include "InvalidParameterException.h"

#include "Date.h"

/**
*   @brief Checks if the passed parameters for the date are valid.
*
*   @param _year The year parameter which should be between 1900 and 9999 inclusive.
*
*   @param _month The month parameter which should be between 1 and 12 inclusive.
*
*   @param _dat The day parameter which value is dependent of the month and year values inclusive.
*
*	@return Returns true if the parameters are valid and false otherwise.
*/

bool Date::isValidDate(const int _year, const int _month, const int _day) const
{
	if (_day <= 0 || _month <= 0 || _year < 1900 || _year > 9999 || _month > 12)
	{
		return false;
	}

	if (_month == 2)
	{
		return _day <= (isLeapYear(_year) ? 29 : 28);
	}
	else if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12)
	{
		return _day <= 31;
	}

	return _day <= 30;
}

/**
*   @brief Checks if the passed year is a leap year.
*
*   @param _year The year which will be checked if it is leap year or not.
*
*	@return Returns true if the year is a leap year and false otherwise.
*/

bool Date::isLeapYear(const int _year) const
{
	return ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0);
}

/**
*   @brief Checks if the passed date format is valid.
*
*   @param dateFormat The date format which will be checked if it is valid.
*
*   @param length The length of the date format.
*
*	@return Returns true if the date format is valid and false otherwise.
*/

bool Date::isValidFormat(const char* dateFormat, const int length) const
{
	//example : 2020-04-07
	if (length != 10 || dateFormat[0] == '0')
	{
		return false;
	}

	int index = 0;

	if (!isNumber(dateFormat, index, 4))
	{
		return false;
	}

	if (dateFormat[index++] != '-')
	{
		return false;
	}

	if (!isNumber(dateFormat, index, index + 2))
	{
		return false;
	}

	if (dateFormat[index++] != '-')
	{
		return false;
	}

	if (!isNumber(dateFormat, index, index + 2))
	{
		return false;
	}

	return true;
}

/**
*	@warning Throws InvalidParameterException if the passed date parameters are invalid.
*/

void Date::setDate(const int _year, const int _month, const int _day)
{
	if (!isValidDate(_year, _month, _day))
	{
		throw InvalidParameterException("Invalid date format! Supported date format is YYYY-MM-DD");
	}

	year = _year;
	month = _month;
	day = _day;
}

Date::Date() : year(1900), month(1), day(1) {}

Date::Date(const int _year, const int _month, const int _day) : year(1900), month(1), day(1)
{
	setDate(_year, _month, _day);
}

/**
*	@warning Throws InvalidParameterException if the passed date parameters are invalid.
*/

Date::Date(const char* dateFormat) : year(1900), month(1), day(1)
{
	if (!isValidFormat(dateFormat, strlen(dateFormat)))
	{
		throw InvalidParameterException("Invalid date format! Supported date format is YYYY-MM-DD");
	}

	int _year = 0;
	int _month = 0;
	int _day = 0;

	addValues(_year, _month, _day, dateFormat);
	setDate(_year, _month, _day);
}

const int Date::getYear() const
{
	return year;
}

const int Date::getMonth() const
{
	return month;
}

const int Date::getDay() const
{
	return day;
}

bool Date::operator==(const Date& other) const
{
	return day == other.day && month == other.month && year == other.year;
}

bool Date::operator > (const Date& other) const
{
	if (year > other.year)
	{
		return true;
	}
	else if (year == other.year && month > other.month)
	{
		return true;
	}
	else if (month == other.month && day > other.day)
	{
		return true;
	}

	return false;
}

bool Date::operator < (const Date& other) const
{
	return !operator==(other) && !operator>(other);
}

bool Date::operator <= (const Date& other) const
{
	return operator==(other) || operator<(other);
}

bool Date::operator >= (const Date& other) const
{
	return operator==(other) || operator>(other);
}

/**
*   @brief Outputs information about the date.
*
*   @param out The output stream which will take the date information.
*
*   @param date The date object to be passed to the output stream.
*/

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << "\"" << date.getYear() << "-";
	if (date.getMonth() <= 9)
	{
		out << "0";
	}
	out << date.getMonth() << "-";
	if (date.getDay() <= 9)
	{
		out << "0";
	}
	out << date.getDay() << "\"";
	return out;
}

/**
*   @brief Checks whether the next N characters are in the date format are numbers.
*
*   @param dateFormat The date format which should contain numbers and dashes only.
*
*   @param startIndex The the index from which the check will begin.
*
*   @param length The number of characters to be checked.
*
*	@return Returns true if the next N characters are numbers and false otherwise.
*/

bool isNumber(const char* dateFormat, int& startIndex, const int length)
{
	while (startIndex < length)
	{
		if (dateFormat[startIndex] < '0' && dateFormat[startIndex] > '9')
		{
			return false;
		}
		startIndex++;
	}

	return true;
}

/**
*   @brief Sets year, month and day parameters from a date format parameter.
*
*/

void addValues(int& _year, int& _month, int& _day, const char* dateFormat)
{
	// example date format : 2020-04-07

	int yearLen = 4;

	for (int i = 0; i < yearLen; i++)
	{
		_year += pow(10, yearLen - i - 1) * num(dateFormat[i]);
	}

	if (dateFormat[5] == '0')
	{
		_month = num(dateFormat[6]);
	}
	else
	{
		_month = 10 * num(dateFormat[5]) + num(dateFormat[6]);
	}

	if (dateFormat[8] == '0')
	{
		_day = num(dateFormat[9]);
	}
	else
	{
		_day = 10 * num(dateFormat[8]) + num(dateFormat[9]);
	}
}

/**
*   @brief Converts a character to a number.
*
*   @param c The character to be converted.
*
*	@return Returns the converted character as a number.
*/

int num(char c)
{
	return (c - '0');
}

#endif