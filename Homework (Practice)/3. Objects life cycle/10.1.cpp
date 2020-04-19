
#include<iostream>
#include <cstring>

class Word
{
private:
	char str[21];
	size_t size;
public:
	Word()
	{
		str[0] = '\0';
		size = 0;
	}

	char operator [](int index)
	{
		if (index < 0 || index >= size)
		{
			std::cout << "Index out of range!" << std::endl;
			return '\0';
		}

		return str[index];
	}

	void operator +(char c)
	{
		if (size == 20)
		{
			std::cout << "Max capacity reached!" << std::endl;
			return;
		}

		str[size++] = c;
	}

	void operator +=(char c)
	{
		operator+(c);
	}

	bool operator < (const Word& other)
	{
		return strcmp(str, other.str) == 1;
	}

	bool operator == (const Word& other)
	{
		return strcmp(str, other.str) == 0;
	}
};

int main()
{

	Word w1;
	w1 += 'a';
	w1 += 'b';

	Word w2;
	w2 += 'a';
	w2 += 'b';

	std::cout << (w1 == w2) << std::endl;

	w2 += 'c';

	std::cout << (w1 < w2) << std::endl;

	std::cout << w1[0] << std::endl;
	std::cout << w2[0] << std::endl;
	std::cout << w2[2] << std::endl;

	return 0;
}