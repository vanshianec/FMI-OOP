#include "Section.h"

TEST_CASE("Section Initializtaion Tests")
{
	Section s(200);

	CHECK(s.getCapacity() == 200);
	s.addItemsCount(20);
	CHECK(s.getItemsCount() == 20);

	s.addItemsCount(200);
	CHECK(s.getItemsCount() == 220);
}