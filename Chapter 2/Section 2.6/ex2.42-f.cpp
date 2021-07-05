#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data sales1, sales2; // we define two Sales_data objects					 
	double price = 0;		   // so we can compare ISBNs
	char prompt = 0;
	unsigned int totalSold = 0;
	double totalRevenue = 0;
	int timer = 0;
	int cnt = 0;

	while (prompt != 'y')
	{
		// fetch data to first variable and do calculations
		std::cin >> sales1.isbn;
		// hacky control string to check if it's empty (first time executing program)
		if (sales1.isbn != sales2.isbn && sales2.isbn != "control")
		{
			std::cout << R"(|||||||| * * *  R E S U L T S  * * * ||||||||
)" << sales2.isbn << " " << totalSold << " " << totalRevenue <<
" " << totalRevenue / totalSold << '\n' << sales2.isbn <<
" occurs " << cnt << " times." << std::endl;
			totalSold = 0; // empty sum containers
			totalRevenue = 0;
			cnt = 0; // reset counter
		}
		std::cin >> sales1.units_sold;
		std::cin >> price;
		sales1.revenue = sales1.units_sold * price;
		totalSold += sales1.units_sold;
		totalRevenue += sales1.revenue;
		++cnt; // increment ISBN count

		// fetch data to second variable and do calculations
		std::cin >> sales2.isbn;
		if (sales1.isbn != sales2.isbn)
		{
			std::cout << R"(|||||||| * * *  R E S U L T S  * * * ||||||||
)" << sales1.isbn << " " << totalSold << " " << totalRevenue <<
" " << totalRevenue / totalSold << '\n' << sales1.isbn <<
" occurs " << cnt << " times." << std::endl;
			totalSold = 0;
			totalRevenue = 0;
			cnt = 0;
		}
		std::cin >> sales2.units_sold;
		std::cin >> price;
		sales2.revenue = sales2.units_sold * price;
		totalSold += sales2.units_sold;
		totalRevenue += sales2.revenue;
		++timer; // increment timer once per 2 inputs to prompt user if they are done
		++cnt;
		// program termination mechanism. very inelegant. too bad!
		if (timer >= 3)
		{
			std::cout << "Are you done? [y/n]: ";
			std::cin >> prompt; // if user inputs y loop ends here
			timer = 0;
		}
	}
	// prints last stored value
	std::cout <<
		R"(|||||||| * * *  R E S U L T S  * * * ||||||||
)" << sales1.isbn << " " << totalSold << " " << totalRevenue << " " <<
totalRevenue / totalSold << '\n' <<
sales1.isbn << " occurs " << cnt << " times." << std::endl;
	return 0;
}