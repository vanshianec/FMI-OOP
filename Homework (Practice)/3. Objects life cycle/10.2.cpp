
#include<iostream>
#include <cstring>

class NumbersSummator
{
private:
	double s;
	double changes;
	int changesCount;

public:
	NumbersSummator(double _sum)
	{
		s = _sum;
		changes = 0;
		changesCount = 0;
	}

	double sum()
	{
		return s;
	}

	void add(double num)
	{
		s += num;
		changesCount++;
		changes += num;
	}

	void sub(double num)
	{
		s -= num;
		changesCount++;
		changes -= num;
	}

	double average()
	{
		return changes / changesCount;
	}
};

int main()
{
	NumbersSummator seq1(10);
	seq1.add(10);
	seq1.add(5);
	seq1.sub(15);
	std::cout << seq1.sum() << std::endl; //−>10 (10+10+5−15)
	std::cout << seq1.average(); //−>0 (10+5−15)/3

	return 0;
}