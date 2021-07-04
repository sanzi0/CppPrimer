#include <iostream>
#include "Sales_item.h"

int main() {
	Sales_item item1, item2;
	int count = 1;
	if (std::cin >> item1)
		while (std::cin >> item2)
			if (item1.isbn() == item2.isbn()) {
				item1 += item2;
				++count;
			} else {
				std::cout << count << " transactions occurred for "
					      << item1.isbn() << std::endl;
				count = 1;
				item1 = item2;
			}
	return 0;
}	