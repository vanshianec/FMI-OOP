#include "StringTrimmer.h"

TEST_CASE("Left trim tests")
{
	std::string s = "     text";
	StringTrimmer::ltrim(s, " ");
	CHECK(s == "text");

	s = "text";
	StringTrimmer::ltrim(s, " ");
	CHECK(s == "text");

	s = "";
	StringTrimmer::ltrim(s, " ");
	CHECK(s == "");

	s = "aaaaaaaab";
	StringTrimmer::ltrim(s, "a");
	CHECK(s == "b");

	s = "   something";
	std::string s2 = StringTrimmer::ltrim(s, " ");
	CHECK(s == "something");
	CHECK(s2 == s);
}

TEST_CASE("Right trim tests")
{
	std::string s = "text    ";
	StringTrimmer::rtrim(s, " ");
	CHECK(s == "text");

	s = "text";
	StringTrimmer::rtrim(s, " ");
	CHECK(s == "text");

	s = "";
	StringTrimmer::rtrim(s, " ");
	CHECK(s == "");

	s = "baaaaaaaa";
	StringTrimmer::rtrim(s, "a");
	CHECK(s == "b");

	s = "something   ";
	std::string s2 = StringTrimmer::rtrim(s, " ");
	CHECK(s == "something");
	CHECK(s2 == s);
}


TEST_CASE("Trim tests")
{
	std::string s = "    text    ";
	StringTrimmer::trim(s);
	CHECK(s == "text");

	s = "text";
	StringTrimmer::trim(s);
	CHECK(s == "text");

	s = "";
	StringTrimmer::trim(s);
	CHECK(s == "");

	s = "    something   ";
	std::string s2 = StringTrimmer::trim(s);
	CHECK(s == "something");
	CHECK(s2 == s);
}
