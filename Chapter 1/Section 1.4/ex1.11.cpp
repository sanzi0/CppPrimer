#include <iostream>

int main() {
	int a = 0, b = 0;
	// The first number must be bigger than the second, or else
	// the program will run forever. This is solved a couple
	// exercises ahead.
	std::cout << "Enter a number: ";
	std::cin >> a;
	std::cout << "Enter another number: ";
	std::cin >> b;
		while (a != b) {
			std::cout << b << '\n';
			++b;
		}
	return 0;
}