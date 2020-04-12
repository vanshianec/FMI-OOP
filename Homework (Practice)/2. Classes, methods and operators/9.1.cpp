#include<iostream>

class Time
{
private:
	int hour;
	int minute;

public:

	Time() : hour(0), minute(0) {}

	Time(int _hour, int _minute) : hour(0), minute(0)
	{
		setHour(_hour);
		setMinute(_minute);
	}

	Time(const Time& t)
	{
		hour = t.hour;
		minute = t.minute;
	}

	Time& operator = (const Time& t)
	{
		if (this != &t)
		{
			hour = t.hour;
			minute = t.minute;
		}

		return *this;
	}

	int getHour()
	{
		return hour;
	}

	int getMinute()
	{
		return minute;
	}

	void setHour(int _hour)
	{
		if (_hour < 0 || _hour > 23)
		{
			std::cout << "Invalid hour";
			return;
		}

		hour = _hour;
	}

	void setMinute(int _minute)
	{
		if (_minute < 0 || _minute > 59)
		{
			std::cout << "Invalid minute";
			return;
		}

		minute = _minute;
	}

	void addMinutes(int _minutes)
	{
		int totalMinutes = minute + _minutes;
		minute = (totalMinutes) % 60;
		hour = (hour + (totalMinutes / 60)) % 24;
	}

	int minutesPassedSinceMidnight()
	{
		return minute + (hour % 24 * 60);
	}

	bool operator < (Time& t)
	{
		return minutesPassedSinceMidnight() < t.minutesPassedSinceMidnight();
	}

	Time operator + (Time& t)
	{
		Time res;
		res.addMinutes(minutesPassedSinceMidnight() + t.minutesPassedSinceMidnight());
		return res;
	}

	Time operator * (int k)
	{
		Time res;
		res.addMinutes(minutesPassedSinceMidnight() * k);
		return res;
	}

	void printTime()
	{
		std::cout << "Hours : " << hour << " Minutes : " << minute << std::endl;
	}
};

Time operator * (int k, Time& t)
{
	Time res;
	res.addMinutes(t.minutesPassedSinceMidnight() * k);
	return res;
}

int main()
{
	Time t1(13, 34);
	Time t2(23, 59);
	Time t3;
	t1.printTime();
	t2.printTime();
	t3.printTime();
	(t1 + t2).printTime();
	(t2 + t1).printTime();
	t2.addMinutes(1);
	(t1 + t2).printTime();
	Time res = (t1 + t2) * 3;
	res.printTime();
	res = 1 * res;
	res.printTime();
}