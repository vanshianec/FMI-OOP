#include "Storage.h"

TEST_CASE("Storage Initialization Tests")
{
	Storage s;

	Product p1("Yoghurt", "2020-05-05", "2020-05-01", "Vereq", "kg", 20, "So good");
	Product p2("Milk", "2020-05-15", "2020-05-02", "Saiana", "l", 30, "Not so good");

	s.addProduct(p1);
	s.addProduct(p2);

	CHECK(s.getProducts().size() == 2);

	s.addAddedProduct(p1);
	s.addAddedProduct(p2);

	CHECK(s.getAddedProducts().size() == 2);

	s.addRemovedProduct(p1);
	s.addRemovedProduct(p2);

	CHECK(s.getRemovedProducts().size() == 2);

	Section s1(100);
	Section s2(200);

	s.addSection(s1);
	s.addSection(s2);

	CHECK(s.getSections().size() == 2);

	CHECK(s.getProducts()[0].getName() == "Yoghurt");
	CHECK(s.getProducts()[0].getExpirationDate() == "2020-05-05");
	CHECK(s.getProducts()[0].getEntryDate() == "2020-05-01");
	CHECK(s.getProducts()[0].getManufacturerName() == "Vereq");
	CHECK(s.getProducts()[0].getUnitOfMeasurement() == Unit::Kilograms);
	CHECK(s.getProducts()[0].getQuantity() == 20);
	CHECK(s.getProducts()[0].getComment() == "So good");

	CHECK(s.getProducts()[1].getName() == "Milk");
	CHECK(s.getProducts()[1].getExpirationDate() == "2020-05-15");
	CHECK(s.getProducts()[1].getEntryDate() == "2020-05-02");
	CHECK(s.getProducts()[1].getManufacturerName() == "Saiana");
	CHECK(s.getProducts()[1].getUnitOfMeasurement() == Unit::Liters);
	CHECK(s.getProducts()[1].getQuantity() == 30);
	CHECK(s.getProducts()[1].getComment() == "Not so good");

}

TEST_CASE("Storage Clean Test")
{
	Storage s;

	Product p1("Yoghurt", "2020-05-05", "2020-05-01", "Vereq", "kg", 20, "So good");
	Product p2("Milk", "2020-05-15", "2020-05-02", "Saiana", "l", 30, "Not so good");

	s.addProduct(p1);
	s.addProduct(p2);

	s.addAddedProduct(p1);
	s.addAddedProduct(p2);

	s.addRemovedProduct(p1);
	s.addRemovedProduct(p2);

	Section s1(100);
	Section s2(200);

	s.addSection(s1);
	s.addSection(s2);

	s.clear();

	CHECK(s.getProducts().size() == 0);
	CHECK(s.getAddedProducts().size() == 0);
	CHECK(s.getRemovedProducts().size() == 0);
	CHECK(s.getSections().size() == 0);
}

TEST_CASE("Storage Remove Tests")
{
	Storage s;

	Product p1("Yoghurt", "2020-05-05", "2020-05-01", "Vereq", "kg", 20, "So good");
	Product p2("Milk", "2020-05-15", "2020-05-02", "Saiana", "l", 30, "Not so good");

	s.addProduct(p1);
	s.addProduct(p2);

	s.removeProduct("Milk", 15);
	CHECK(s.getRemovedProducts().size() == 1);
	CHECK(s.getProducts()[1].getQuantity() == 15);
	s.removeProduct("Milk", 15);
	CHECK(s.getRemovedProducts().size() == 2);
	CHECK(s.getProducts().size() == 1);
	s.removeProduct("Yoghurt", 20);
	CHECK(s.getProducts().size() == 0);
	CHECK(s.getRemovedProducts().size() == 3);
}

TEST_CASE("Storage Remove Tests")
{
	Storage s;

	Product p1("Yoghurt", "2020-05-05", "2020-05-01", "Vereq", "kg", 20, "So good");
	Product p2("Milk", "2020-05-15", "2020-05-02", "Saiana", "l", 30, "Not so good");

	s.addProduct(p1);
	s.addProduct(p2);

	s.removeProduct("Milk", 15);
	CHECK(s.getRemovedProducts().size() == 1);
	CHECK(s.getProducts()[1].getQuantity() == 15);
	s.removeProduct("Milk", 15);
	CHECK(s.getRemovedProducts().size() == 2);
	CHECK(s.getProducts().size() == 1);
	s.removeProduct("Yoghurt", 20);
	CHECK(s.getProducts().size() == 0);
	CHECK(s.getRemovedProducts().size() == 3);
}