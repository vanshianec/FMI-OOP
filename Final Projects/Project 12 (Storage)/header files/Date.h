#ifndef __DATE_H
#define __DATE_H

class Date
{
private:
	int day;
	int month;
	int year;
	bool isValidDate(const int _year, const int _month, const int _day) const;
	bool isLeapYear(const int _year) const;
	bool isValidFormat(const char* dateFormat, const int length) const;
	void setDate(const int _year, const int _month, const int _day);
	int countLeapYears(const int _year, const int _month) const;
public:
	Date();
	Date(const int _year, const int _month, const int _day);
	Date(const char* dateFormat);
	const int getYear() const;
	const int getMonth() const;
	const int getDay() const;
	const int daysDifference(const Date& other) const;
	bool operator==(const Date& other) const;
	bool operator > (const Date& other) const;
};

std::ostream& operator<<(std::ostream& out, const Date& date);
bool isNumber(const char* dateFormat, int &startIndex, const int length);
void addValues(int &newYear, int &newMonth, int &newDay, const char* dateFormat);
int num(char c);

#endif