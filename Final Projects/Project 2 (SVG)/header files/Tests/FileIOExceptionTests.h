#include "FileIOException.h"

TEST_CASE("Exception throw test")
{
	std::string message;

	try
	{
		throw FileIOException("This is the message");
	}
	catch (FileIOException ex)
	{
		message = ex.what();
	}

	CHECK(message == "This is the message");
}

