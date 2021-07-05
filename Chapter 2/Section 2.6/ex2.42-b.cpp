#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data sales1, sales2;
	double price = 0;
	unsigned int totalSold = 0;
	double totalRevenue = 0;

	// must be for same ISBN 
	std::cin >> sales1.isbn >> sales1.units_sold >> price;
	sales1.revenue = sales1.units_sold * price;
	std::cin >> sales2.isbn >> sales2.units_sold >> price;
	sales2.revenue = sales2.units_sold * price;

	totalSold = sales1.units_sold + sales2.units_sold;
	totalRevenue = sales1.revenue + sales2.revenue;

	std::cout << sales1.isbn << " " << totalSold << " " << totalRevenue << " " << totalRevenue / totalSold;
	return 0;
}