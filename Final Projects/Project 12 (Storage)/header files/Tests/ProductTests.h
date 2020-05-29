#include "Product.h"

TEST_CASE("Product Initializiation Tests")
{
	Product p("Yoghurt", "2000-05-05", "2000-05-01", "Vereq", "kg", 20, "So good");
	CHECK(p.getName() == "Yoghurt");
	CHECK(p.getExpirationDate() == "2000-05-05");
	CHECK(p.getEntryDate() == "2000-05-01");
	CHECK(p.getManufacturerName() == "Vereq");
	CHECK(p.getUnitOfMeasurement() == Unit::Kilograms);
	CHECK(p.getQuantity() == 20);
	CHECK(p.getComment() == "So good");
}

TEST_CASE("Product Functionality Tests")
{
	Product p("Yoghurt", "2000-05-05", "2000-05-01", "Vereq", "kg", 30, "So good");
	CHECK(p.getQuantity() == 30);
	p.reduceQuantity(10);
	CHECK(p.getQuantity() == 20);

	Product p2 = p;

	CHECK(p2 == p);

	Product p3("Yoghurt", "2000-05-06", "2000-05-01", "Vereq", "kg", 30, "So good");

	CHECK(p < p3);

	Product p4("Yoghurt", "2000-05-04", "2000-05-01", "Vereq", "kg", 30, "So good");

	CHECK(!(p < p4));
	
}