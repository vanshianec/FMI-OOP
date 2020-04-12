#include<iostream>

template<class T>
bool member(T* array, int n, T element)
{
	for (int i = 0; i < n; i++)
	{
		if (array[i] == element)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	int arr[] = { 1, 4, 6, 21 };
	double arr2[] = { 4.2, 6, 7.1, 9 };
	char arr3[] = { 'a', 'b', 'c' };
	char arr4[] = { 'b', 'a', 'c' };

	std::cout << member(arr, 4, 4) << std::endl;
	std::cout << member(arr2, 4, 7.1) << std::endl;
	std::cout << member(arr3, 3, 'c') << std::endl;
	std::cout << member(arr4, 3, 'z') << std::endl;
}