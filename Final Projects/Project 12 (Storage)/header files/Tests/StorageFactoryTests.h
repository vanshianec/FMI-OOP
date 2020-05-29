#include "StorageFactory.h"
#include <vector>
#include <string>

TEST_CASE("Create Storage Test")
{
	std::string sectionsCount = "4";
	std::string sectionsCapacity = "10";

	std::vector<std::string> params = { sectionsCount , sectionsCapacity};

	Storage s = StorageFactory::createStorage(params);
	CHECK(s.getSections().size() == 4);

	for (const Section sec : s.getSections())
	{
		CHECK(sec.getCapacity() == 10);
	}
}