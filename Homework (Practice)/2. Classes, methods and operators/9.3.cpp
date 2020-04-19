
#include<iostream>
#include <cstring>
#include <algorithm>

class Pair
{
private:
	char keyWord[101];
	char value[501];
public:
	Pair()
	{
		keyWord[0] = '\0';
		value[0] = '\0';
	}

	Pair(const char* _keyWord, const char* _value)
	{
		strcpy_s(keyWord, strlen(_keyWord) + 1, _keyWord);
		strcpy_s(value, strlen(_value) + 1, _value);
	}

	bool containsKey(const char* key)
	{
		return strcmp(keyWord, key) == 0;
	}

	const char* getKeyWord() const
	{
		return keyWord;
	}

	const char* getValue() const
	{
		return value;
	}

	void printPair()
	{
		std::cout << keyWord << " <-> " << value << std::endl;
	}
};

class Dictionary
{
private:
	Pair pairs[500];
	size_t size;
	void deleteWord(const int index)
	{
		for (int i = index + 1; i < size; i++)
		{
			pairs[i - 1] = pairs[i];
		}

		pairs[size - 1] = Pair();
		size--;
	}

	bool containsKey(const char* key)
	{
		for (int i = 0; i < size; i++)
		{
			if (pairs[i].containsKey(key))
			{
				return true;
			}
		}

		return false;
	}

	void addDuplicates(Pair& current, const Dictionary& other, Dictionary& result)
	{
		for (int i = 0; i < size; i++)
		{
			current = pairs[i];
			for (int j = 0; j < other.size; j++)
			{
				if (current.containsKey(other.pairs[j].getKeyWord()))
				{
					char newValue[200];
					concatValues(newValue, current.getValue(), other.pairs[j].getValue());
					result.add(Pair(current.getKeyWord(), newValue));
				}
			}
		}
	}

public:

	Dictionary()
	{
		size = 0;
	}

	void add(const Pair& pair)
	{
		if (size == 500)
		{
			std::cout << "Dictionary is full!" << std::endl;
			return;
		}

		pairs[size++] = pair;
	}

	void remove(const char* keyWord)
	{
		for (int i = 0; i < size; i++)
		{
			if (pairs[i].containsKey(keyWord))
			{
				deleteWord(i);
				std::cout << "Deleted " << keyWord << std::endl;
				i--;
			}
		}
	}

	const char* getValue(const char* keyWord)
	{
		for (int i = 0; i < size; i++)
		{
			if (pairs[i].containsKey(keyWord))
			{
				return pairs[i].getValue();
			}
		}

		std::cout << "Dictionary does not contain " << keyWord << std::endl;
		return "";
	}

	void printPairs()
	{
		for (int i = 0; i < size; i++)
		{
			pairs[i].printPair();
		}
	}

	void printInAscendingOrder()
	{
		Pair sorted[500];

		for (int i = 0; i < size; i++)
		{
			sorted[i] = pairs[i];
		}

		Pair current;

		for (int i = 1; i < size; i++)
		{
			current = pairs[i];
			int j = i;
			while (--j >= 0 && strcmp(pairs[j].getKeyWord(), current.getKeyWord()) == 1)
			{
				sorted[j + 1] = sorted[j];
			}
			sorted[j + 1] = current;
		}

		for (int i = 0; i < size; i++)
		{
			sorted[i].printPair();
		}
	}

	void concatValues(char* value, const char* first, const char* second)
	{
		int len = strlen(first);
		strcpy_s(value, len + 1, first);
		strcat_s(value, len + strlen(second) + 1, second);
	}

	Dictionary operator+(const Dictionary& other)
	{
		Dictionary result;
		Pair current;

		addDuplicates(current, other, result);

		for (int i = 0; i < size; i++)
		{
			if (!result.containsKey(pairs[i].getKeyWord()))
			{
				result.add(pairs[i]);
			}
		}

		int index = 0;
		while (result.size <= 500 && index < other.size)
		{
			if (!result.containsKey(other.pairs[index].getKeyWord()))
			{
				result.add(other.pairs[index]);
			}

			index++;
		}

		return result;
	}

};

int main()
{
	Dictionary d;
	d.add(Pair("car", "a vehicle used by people to travel long distances in short amount of time"));
	d.add(Pair("pen", "an object used to write ink on paper"));
	d.add(Pair("pen", "an object used to write ink on paper"));
	d.add(Pair("pen", "an object used to write ink on paper"));
	d.add(Pair("pen", "an object used to write ink on paper"));
	d.add(Pair("elbow", "a joint in the human body which connects the forearm and the upper arm"));
	d.add(Pair("apple", "a fruit"));
	d.printPairs();
	d.printInAscendingOrder();
	d.remove("pen");
	d.printPairs();
	std::cout << d.getValue("elbow") << std::endl;

	Dictionary d2;
	d2.add(Pair("car", " carururur"));
	d2.add(Pair("pen", " pennenen"));
	d2.add(Pair("elbow", " elbowrruuu"));
	d2.add(Pair("apple", " appllekjr"));
	d2.add(Pair("t1", " 1"));
	d2.add(Pair("t2", " 2"));
	d2.add(Pair("t3", " 3"));
	d2.add(Pair("t4", " 4"));
	d2.add(Pair("t5", " 5"));
	d2.add(Pair("t6", " 6"));

	Dictionary d3 = d + d2;
	d3.printPairs();
	return 0;
}