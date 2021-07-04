#include <iostream>

int main() {
	int sum = 0, input = 0;
	std::cout << "Enter a number: ";
		if (std::cin >> sum)
			std::cout << "Enter another number: ";
		while (std::cin >> input) {
			sum += input;
			std::cout << "The result of the sum is: " << sum << '\n';
		}
}
