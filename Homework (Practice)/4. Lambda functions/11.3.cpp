
#include<iostream>
#include <functional>

template <class T>
std::function<bool(T)> negate(std::function<bool(T)> p)
{
	return [p](T x)->bool {return !p(x); };
}

bool isEven(int x)
{
	return x % 2 == 0;
}

int main()
{
	std::cout << isEven(4) << std::endl;
	std::cout << negate<int>(isEven)(4);

	return 0;
}