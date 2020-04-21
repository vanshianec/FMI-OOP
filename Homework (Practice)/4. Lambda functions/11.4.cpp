
#include<iostream>
#include <functional>

template<class T>
using myFn = std::function<T(T)>;

template<class T>
myFn<T> repeated(int k, myFn<T> f)
{
	return [f, k](T x)->T
	{
		T result = x;

		for (int i = 0; i < k; i++)
		{
			result = f(result);
		}

		return result;
	};
}

double divideByTwo(double x)
{
	return x / 2;
}

int square(int x)
{
	return x * x;
}

int id(int x)
{
	return x;
}

int main()
{
	myFn<double> h1 = repeated<double>(5, divideByTwo);

	std::cout << h1(88.0) << std::endl;

	myFn<int> h2 = repeated<int>(3, square);

	std::cout << h2(4) << std::endl;

	myFn<int> h3 = repeated<int>(3, id);

	std::cout << h3(5) << std::endl;

	return 0;
}