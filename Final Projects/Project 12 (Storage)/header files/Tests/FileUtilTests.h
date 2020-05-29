#include "FileUtil.h"

TEST_CASE("File Path Test")
{
	FileUtil::path = "C:\\Users\\Иван Йовов\\source\\repos\\SVG\\SVG\\Test Files\\empty.svg";
	std::string filePath = FileUtil::path;
	CHECK(filePath == "C:\\Users\\Иван Йовов\\source\\repos\\SVG\\SVG\\Test Files\\empty.svg");
}

TEST_CASE("Empty File Tests")
{
	FileUtil::path = "C:\\Users\\Иван Йовов\\source\\repos\\SVG\\SVG\\Test Files\\empty.svg";
	bool empty = FileUtil::isEmpty();
	CHECK(empty == true);

	FileUtil::path = "C:\\Users\\Иван Йовов\\source\\repos\\SVG\\SVG\\Test Files\\notEmpty.svg";
	empty = FileUtil::isEmpty();
	CHECK(empty == false);
}

TEST_CASE("File Open Tests")
{
	FileUtil::path = "C:\\Users\\Иван Йовов\\source\\repos\\SVG\\SVG\\Test Files\\empty.svg";
	bool canOpen = FileUtil::open();
	CHECK(canOpen == true);

	// non existent path
	FileUtil::path = "Z:\\NON_EXISTENT.jfkdsjf";
	canOpen = FileUtil::open();
	CHECK(canOpen == false);
}

TEST_CASE("File Name Tests")
{
	FileUtil::path = "C:\\Users\\Иван Йовов\\source\\repos\\SVG\\SVG\\Test Files\\empty.svg";
	std::string fileName = FileUtil::fileName();
	CHECK(fileName == "empty.svg");


	FileUtil::path = "C:\\Users\\Иван Йовов\\source\\repos\\SVG\\SVG\\Test Files\\notEmpty.svg";
	fileName = FileUtil::fileName();
	CHECK(fileName == "notEmpty.svg");
}



