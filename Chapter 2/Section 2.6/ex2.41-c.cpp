#include <iostream>

int main()
{
	struct Sales_data {
		std::string isbn;
		unsigned units_sold = 0;
		double revenue = 0.0;
	};

	Sales_data sales1;
	double price = 0;
	char prompt = 0;
	unsigned int totalSold = 0;
	double totalRevenue = 0;
	int cnt = 0;

	// must be for same ISBN 
	while (prompt != 'y')
	{
		std::cin >> sales1.isbn;
		std::cin >> sales1.units_sold;
		std::cin >> price;
		sales1.revenue = sales1.units_sold * price;
	
		totalSold += sales1.units_sold;
		totalRevenue += sales1.revenue;
		++cnt;
		if (cnt == 3)
		{
			std::cout << "Are you done? [y/n]: ";
			std::cin >> prompt;
			cnt = 0;
		}
	}
	std::cout << sales1.isbn << " " << totalSold << " " << totalRevenue << " "
	<< totalRevenue / totalSold;
	return 0;
}