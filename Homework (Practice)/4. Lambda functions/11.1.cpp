
#include<iostream>

template<class T>
void map(T* arr, void(*f)(T), size_t len)
{
	for (int i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}

template<class T>
void print(T element)
{
	std::cout << element << std::endl;
}

int main()
{

	int arr[] = { 1, 2, 3, 5, 8, 20 };

	map(arr, print, 6);
	
	return 0;
}