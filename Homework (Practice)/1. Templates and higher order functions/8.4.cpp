#include<iostream>

double square(double x)
{
	return x * x;
}

double cube(double x)
{
	return x * x * x;
}

double half(double x)
{
	return x / 2;
}

double half2(double x)
{
	return x / 2;
}

double byPi(double x)
{
	return x * 3.14;
}

int main()
{
	double (*fnArray[5])(double);
	fnArray[0] = &square;
	fnArray[1] = &cube;
	fnArray[2] = &half;
	fnArray[3] = &byPi;
	fnArray[4] = &half2;

	double x, minRes = 100000;
	std::cin >> x;

	for (int i = 0; i < 5; i++)
	{
		double res = (*(fnArray + i))(x);
		if (res < minRes)
		{
			minRes = res;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (fnArray[i](x) == minRes)
		{
			std::cout << i << " ";
		}
	}


}