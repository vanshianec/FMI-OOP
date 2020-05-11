#define DOCTEST_CONFIG_IMPLEMENT
#define TEST_CASE DOCTEST_TEST_CASE
#include "doctest.h"
#include "Date.h"

TEST_CASE("Date first constructor tests")
{
	Date d1(2000, 1, 10);
	CHECK(d1.getYear() == 2000);
	CHECK(d1.getMonth() == 1);
	CHECK(d1.getDay() == 10);

	//edge case (first allowed date)
	Date d2(1900, 1, 1);
	CHECK(d2.getYear() == 1900);
	CHECK(d2.getMonth() == 1);
	CHECK(d2.getDay() == 1);

	//edge case (last allowed date)
	Date d3(9999, 12, 31);
	CHECK(d3.getYear() == 9999);
	CHECK(d3.getMonth() == 12);
	CHECK(d3.getDay() == 31);

	//TODO
}

TEST_CASE("Date second constructor tests")
{
	Date d1("2000-07-04");
	CHECK(d1.getYear() == 2000);
	CHECK(d1.getMonth() == 7);
	CHECK(d1.getDay() == 4);
	Date d2("2000-12-31");
	CHECK(d2.getYear() == 2000);
	CHECK(d2.getMonth() == 12);
	CHECK(d2.getDay() == 31);
	//TODO CATCHE EXC
	Date d4("2020-02-29");
	CHECK(d4.getYear() == 2020);
	CHECK(d4.getMonth() == 2);
	CHECK(d4.getDay() == 29);

}

/*
int main()
{
	doctest::Context().run();

	return 0;
}
*/
