#include<iostream>
#include <algorithm>

using doubleFunc = double (*)(double);

double fMax(doubleFunc f, doubleFunc g, double x)
{
	return std::max(f(x), g(x));
}

double square(double x)
{
	return x * x;
}

double cube(double x)
{
	return x * x * x;
}

int main()
{
	double x;
	std::cin >> x;
	doubleFunc f = &square;
	doubleFunc g = &cube;
	std::cout << fMax(f, g, x);

}