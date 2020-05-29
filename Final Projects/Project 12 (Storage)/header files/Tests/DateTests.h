#include "Date.h"
#include "InvalidParameterException.h"

TEST_CASE("Date Initialization Tests")
{
	Date date(2000, 10, 30);
	CHECK(date.getYear() == 2000);
	CHECK(date.getMonth() == 10);
	CHECK(date.getDay() == 30);

	std::string invalidDateMessage;

	try
	{
		Date date(2000, 99, 99);
	}
	catch (InvalidParameterException ex)
	{
		invalidDateMessage = ex.what();
	}

	CHECK(invalidDateMessage == "Invalid date format! Supported date format is YYYY-MM-DD");
}

TEST_CASE("Date Initialization Tests")
{
	Date date(2000, 10, 30);
	CHECK(date.getYear() == 2000);
	CHECK(date.getMonth() == 10);
	CHECK(date.getDay() == 30);

	Date date2("2000-10-30");
	CHECK(date.getYear() == 2000);
	CHECK(date.getMonth() == 10);
	CHECK(date.getDay() == 30);

	std::string invalidDateMessage;

	try
	{
		Date date(2000, 99, 99);
	}
	catch (InvalidParameterException ex)
	{
		invalidDateMessage = ex.what();
	}

	CHECK(invalidDateMessage == "Invalid date format! Supported date format is YYYY-MM-DD");

	std::string invalidDateMessage2;

	try
	{
		Date date("2000-99-99");
	}
	catch (InvalidParameterException ex)
	{
		invalidDateMessage2 = ex.what();
	}

	CHECK(invalidDateMessage2 == "Invalid date format! Supported date format is YYYY-MM-DD");
}

TEST_CASE("Edge Case Tests")
{
	//February leap year
	Date date1("2000-02-29");
	CHECK(date1.getDay() == 29);
	//February non leap year
	Date date2("2001-02-28");
	CHECK(date2.getDay() == 28);

	Date date3("2000-01-31");
	CHECK(date3.getDay() == 31);

	Date date4("2000-04-30");
	CHECK(date4.getDay() == 30);

	std::string invalidDateMessage;

	try
	{
		Date date("2000-04-31");
	}
	catch (InvalidParameterException ex)
	{
		invalidDateMessage = ex.what();
	}

	CHECK(invalidDateMessage == "Invalid date format! Supported date format is YYYY-MM-DD");
}

TEST_CASE("Comparison Operators Tests")
{
	Date date1("2000-05-29");
	Date date2("2000-05-28");

	CHECK(date1 > date2);
	CHECK(!(date1 < date2));

	CHECK(date1 >= date2);
	CHECK(!(date1 <= date2));

	CHECK(!(date1 == date2));

	Date date3("2000-05-29");

	CHECK(date3 == date1);
}

