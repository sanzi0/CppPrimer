#include <iostream>

int main()
{
	// define variables
	int i = 0;
	int &r = i;
	auto a = r;
	const int ci = i,
	const int &cr = ci;
	auto b = ci;
	auto c = cr; 
	auto d = &i;
	auto e = &ci; 
	auto &g = ci; 

	// do assignments
	a = 42; 
	b = 42; 
	c = 42;
	d = 42; // predictions were correct
	e = 42; // predictions were correct
	g = 42; // predictions were correct
}