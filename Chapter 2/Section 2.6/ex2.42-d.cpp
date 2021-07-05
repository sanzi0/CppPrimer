#include <iostream>
#include "Sales_data.h"
int main()
{
	Sales_data sales1, sales2;
	sales1.isbn = "control";
	sales2.isbn = "control";
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
		if (timer >= 4)
		{
			std::cout << "Are you done? [y/n]: ";
			std::cin >> prompt;
			timer = 0;
		}
	}
}
