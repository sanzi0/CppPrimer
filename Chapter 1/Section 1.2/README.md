# Section 1.2
## Exercises Section 1.2
### [Exercise 1.3]()
Write a program to print Hello, World on the standard output.

### [Exercise 1.4]()
Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, `*`, to print
the product instead.

### [Exercise 1.5]()
We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.

### [Exercise 1.6]()
Explain whether the following program fragment is legal.

```
std::cout << "The sum of " << v1;
          << " and " << v2;
          << " is " << v1 + v2 << std::endl;
```
Illegal. When we include the semicolon: `std::cout << "The sum of " << v1;`
We mean that the statement ends, so program continues execution on the following statement:
`<< " and " << v2;`
Which cannot compile because the first output operator of this expression lacks the left-hand operand (which is std::cout as far as we're concerned). 
It was supposed to be there because the very first statement of the program contains it:
`std::cout << "The sum of " << v1;`
And when the program starts, it reads this first:
`std::cout << "The sum of "`
Which prints the message to screen and evaluates to std::cout. Execution continues:
`std::cout << v1;`
This prints the value of v1 to screen and that's it. There's a semicolon, which officially ends the statement. 
std::cout doesn't survive to print out the next items on our program:
`<< " and " << v2;`
As stated, the first output operator (<<) ended up with no left-hand operand. It's a syntax error.
Correction: delete semicolons or type std::cout before every <<.
