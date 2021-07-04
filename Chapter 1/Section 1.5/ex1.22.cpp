#include <iostream>
#include "Sales_item.h"

int main() {
	Sales_item sum, input;
	while (std::cin >> input)
		sum += input;
	std::cout << sum << std::endl;

	return 0;
}