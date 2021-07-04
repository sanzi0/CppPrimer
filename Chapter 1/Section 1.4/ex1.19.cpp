#include <iostream>

int main() {
	int a = 0, b = 0;
	std::cout << "Enter a number: ";
	std::cin >> a;
	std::cout << "Enter another number: ";
	std::cin >> b;

	if (b < a) {
		while (a != b) {
			std::cout << b << '\n';
			++b;
		}
	} else {
		while (a != b) {
			std::cout << a << '\n';
			++a;
		}
	}
	return 0;
}