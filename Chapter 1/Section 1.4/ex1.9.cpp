#include <iostream>

int main() {
	// sum numbers 50 to 100
	int val = 50, sum = 0;
	while (val <= 100) {
		sum += val;
		++val;
		std::cout << sum << '\n'; // prints each sum to screen
	}
}