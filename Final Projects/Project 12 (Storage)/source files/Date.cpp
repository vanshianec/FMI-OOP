#ifndef __DATE_CPP
#define __DATE_CPP

#include <cstring>
#include <cmath>
#include <iostream>

#include "Date.h"

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
		return _month <= 31;
	}

	return _month <= 30;
}

bool Date::isLeapYear(const int _year) const
{
	return ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0);
}

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

void Date::setDate(const int _year, const int _month, const int _day)
{
	if (!isValidDate(_year, _month, _day))
	{
		throw 1;
	}

	year = _year;
	month = _month;
	day = _day;
}

int Date::countLeapYears(const int _year, const int _month) const
{
	int resultYear = _year;

	if (_month <= 2)
	{
		resultYear--;
	}

	return resultYear / 4 - resultYear / 100 + resultYear / 400;
}

Date::Date() : year(1900), month(1), day(1) {}

Date::Date(const int _year, const int _month, const int _day) : year(1900), month(1), day(1)
{
	setDate(_year, _month, _day);
}

Date::Date(const char* dateFormat) : year(1900), month(1), day(1)
{
	if (!isValidFormat(dateFormat, strlen(dateFormat)))
	{
		throw 1;
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

const int Date::daysDifference(const Date& other) const
{
	int totalDays = 0, otherTotalDays = 0;
	const int monthDays[12] = { 31, 28, 31, 30, 31, 30,
								31, 31, 30, 31, 30, 31 };

	totalDays += year * 365 + day;

	for (int i = 0; i < month - 1; i++)
	{
		totalDays += monthDays[i];
	}

	totalDays += countLeapYears(year, month);

	otherTotalDays += other.year * 365 + other.day;

	for (int i = 0; i < other.month - 1; i++)
	{
		otherTotalDays += monthDays[i];
	}

	otherTotalDays += countLeapYears(other.year, other.month);

	return abs(totalDays - otherTotalDays);
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

int num(char c)
{
	return (c - '0');
}

#endif