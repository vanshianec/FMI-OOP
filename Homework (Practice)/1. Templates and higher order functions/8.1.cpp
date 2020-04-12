#include<iostream>

template<class T>
void input(T* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cin >> array[i];
	}
}

template<class T>
void printArr(T* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << array[i] << " ";
	}
	std:: cout << std::endl;
}

int main()
{
	int arr[3];
	input(arr, 3);
	printArr(arr, 3);
	double arr2[3];
	input(arr2, 3);
	printArr(arr2, 3);
	char arr3[3];
	input(arr3, 3);
	printArr(arr3, 3);
}