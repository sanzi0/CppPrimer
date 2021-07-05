# Section 2.5
## Exercises Section 2.5.2
### Exercise 2.33
#### Using the variable definitions from this section, determine what happens in each of these assignments:
```c++
// variable definitions
int i = 0;
int &r = i;
auto a = r; // int

const int ci = i, 
const int &cr = ci;

auto b = ci; // int
auto c = cr; // int
auto d = &i; // int*
auto e = &ci; // const int*
auto &g = ci; // const int&
```
```c++
// assignments
a = 42; b = 42; c = 42;
d = 42; e = 42; g = 42;
```
##### (a) `a = 42;` 
42 is successfully assigned to `a`, which has type `int`. <br/> 
	
##### (b) `b = 42;` 
42 is successfully assigned to `b`, which has type `int`. <br/>

##### (c) `c = 42;`
42 is successfully assigned to `c`, which has type `int`. <br/>
	
##### (d) `d = 42;` 
42 can't be assigned to `d`, which has type pointer to `int`. (`int*`) <br/>

##### (e) `e = 42;` 
42 can't be assigned to `e`, which has type pointer to `const int`. (`const int*`) <br/>

##### (f) `g = 42;`
42 can't be assigned to `g`, which is a reference to a `const int`, which cannot be assigned to by any means. <br/>

### [Exercise 2.34](/Chapter%202/Section%202.5/ex2.34.cpp)
#### Write a program containing the variables and assignments from the previous exercise. Print the variables before and after the assignments to check whether your predictions in the previous exercise were correct. If not, study the examples until you can convince yourself you know what led you to the wrong conclusion.
<br/>
<br/>

### [Exercise 2.35](/Chapter%202/Section%202.5/ex2.35.cpp)
#### Determine the types deduced in each of the following definitions. Once you’ve figured out the types, write a program to see whether you were correct.
```c++
const int i = 42;
auto j = i; const auto &k = i; auto *p = &i;
const auto j2 = i, &k2 = i;
```
<br/>
<br/>

##### (a) `const int i = 42;`
Type already defined: `const int`. <br/>

##### (b) `auto j = i;`
Type deduced: `int`. <br/>

##### (c) `const auto &k = i;` 
Type deduced: `const int&`. <br/>
	
##### (d) `auto *p = &i;`
Type deduced: `const int*`. <br/>

##### (e) `const auto j2 = i, &k2 = i;`
Type deduced for `j2`: `const int`. <br/>
Type deduced for `k2`: `const int&`. <br/>

## Exercises Section 2.5.3
### Exercise 2.36
#### In the following code, determine the type of each variable and the value each variable has when the code finishes:
```c++
int a = 3, b = 4;
decltype(a) c = a;
decltype((b)) d = a;
++c;
++d;
```
##### (a) `int a = 3, b = 4;`
`a` and `b` have type `int`. Their values are 3 and 4 respectively. <br/>

##### (b) `decltype(a) c = a;`
`c` has type `int`. `c` has value 3. <br/>

##### (c) `decltype((b)) d = a;`
`d` has type `int&` (reference to `int`). `d` is not an object of its own, but merely a reference to `a`. `d` has value 3.

##### (d) `++c;`
Increments `c`. <br/>

##### (e) `++d;`
Increments `d`. <br/>

##### Final values:
`a = 4`
`b = 4`
`c = 4`
`d = 4`
<br/>
<br/>

### Exercise 2.37
#### Assignment is an example of an expression that yields a reference type. The type is a reference to the type of the left-hand operand. That is, if `i` is an `int`, then the type of the expression `i = x` is `int&`. Using that knowledge, determine the type and value of each variable in this code:
```c++
int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d = a;
```
##### (a) `int a = 3, b = 4;`
`a` and `b` have type `int`. Their values are 3 and 4 respectively. <br/>

##### (b) `decltype(a) c = a;`
Type deduced: `int`. `c` has now value 3. <br/>

##### (c) `decltype(a = b) d = a;`
Type deduced: `int&`. `d` is now a reference to `a`.

##### Final values:
`a = 3`
`b = 4`
`c = 3`
`d = 3`
<br/>
<br/>

### Exercise 2.38
#### Describe the differences in type deduction between `decltype` and `auto`. Give an example of an expression where `auto` and `decltype` will deduce the same type and an example where they will deduce differing types.
<br/>
<br/>

`decltype` does not leave anything behind, it returns exactly the type of its definition, e.g.
```c++ 
const int a = 5;
decltype (b) = a;
```
In this case, `decltype` deduces `b` to be of the type `const int`. `auto`, however, behaves differently:
```c++
const int a = 5;
auto b = a;
```
`b` is of type `int`, because `auto` ignores top-level `consts`. Here's an example where `auto` and `decltype` deduce the same type:
```c++
int c = 6;
auto d = c;
```
```c++
int c = 7;
decltype (d) = c
```
`decltype` evaluates the result of an expression. It also accepts functions? There's more to it than meets the eye. For now, this simple answer will do.
