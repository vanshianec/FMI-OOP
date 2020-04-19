
#include<iostream>
#include <cstring>

class HistoryEntry
{
private:
	int month;
	char url[100];

public:
	HistoryEntry()
	{
		month = 1;
		url[0] = '\0';
	}

	HistoryEntry(const int _month, const char* _url)
	{
		month = _month;
		strcpy_s(url, strlen(_url) + 1, _url);
	}

	int getMonth()
	{
		return month;
	}

	void print()
	{
		std::cout << "Month : " << month << " url : " << url << std::endl;
	}
};

class BrowserHistory
{
private:
	int count;
	size_t n;
	HistoryEntry* story;
	void setParams(const BrowserHistory& other)
	{
		count = other.count;
		n = other.n;
		delete[]story;
		story = new HistoryEntry[n];
		for (int i = 0; i < n; i++)
		{
			story[i] = other.story[i];
		}
	}
public:
	BrowserHistory(size_t _n)
	{
		count = 0;
		n = _n;
		story = new HistoryEntry[n];
	}

	BrowserHistory(const BrowserHistory& other)
	{
		setParams(other);
	}

	BrowserHistory& operator = (const BrowserHistory& other)
	{
		if (this != &other)
		{
			setParams(other);
		}

		return *this;
	}

	~BrowserHistory()
	{
		delete[]story;
	}

	void add()
	{
		if (count == n)
		{
			return;
		}

		int month;
		char url[100];
		std::cin >> month >> url;
		story[count++] = HistoryEntry(month, url);
	}

	void operator +=(const HistoryEntry& entry)
	{
		if (count == n)
		{
			return;
		}

		story[count++] = entry;
	}

	void printHistory()
	{
		for (int i = 0; i < count; i++)
		{
			story[i].print();
		}
	}

	int searchesInMonth(int month)
	{
		if (month < 1 || month > 12)
		{
			return -1;
		}

		int c = 0;

		for (int i = 0; i < count; i++)
		{
			if (story[i].getMonth() == month)
			{
				c++;
			}
		}

		return c;
	}

	int monthWithMostSearches()
	{
		int bestCount = 0;
		int bestMonth = 1;
		int currentSearches;

		for (int i = 1; i <= 12; i++)
		{
			currentSearches = searchesInMonth(i);
			if (currentSearches > bestCount)
			{
				bestMonth = i;
				bestCount = currentSearches;
			}
		}

		return bestMonth;
	}

	void removeMostRecentSearch()
	{
		if (count <= 0)
		{
			return;
		}

		count--;
		story[count] = HistoryEntry();
	}

	BrowserHistory operator+(const BrowserHistory& other)
	{
		BrowserHistory result(count + other.count);
		for (int i = 0; i < count; i++)
		{
			result += (story[i]);
		}

		for (int j = 0; j < other.count; j++)
		{
			result += (other.story[j]);
		}

		return result;
	}

	BrowserHistory& operator+=(const BrowserHistory& other)
	{
		int newN = n + other.n;
		int newCount = count + other.count;

		HistoryEntry* newStory = new HistoryEntry[newN];

		for (int i = 0; i < count; i++)
		{
			newStory[i] = story[i];
		}

		for (int i = count; i < count + other.count; i++)
		{
			newStory[i] = other.story[i - count];
		}

		delete[]story;
		story = newStory;
		count = newCount;
		n = newN;

		return *this;
	}

};

int main()
{
	BrowserHistory h1(10);
	h1.add();
	h1.add();
	h1.printHistory();
	h1.removeMostRecentSearch();
	h1.printHistory();

	BrowserHistory h2(5);
	h2 += HistoryEntry(1, "facebook.com");
	h2 += HistoryEntry(1, "youtube.com");
	h2 += HistoryEntry(1, "stackoverflow.com");
	h2 += HistoryEntry(12, "github.com");

	BrowserHistory h3 = h1 + h2;
	std::cout << h3.monthWithMostSearches() << std::endl;
	h3.printHistory();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	BrowserHistory h4 = h3;

	h3 += h3;
	h3.printHistory();

	return 0;
}