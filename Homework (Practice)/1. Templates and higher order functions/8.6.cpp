#include<iostream>
#include <algorithm>

using doubleFunc = double (*)(double);
using doubleFuncArr = double (**)(double);

double fMax(doubleFunc f, doubleFunc g, double x)
{
	return std::max(f(x), g(x));
}

double maxArray1(doubleFuncArr arr, int n, double x)
{
	double maxRes = (*(arr))(x), currentRes;
	for (int i = 1; i < n; i++)
	{
		currentRes = (*(arr + i))(x);
		if (maxRes < currentRes)
		{
			maxRes = currentRes;
		}
	}

	return maxRes;
}


double maxArray2(doubleFuncArr arr, int n, double x)
{
	double maxRes = (*(arr))(x), currentRes;
	int k = n;

	if (n % 2 == 0)
	{
		k--;
	}

	for (int i = 1; i < k; i += 2)
	{
		currentRes = fMax((*(arr + i)), (*(arr + i + 1)), x);
		if (maxRes < currentRes)
		{
			maxRes = currentRes;
		}
	}

	if (n % 2 == 0)
	{
		return std::max(maxRes, (*(arr + n - 1))(x));
	}

	return maxRes;
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
	doubleFuncArr arr = new (double(*[3])(double));
	arr[0] = &cube;
	arr[1] = &cube;
	arr[2] = &square;

	std::cout << maxArray1(arr, 3, x) << std::endl;
	std::cout << maxArray2(arr, 3, x) << std::endl;

	doubleFuncArr arr2 = new (double(*[4])(double));
	arr2[0] = &cube;
	arr2[1] = &cube;
	arr2[2] = &cube;
	arr2[3] = &square;

	std::cout << maxArray1(arr2, 4, x) << std::endl;
	std::cout << maxArray2(arr2, 4, x) << std::endl;

}