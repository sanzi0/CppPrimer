#include <iostream>
#include "Sales_data.h"
int main()
{
	// this one has isbn initialized to the string
	// "control" so the whole logic works... not pretty.
	// too bad!
	Sales_data sales1, sales2;
	double price = 0;
	unsigned int totalSold = 0;
	double totalRevenue = 0;
	int cnt = 0;
	int timer = 0;
	char prompt = 0;

	while (prompt != 'y')
	{
		std::cin >> sales1.isbn;
		std::cin >> sales1.units_sold;
		std::cin >> price;
		sales1.revenue = sales1.units_sold * price;
		if (sales1.isbn != sales2.isbn && sales2.isbn != "control")
		{
			std::cout << sales2.isbn << " occurs " << cnt << " times." << std::endl;
			cnt = 0;
		}
		++cnt;

		std::cin >> sales2.isbn;
		std::cin >> sales2.units_sold;
		std::cin >> price;
		sales2.revenue = sales2.units_sold * price;

		if (sales1.isbn != sales2.isbn)
		{
			std::cout << sales1.isbn << " occurs " << cnt << " times." << std::endl;
			cnt = 0;
		}
		++cnt;
		++timer;
		if (timer >= 3)
		{
			std::cout << "Are you done? [y/n]: ";
			std::cin >> prompt;
		}
	}

}
