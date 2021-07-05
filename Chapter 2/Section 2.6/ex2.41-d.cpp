#include <iostream>

int main()
{
	// sales2.isbn is the empty string, therefore, it's always going to be different
	// than whatever the user provides in the input phase of the program. to solve this,
	// i just initialized isbn to the string "control" so we can actually test for it in the conditions.
	// doesn't look too good. will have to do for now
	// we can come back later and fix this
	struct Sales_data {
		std::string isbn = "control";
		unsigned units_sold = 0;
		double revenue = 0.0;
	};

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
