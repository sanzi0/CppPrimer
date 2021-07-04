# Section 1.4
## Exercises Section 1.4.1
### [Exercise 1.9](/Chapter%201/Section%201.4/ex1.9.cpp)
#### Write a program that uses a while to sum the numbers from 50 to 100.
<br/>
<br/>

### [Exercise 1.10](/Chapter%201/Section%201.4/ex1.10.cpp) 
#### In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.
<br/>
<br/>

### [Exercise 1.11](/Chapter%201/Section%201.4/ex1.11.cpp) 
#### Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.
<br/>
<br/>

## Exercises Section 1.4.2
### Exercise 1.12
#### What does the following for loop do? What is the final value of sum?
```
int sum = 0;
for (int i = -100; i <= 100; ++i)
  sum += i;
```
<br/>
<br/>

Prints the sum of values from -100 to 100 inclusive. Sum equals 0.
### [Exercise 1.13](/Chapter%201/Section%201.4/ex1.13-a.cpp)
#### Rewrite the exercises from § [1.4.1](/Chapter%201/Section%201.4#exercises-section-141) (p. 13) using for loops.
###### [Sum](/Chapter%201/Section%201.4/ex1.13-a.cpp), [Decrement](/Chapter%201/Section%201.4/ex1.13-b.cpp), [Range](/Chapter%201/Section%201.4/ex1.13-c.cpp)

### [Exercise 1.14](url)
#### Compare and contrast the loops that used a for with those using a while. Are there advantages or disadvantages to using either form?
<br/>
<br/>

With my current knowledge, I cannot see any differences between the two. `while (true)` is an infinite loop, but also is `for (; ;)`.
`for` allows a creation of a variable of limited scope, while `while` can only test a condition. Maybe the difference lies in the sequence of execution - perhaps you want an increment (or expression) to be solved/evaluated in a certain order. `for` loops always test the condition, execute the block and then increment the value. `while` however, can test the condition, increment a value first and then execute the block. And within this block you can do all sorts of different things. 

### [Exercise 1.15](url)
#### Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.
<br/>
<br/>

![ex1.15](/assets/ch1/ex1.15.png)
Tip: you can right-click your project -> properties -> C/C++ -> set Disable Language Extensions to **Yes (/Za)**. While you're at it,
set C++ Language Standard to **ISO C++17 Standard (/std:c++17)**. When a tutorial tries to teach you new C++17-implemented stuff, you'll be
good to go. And disabling language extensions helps us learn by adhering strictly to [C++ rules](https://www.learncpp.com/cpp-tutorial/configuring-your-compiler-compiler-extensions/) - or so I'm told. These guys also recommend you to change "Treat All Warnings As Errors" to **Yes (/WX)**, but I found this to be
slightly inconvenient when trying to jot down quick and dirty code for places like [Project Euler](https://projecteuler.net/about).
## Exercises Section 1.4.3
### [Exercise 1.16](url)
#### Write your own version of a program that prints the sum of a set of integers read from cin.
<br/>
<br/>

## Exercises Section 1.4.4
### [Exercise 1.17](url)
#### What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?
```
#include <iostream>
int main()
{
	// currVal is the number we're counting; we'll read new values into val
	int currVal = 0, val = 0;
	// read first number and ensure that we have data to process
	if (std::cin >> currVal) {
		int cnt = 1; // store the count for the current value we're processing
		while (std::cin >> val) { // read the remaining numbers
			if (val == currVal) // if the values are the same
				++cnt; // add 1 to cnt
			else { // otherwise, print the count for the previous value
				std::cout << currVal << " occurs "
				          << cnt << " times" << std::endl;
				currVal = val; // remember the new value
				cnt = 1; // reset the counter
			}
		} // while loop ends here
		// remember to print the count for the last value in the file
		std::cout << currVal << " occurs "
		          << cnt << " times" << std::endl;
	} // outermost if statement ends here
	return 0;
}
```
<br/>
<br/>

If the input values are all equal, the program doesn't output anything. The program will prompt the user to enter a first number, store it in
`currVal`, and a second one, storing it in `val`. Then, only the second if statement will be executed, eternally incrementing `cnt`. The only way 
to see how many times these numbers occurred (and effectively end the `while` loop) is to signal end-of-file to `std::cin` through CTRL+Z (Windows). 
The read doesn't succeed, therefore `std::cin` isn't returned, the condition evaluates to false and the last statement of the first `if` block is 
executed: we see the value of `currVal`, which represents our first input, and also `cnt`, which is the counter for how many times these equal values
appeared.
