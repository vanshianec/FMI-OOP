#ifndef __DATE_H
#define __DATE_H

#include <fstream>

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
	bool isValidDate(const int _year, const int _month, const int _day) const;
	bool isLeapYear(const int _year) const;
	bool isValidFormat(const char* dateFormat, const int length) const;
	int countLeapYears(const int _year, const int _month) const;
};

bool isNumber(const char* dateFormat, int &startIndex, const int length);
void addValues(int &newYear, int &newMonth, int &newDay, const char* dateFormat);
int num(char c);

std::ostream& operator<<(std::ostream& out, const Date& date);

#endif