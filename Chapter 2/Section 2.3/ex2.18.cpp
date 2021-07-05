#include <iostream>

int main()
{
	int a = 512;
	int b = 1024;

	// initialize pt as a pointer
	// to a
	int *pt = &a;

	// change address stored in pt
	// it now points to b
	pt = &b;

	// access object through dereference
	// assigns 256 to b
	*pt = 256;

	return 0;
}
