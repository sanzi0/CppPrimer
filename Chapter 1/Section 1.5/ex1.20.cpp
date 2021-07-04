#include <iostream>
#include "Sales_item.h"

int main() {
	Sales_item item1, item2, item3;
	std::cin >> item1;
	std::cin >> item2;
	std::cin >> item3;

	std::cout << item1 << std::endl <<
		item2 << '\n'  << item3;
}