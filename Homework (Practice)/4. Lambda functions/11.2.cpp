
#include<iostream>

struct S
{
	int a;
	int b;
	int c;
};

void map(S* arr, void(*f)(S&), size_t len)
{
	for (int i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}

void printSum(S& s)
{
	std::cout << s.a + s.b + s.c << std::endl;
}

void readInput(S& s)
{
	std::cin >> s.a >> s.b >> s.c;
}

void increaseByOne(S& s)
{
	s.a++;
	s.b++;
	s.c++;
}

void swapElements(S& s)
{
	int temp = s.a;
	s.a = s.b;
	s.b = temp;
}

void print(S& s)
{
	std::cout << s.a << " " << s.b << " " << s.c << std::endl;
}

int main()
{

	S arr[5] = { {1, 2, 3}, {5, 2, 4}, {5, 8, 10}, {11, 14, 16}, {20, 21, 1} };

	map(arr, print, 5);
	map(arr, swapElements, 5);
	map(arr, print, 5);
	map(arr, printSum, 5);
	map(arr, readInput, 5);
	map(arr, printSum, 5);
	map(arr, increaseByOne, 5);
	map(arr, printSum, 5);

	return 0;
}