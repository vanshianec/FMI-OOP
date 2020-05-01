#define DOCTEST_CONFIG_IMPLEMENT
#define TEST_CASE DOCTEST_TEST_CASE
#include "doctest.h"

#include "List.cpp"

TEST_CASE("Push Tests")
{
	LList<int> list;
	list.push(3);
	list.push(42);
	list.push(66);

	CHECK(list[0] == 66);
	CHECK(list[1] == 42);
	CHECK(list[2] == 3);
}

TEST_CASE("Modify data Tests")
{
	LList<int> list;
	list.push(3);
	list.push(42);
	list.push(66);
	CHECK(list[0] == 66);
	CHECK(list[1] == 42);
	CHECK(list[2] == 3);

	list[0] = 1;
	list[1] = 5;
	list[2] = 11;

	CHECK(list[0] == 1);
	CHECK(list[1] == 5);
	CHECK(list[2] == 11);
}

TEST_CASE("Pop Tests")
{
	LList<int> list;
	list.push(3);
	list.push(42);
	list.push(66);

	// 66 42 3

	int result = list.pop();
	CHECK(result == 66);
	CHECK(list[0] == 42);
	CHECK(list[1] == 3);

	result = list.pop();
	CHECK(result == 42);
	CHECK(list[0] == 3);
	result = list.pop();
	CHECK(result == 3);
}

TEST_CASE("Insert at Tests")
{
	LList<int> list;
	list.push(3);
	list.push(42);
	list.push(66);

	list.insertAfter(1, 99);

	CHECK(list[0] == 66);
	CHECK(list[1] == 42);
	CHECK(list[2] == 99);
}

TEST_CASE("Delete after Tests")
{
	LList<int> list;
	list.push(3);
	list.push(42);
	list.push(66);

	list.deleteAfter(1);

	CHECK(list[0] == 66);
	CHECK(list[1] == 42);

	list.deleteAfter(1);

	CHECK(list[0] == 66);
	CHECK(list[1] == 42);

	list.deleteAfter(0);

	CHECK(list[0] == 66);
}

TEST_CASE("Count Tests")
{
	LList<int> list;
	list.push(3);
	list.push(42);
	list.push(66);
	list.push(66);
	list.push(66);

	CHECK(list.count(66) == 3);
	CHECK(list.count(3) == 1);
	CHECK(list.count(55) == 0);
}

TEST_CASE("Push back Tests")
{
	LList<int> list;
	list.pushBack(3);
	list.pushBack(42);
	list.pushBack(66);
	list.pushBack(66);

	CHECK(list[0] == 3);
	CHECK(list[1] == 42);
	CHECK(list[2] == 66);
	CHECK(list[3] == 66);
}

TEST_CASE("Operator += Tests")
{
	LList<int> list;
	list += 3;
	list += 42;
	list += 66;
	list += 66;

	CHECK(list[0] == 3);
	CHECK(list[1] == 42);
	CHECK(list[2] == 66);
	CHECK(list[3] == 66);

}

TEST_CASE("Remove All Tests")
{
	LList<int> list;
	list += 66;
	list += 66;
	list += 42;
	list += 1;
	list += 4;
	list += 66;
	list += 66;
	list += 5;
	list += 66;
	list += 66;
	list += 66;

	list.removeAll(66);

	CHECK(list[0] == 42);
	CHECK(list[1] == 1);
	CHECK(list[2] == 4);
	CHECK(list[3] == 5);
}

TEST_CASE("Append Tests")
{
	LList<int> list;
	list += 66;
	list += 1;
	list += 42;

	LList<int> list2;
	list2 += 9;
	list2 += 10;
	list2 += 99;
	list2 += 4;

	list.append(list2);

	CHECK(list[0] == 66);
	CHECK(list[1] == 1);
	CHECK(list[2] == 42);
	CHECK(list[3] == 9);
	CHECK(list[4] == 10);
	CHECK(list[5] == 99);
	CHECK(list[6] == 4);
}

TEST_CASE("Concat Tests")
{
	LList<int> list;
	list += 66;
	list += 1;
	list += 42;

	LList<int> list2;
	list2 += 9;
	list2 += 10;
	list2 += 99;
	list2 += 4;

	LList<int> list3 = list.concat(list2);

	CHECK(list3[0] == 66);
	CHECK(list3[1] == 1);
	CHECK(list3[2] == 42);
	CHECK(list3[3] == 9);
	CHECK(list3[4] == 10);
	CHECK(list3[5] == 99);
	CHECK(list3[6] == 4);
}

TEST_CASE("Operator + Tests")
{
	LList<int> list;
	list += 66;
	list += 1;
	list += 42;

	LList<int> list2;
	list2 += 9;
	list2 += 10;
	list2 += 99;
	list2 += 4;

	LList<int> list3 = list + list2;

	CHECK(list3[0] == 66);
	CHECK(list3[1] == 1);
	CHECK(list3[2] == 42);
	CHECK(list3[3] == 9);
	CHECK(list3[4] == 10);
	CHECK(list3[5] == 99);
	CHECK(list3[6] == 4);
}

TEST_CASE("Operator += Tests")
{
	LList<int> list;
	list += 66;
	list += 1;
	list += 42;

	LList<int> list2;
	list2 += 9;
	list2 += 10;
	list2 += 99;
	list2 += 4;

	list += list2;

	CHECK(list[0] == 66);
	CHECK(list[1] == 1);
	CHECK(list[2] == 42);
	CHECK(list[3] == 9);
	CHECK(list[4] == 10);
	CHECK(list[5] == 99);
	CHECK(list[6] == 4);
}

TEST_CASE("Reverse Tests")
{
	LList<int> list;
	list += 66;
	list += 1;
	list += 42;

	LList<int> list2;
	list2 += 9;
	list2 += 10;
	list2 += 99;
	list2 += 4;

	list += list2;

	list.reverse();

	CHECK(list[0] == 4);
	CHECK(list[1] == 99);
	CHECK(list[2] == 10);
	CHECK(list[3] == 9);
	CHECK(list[4] == 42);
	CHECK(list[5] == 1);
	CHECK(list[6] == 66);
}

int main()
{
	doctest::Context().run();

	return 0;
}