#include <iostream>

int main() {
	// fixed version
	std::cout << "/*";
	std::cout << "*/";
	std::cout << /* "*/ "*/";
	std::cout << /* "*/ "/*" /*" */;
}
