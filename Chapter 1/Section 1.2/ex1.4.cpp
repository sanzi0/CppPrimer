#include <iostream>

int main() {
	std::cout << "Enter two numbers:" << std::endl;
	int a = 0, b = 0;
	std::cin >> a >> b;
	std::cout << "The product of " << a << " and " << b << " is "
		  << a * b;
	return 0;
}
