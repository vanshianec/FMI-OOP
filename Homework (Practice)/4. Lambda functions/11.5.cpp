
#include<iostream>
#include <functional>
#include <vector>

template<class T>
using func = std::function<T(T)>;

template<class T>
func<T> createFn(std::vector<T> args, std::vector<T> values)
{
	return [args, values](T x)->T
	{
		for (size_t i = 0; i < args.size(); i++)
		{
			if (args[i] == x)
			{
				return values[i];
			}
		}

		return NULL;
	};
}


int main()
{
	std::vector<int> x = { 1, 3, 5, 7, 11, 44, 66 };
	std::vector<int> y = { -1, -3, -5, -7, -11, -44, -66 };

	func<int> h = createFn(x, y);

	std::cout << h(3) << std::endl;
	std::cout << h(100) << std::endl;

	return 0;
}