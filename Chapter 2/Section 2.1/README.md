# Section 2.1
## Exercises Section 2.1.1
### Exercise 2.1
#### What are the differences between `int`, `long`, `long long`, and `short`? Between an unsigned and a signed type? Between a `float` and a `double`?
<br/>
<br/>

An `int` is at least as large as a `short`, a `long` at least as large as an `int` and
`long long` is at least as large as `long`. While this is the truth, as a beginner it's also worth stating the obvious:
`short` is the smallest type. `long long` is the largest. Use accordingly. If you want to store the world population 7,800,000,000 in a `short`, that's no good,
because `signed short` only spans values from -32768 to 32767 inclusive. Using `long long` would solve our problem. Each of these data types have different sizes, 
but all of them are used to define integers. A signed type represents negative and positive values (including zero), 
but an unsigned type can only hold positive values (greater than or equal to zero). A double has more precision with its computations (yields 16 significant figures), 
a float yields less (7 sig figs), and is smaller in size as well.

### Exercise 2.2
#### To calculate a mortgage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type.
<br/>
<br/>

Mortgage principal: `int` <br/> 
Because it's a round number, but not large enough for `long`. <br/>
<br/>
Rate: `float` <br/>
Interest rates are usually decimals. <br/>
<br/>
Payment: `double` <br/>
The monthly payment will end up not being round as well, so we'll need to use floating point types.

## Exercises Section 2.1.2
### Exercise 2.3
#### What output will the following code produce?
```c++
  unsigned u = 10, u2 = 42;
  std::cout << u2 - u << std::endl;
  std::cout << u - u2 << std::endl;
  
  int i = 10, i2 = 42;
  std::cout << i2 - i << std::endl;
  std::cout << i - i2 << std::endl;
  
  std::cout << i - u << std::endl;
  std::cout << u - i << std::endl;
```
<br/>
<br/>

![ex2.3](/assets/ch2/ex2.3.png)

### [Exercise 2.4](/Chapter%202/Section%202.1/ex2.4.cpp) 
#### Write a program to check whether your predictions were correct. If not, study this section until you understand what the problem is.
<br/>
<br/>

## Exercises Section 2.1.3
### Exercise 2.5
#### Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples:
##### (a) 'a', L'a', "a", L"a"
`'a'`: Character literal of type `char`. Is guaranteed to represent one (and only one) narrow character from the machine's basic character set. Size varies. <br/>
`L'a'`: Character literal of type `wchar_t`. Is guaranteed to represent one (and only one) wide character from the machine's extended character set. Size varies. <br/>
`"a"`: String literal of type array of `const char`. Can represent a set of narrow characters. Size varies. <br/>
`L"a"`: String literal of type array of `const wchar_t`. Can represent a set of wide characters. Size varies. <br/>

Note: The data sizes proposed in the book seem outdated. [Here's](https://en.cppreference.com/w/cpp/language/types) the recent stuff. 
Microsoft also has [nice docs](https://docs.microsoft.com/en-us/cpp/cpp/fundamental-types-cpp?view=msvc-160).

##### (b) 10, 10u, 10L, 10uL, 012, 0xC
`10`: integer literal type `int` <br/>
`10u`: integer literal type `unsigned int` <br/>
`10L`: integer literal type `long` <br/>
`10uL`: integer literal type `unsigned long` <br/>
`012`: integer literal in octal form (= 10) type `int` <br/>
`0xC`: integer literal in hexadecimal form (= 12) type `int` <br/>

##### (c) 3.14, 3.14f, 3.14L
`3.14`: floating point literal type `double` <br/>
`3.14f`: floating point literal type `float` <br/>
`3.14L`: floating point literal type `long double` <br/>

All of these represent the same number: `float` has lower precision, `long double` has higher precision, and it's best to not mix them
so as to not lose precision or even change the values drastically.

##### (d) 10, 10u, 10., 10e-2
`10`: integer literal type `int` <br/>
`10u`: integer literal type `unsigned` <br/>
`10.`: floating point literal type `double` <br/>
`10e-2`: floating point literal type `double` (= 0.1) <br/>
	
The first three are all the number 10, the first one admitting negative values,
the second one admitting only positive values including zero, and the third one being a 
floating point number, which is somewhat analogous to decimal numbers. The last literal
is followed by a negative exponent, and evaluates to 0.1.

### Exercise 2.6
#### What, if any, are the differences between the following definitions:
```c++
int month = 9, day = 7;
int month = 09, day = 07;
```
<br/>
<br/>

To use a zero directly followed by some number means this representation is using the octal system. On the second line, `int month = 09` is in error, because
the octal system only comprises the digits 0, 1, 2, 3, 4, 5, 6, 7. Nine in octal is 11. However, `day = 07` is correct octal notation and in decimal means 7.

### Exercise 2.7
#### What values do these literals represent? What type does each have?
##### (a) "Who goes with F\145rgus?\012"
It's a string literal, of type array of `const chars`. 
`\145` is an escape sequence containing the ASCII code for `e` in octal system. 
It can be used exactly like a character literal in C++, and will just output `e`. `\012`
is the ASCII code for `\n` or newline. It's also in octal. <br/>

##### (b) 3.14e1L
This evaluates to 31.4, it's a floating point literal of type `long double`. <br/>

##### (c) 1024f
Illegal. If the floating point literal does not have an exponent, the decimal point is mandatory. <br/>

##### (d) 3.14L
This evaluates to 3.14, it's a floating point literal of type `long double`. <br/>

### [Exercise 2.8](url)
#### Using escape sequences, write a program to print `2M` followed by a newline. Modify the program to print `2`, then a tab, then an `M`, followed by a newline.
<br/>
<br/>
