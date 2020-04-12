#include<iostream>

template<class T>
bool ordered(T* array, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int arr[] = { 1, 4, 6, 21 };
	double arr2[] = { 4.2, 6, 7.1, 9 };
	char arr3[] = { 'a', 'b', 'c' };
	char arr4[] = { 'b', 'a', 'c' };

	std::cout << ordered(arr, 4) << std::endl;
	std::cout << ordered(arr2, 4) << std::endl;
	std::cout << ordered(arr3, 3) << std::endl;
	std::cout << ordered(arr4, 3) << std::endl;
}