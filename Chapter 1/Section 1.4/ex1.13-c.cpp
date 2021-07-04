#include <iostream>

int main() {
	int a = 0, b = 0;
	std::cout << "Enter a number: ";
	std::cin >> a;
	std::cout << "Enter another number: ";
	std::cin >> b;

	if (a > b) {
		for (; b <= a; ++b) // semicolon is itself the init-statement, no need to initialize another variable
			std::cout << b << '\n'; 
	}
	else if (a < b) {
		for (; a <= b; ++a) // the greater-then-or-equal-to operator allows for printing the full closed interval
			std::cout << a << '\n'; // e.g. 0 to 100 inclusive, and even prints the first number itself
	}
}