#include <iostream>

int main()
{
	// define variable
	const int i = 42;

	// do assignments
	auto j = i; 
	const auto &k = i; 
	auto *p = &i;
	const auto j2 = i, &k2 = i;
	/* predictions were all correct */
}