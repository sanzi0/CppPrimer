# Section 2.2
## Exercises Section 2.2.1
### Exercise 2.9
#### Explain the following definitions. For those that are illegal, explain what’s wrong and how to correct it.
##### (a) std::cin >> int input_value;
Compiler shows error `E0254: type name is not allowed`. This is illegal, the variable needs to first be declared and then it can be used with `std::cin`. <br/>

##### (b) int i = { 3.14 };
Type conversion does not happen because of the use of list initialization. Change type to `double` or do copy initialization. <br/>

##### (c) double salary = wage = 9999.99;
Illegal. It's not possible to chain initializations like this, compiler complains. A possible workaround, if typing everything in the same line is a priority:
```c++ 
double salary = 9999.99; double wage = salary;
```

##### (d) int i = 3.14;
Legal, but number gets truncated. Only the value before the decimal point gets stored. It's possible to change `int` to `float`, `double` or `long double`, types that
can safely hold that value. <br/>

### Exercise 2.10
#### What are the initial values, if any, of each of the following variables?
```c++
std::string global_str;
int global_int;
int main()
{
	int local_int;
	std::string local_str;
}
```
<br/>
<br/>

`global_str` is initialized to the empty string, `global_int` is a global variable of value `0`, `local_int` is a local variable defined in the body of `main`. This means
its value is undefined. `local_str` is initialized to the empty string.

## Exercises Section 2.2.2
### Exercise 2.11
#### Explain whether each of the following is a declaration or a definition:
##### (a) extern int ix = 1024;
Initializer provided. Extern overridden. Definition + declaration. <br/>

##### (b) int iy;
No initializer. Object was given a name, type and memory space. Definition + declaration. <br/>

##### (c) extern int iz;
Usage of the extern keyword. Declaration. <br/>

## Exercises Section 2.2.3
### Exercise 2.12
#### Which, if any, of the following names are invalid?
##### (a) int double = 3.14;
Invalid. `double` is a reserved keyword. <br/>

##### (b) int \_;
Valid. Names can begin with the underscore character. <br/>

##### (c) int catch-22;
Invalid. Allowed composition of identifiers: letters, digits and the underscore character. <br/>

##### (d) int 1_or_2 = 1;
Invalid. Names can't begin with a letter. <br/>

##### (e) double Double = 3.14;
Valid. `double` is a reserved keyword, but the identifiers are case-sensitive. <br/>

## Exercises Section 2.2.4
### Exercise 2.13
#### What is the value of j in the following program?
```c++
int i = 42;
int main()
{
	int i = 100;
	int j = i;
}
```
<br/>
<br/>

`j` gets assigned the value of `i`, which is 100, because a local variable with the same identifier has just been defined and is now in scope, 
effectively  "hiding" the global `i`. To access it, one must provide the `::` scope operator with empty left-hand operand to indicate global scope.

### Exercise 2.14
#### Is the following program legal? If so, what values are printed?
```c++
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
	sum += i;
std::cout << i << " " << sum << std::endl;
```
<br/>
<br/>

It's legal. The first `i` gets defined as 100, but the `for` statement generates another `i` that's only usable inside its body. It runs the following iterations:
```c++
i = 0, sum = 0
i = 1, sum = 1
i = 2, sum = 3
i = 3, sum = 6
i = 4, sum = 10
i = 5, sum = 15
i = 6, sum = 21
i = 7, sum = 28
i = 8, sum = 36
i = 9, sum = 45
```
The second `i` lifespan is spent merely as tool to increment the value of `sum`. In the end of the `for` loop, `sum` retains its value, but the second `i` is obliterated. The first `i` gets printed, along with the value of `sum`: `100 45`.
