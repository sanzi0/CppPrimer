# Section 2.3
## Exercises Section 2.3.1
### Exercise 2.15
#### Which of the following definitions, if any, are invalid? Why?
##### (a) `int ival = 1.01;`
Valid, but value will be truncated. <br/>

##### (b) `int &rval1 = 1.01;`
Invalid: initializer of reference must be an object (we can't create references to literals, unless it's `const`. That'll come... later). <br/>

##### (c) `int &rval2 = ival;`
Valid: `rval2` is a reference to `ival`. <br/>

##### (d) `int &rval3;`
Invalid. References must be initialized. <br/>

### Exercise 2.16
#### Which, if any, of the following assignments are invalid? If they are valid, explain what they do.
```c++
int i = 0, &r1 = i; double d = 0, &r2 = d;
```
##### (a) `r2 = 3.14159;`
Valid. Assigns 3.14159 to `d`. <br/>

##### (b) `r2 = r1;`
Valid. Assigns the value of `i` to `d`. Type conversion will happen, from `int` to `double`. <br/>

##### (c) `i = r2;`
Valid. Assigns the value of `d` to `i`. Type conversion will happen, from `double` to `int`. <br/>

##### (d) `r1 = d;`
Valid. Assigns the value of `d` to `i`. Type conversion will happen, from `double` to `int`. <br/>

### Exercise 2.17
#### What does the following code print?
```c++
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```
<br/>
<br/>

`10 10`. Changing the value of the reference is the same as changing the value of the object to which it is bound.

## Exercises Section 2.3.2
### [Exercise 2.18](url)
#### Write code to change the value of a pointer. Write code to change the value to which the pointer points.
<br/>
<br/>

### Exercise 2.19
#### Explain the key differences between pointers and references.
Pointers are objects of their own that hold memory addresses and point to a data type and a specific object of that data type.
References are just aliases for objects, they have no substance, therefore, any modifications to a reference is the 
same as modifying the object to which it is bound.

### Exercise 2.20
#### What does the following program do?
```c++
int i = 42;
int *p1 = &i;
*p1 = *p1 * *p1;
```
<br/>
<br/>

Defines `p1` as a pointer to `i`, and assigns the result of its square to itself, accessing the object through the dereference operator `*`. The result is 1,764.

### Exercise 2.21
#### Explain each of the following definitions. Indicate whether any are illegal and, if so, why.
```c++
int i = 0;
```
##### (a) `double* dp = &i;`
Illegal, pointer must have the same type as the object it's pointing to. <br/>

##### (b) `int *ip = i;`
Illegal, doesn't provide the pointer with the address of the variable. <br/>

##### (c) `int *p = &i;`
Legal. Correct syntax for initializing a pointer.

### Exercise 2.22
#### Assuming `p` is a pointer to `int`, explain the following code:
```c++
if (p) // ...
if (*p) // ...
```
<br/>
<br/>

`p` returns the address of the object to which it's pointing. If this address
is equal to zero, condition evaluates as false. In any other case, condition
evaluates as true. <br/>

`*p` returns the value of the object to which it's pointing. If this object
is equal to zero, condition evaluates as false. In any other case, condition
evaluates as true.

### Exercise 2.23
#### Given a pointer p, can you determine whether p points to a valid object? If so, how? If not, why not?
<br/>
<br/>

I don't know. Here's [what I found](https://stackoverflow.com/questions/17202570/c-is-it-possible-to-determine-whether-a-pointer-points-to-a-valid-object).
Apparently, it's a bit more complicated than I thought. Anyway, my answer is you just `CTRL` + click the pointer and go to the place of its definition and verify
what exactly it is pointing to. It can be the address of a normal variable, it can be a `nullptr`, it can be `0` etc.

...It's definitely more complicated than this.

### Exercise 2.24
#### Why is the initialization of `p` legal but that of `lp` illegal?
```c++
int i = 42; void *p = &i; long *lp = &i;
```
<br/>
<br/>

Void pointers can point to any type. Other pointers need to match the type of the object they are pointing to.

## Exercises Section 2.3.3
### Exercise 2.25
#### Determine the types and values of each of the following variables.
##### (a) `int* ip, &r = ip;`
`ip` is an uninitialized pointer to an `int` and has undefined value, `&r` is a reference to `ip` and has undefined value. <br/>

##### (b) `int i, *ip = 0;`
`i` is an uninitialized variable of type `int`, `ip` is a null pointer to an `int`. <br/>

##### (c) `int* ip, ip2;`
`ip` is an uninitialized pointer to an `int` and has undefined value, `ip2` is an uninitialized variable of type `int` and its value depends on 
whether it's defined in a function block or globally.
