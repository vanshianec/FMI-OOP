#include<iostream>

struct myStruct
{
	int a;
	int b;
	int c;
};

using cmp = int (*) (myStruct, myStruct);

void sort(myStruct arr[], int n, cmp compare)
{
	myStruct current;
	int j;
	for (int i = 1; i < n; i++)
	{
		current = arr[i];
		j = i;
		while (--j >= 0 && (compare(arr[j], current) > 0))
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = current;
	}
}

int compareByA(myStruct s1, myStruct s2)
{
	return s1.a > s2.a ? 1 : s1.a == s2.a ? 0 : -1;
}

int compareByB(myStruct s1, myStruct s2)
{
	return s1.b > s2.b ? 1 : s1.b == s2.b ? 0 : -1;
}

void printStructs(myStruct arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i].a << " " << arr[i].b << " " << arr[i].c << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	myStruct s1 = { 2, 4, 6 };
	myStruct s2 = { 15, 44, 8 };
	myStruct s3 = { 76, 8, 1 };
	myStruct s4 = { 2, 11, 55 };
	myStruct s5 = { 5, 8, 2 };

	myStruct arr[] = { s1, s2, s3, s4, s5 };
	printStructs(arr, 5);
	sort(arr, 5, compareByA);
	printStructs(arr, 5);
	sort(arr, 5, compareByB);
	printStructs(arr, 5);
}