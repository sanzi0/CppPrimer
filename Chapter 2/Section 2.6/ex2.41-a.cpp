#include <iostream>

int main()
{
	struct Sales_data {
		std::string isbn;
		unsigned units_sold = 0;
		double revenue = 0.0;
	};

	// a "set" of transactions. let's assume three
	// needs to have same ISBN
	Sales_data sales1, sales2, sales3;
	double price = 0;

	std::cin >> sales1.isbn;
	std::cin >> sales1.units_sold;
	std::cin >> price;
	sales1.revenue = sales1.units_sold * price;

	std::cin >> sales2.isbn;
	std::cin >> sales2.units_sold;
	std::cin >> price;
	sales2.revenue = sales2.units_sold * price;

	std::cin >> sales3.isbn;
	std::cin >> sales3.units_sold;
	std::cin >> price;
	sales3.revenue = sales3.units_sold * price;

	unsigned int totalSold = sales1.units_sold + sales2.units_sold + sales3.units_sold;
	double totalRevenue = sales1.revenue + sales2.revenue + sales3.revenue;
	std::cout << sales1.isbn << " " << totalSold << " " << totalRevenue << " "
		<< totalRevenue / totalSold;

	return 0;
}
