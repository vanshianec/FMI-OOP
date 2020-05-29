#include "ProductFactory.h"
#include "DateTime.h"
#include <vector>
#include <string>

TEST_CASE("Product Creation Tests")
{
	std::string productName = "Yoghurt";
	std::string manufacturerName = "Vereq";
	std::string quantity = "40";
	std::string unitOfMeasurement = "kg";
	std::string expirationDate = "2000-05-05";
	std::string comment = "So good";

	std::vector<std::string> params = { productName, manufacturerName, quantity,
		unitOfMeasurement,	expirationDate, comment };

	Product p = ProductFactory::createProduct(params);

	CHECK(p.getName() == "Yoghurt");
	CHECK(p.getManufacturerName() == "Vereq");
	CHECK(p.getQuantity() == 40); 
	CHECK(p.getUnitOfMeasurement() == Unit::Kilograms);
	CHECK(p.getExpirationDate() == "2000-05-05");
	CHECK(p.getComment() == "So good");
	char entryDate[11];
	DateTime::currentDateISO8601(entryDate);
	CHECK(p.getEntryDate() == entryDate);

}