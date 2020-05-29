#ifndef __DATE_H
#define __DATE_H

#include <fstream>

/// @brief Date class used with 'YYYY-MM-DD' format

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(const int _year, const int _month, const int _day);
	Date(const char* dateFormat);
	const int getYear() const;
	const int getMonth() const;
	const int getDay() const;
	void setDate(const int _year, const int _month, const int _day);
	bool operator==(const Date& other) const;
	bool operator > (const Date& other) const;
	bool operator < (const Date& other) const;
	bool operator <= (const Date& other) const;
	bool operator >= (const Date& other) const;

private:
	/// @brief Checks if the passed parameters for the date are valid.
	bool isValidDate(const int _year, const int _month, const int _day) const;
	/// @brief Checks if the passed year is a leap year.
	bool isLeapYear(const int _year) const;
	/// @brief Checks if the passed date format is valid.
	bool isValidFormat(const char* dateFormat, const int length) const;
};

/// @brief Checks whether the next N characters are in the date format are numbers.
bool isNumber(const char* dateFormat, int &startIndex, const int length);
/// @brief Sets year, month and day parameters from a date format parameter.
void addValues(int &newYear, int &newMonth, int &newDay, const char* dateFormat);
/// @brief Converts a character to a number.
int num(char c);

/// @brief Outputs information about the date.
std::ostream& operator<<(std::ostream& out, const Date& date);

#endif