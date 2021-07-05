# Section 2.4
## Exercises Section 2.4
### Exercise 2.26
#### Which of the following are legal? For those that are illegal, explain why.
##### (a) `const int buf;`
Illegal, `const` needs to be initialized. <br/>

##### (b) `int cnt = 0;`
Legal. Defines a variable `cnt` of type `int` and initializes it to the value 0. <br/>

##### (c) `const int sz = cnt;`
Legal. Assigns the value of `cnt` to a constant variable `sz` of type `int`. <br/>

##### (d) `++cnt; ++sz;`
First statement is legal: `cnt` can be safely incremented.
Second statement is illegal: `sz` cannot be incremented, for it is a `const`.
<br/>
<br/>

## Exercises Section 2.4.2
### Exercise 2.27
#### Which of the following initializations are legal? Explain why.
##### (a) `int i = -1, &r = 0;`
The first statement is legal, the second, however, is illegal. To make a reference to a literal, the reference has to be `const`. 
Otherwise, the only way to initialize a reference is to provide it with a valid object to which it can refer to. <br/>

##### (b) `int *const p2 = &i2;`
Legal. Creates a `const` pointer `p2` and assigns to it the address of `i2`. 
It can never point anywhere else, but we can change the value of `i2` through it. <br/>

##### (c) `const int i = -1, &r = 0;`
Legal. Initializes a `const` variable of type `int` to the value of -1, and also
initializes a reference to `const` with the integer literal 0. <br/>

##### (d) `const int *const p3 = &i2;`
Legal. Initializes a pointer to `const` (that happens to be a `const` pointer) to a variable `i2`. <br/>

##### (e) `const int *p1 = &i2;`
Legal. Initializes a pointer to `const` to a variable `i2`. <br/>

##### (f) `const int &const r2;`
Illegal, it's using a C++ reserved keyword as an identifier (`const`) and it's missing the assignment operator. Correction: `const int &anotherName = r2;`. <br/>

##### (g) `const int i2 = i, &r = i;`
Legal. Assigns the value of `i` to a constant integer `i2`, and initializes a reference `r` to the value of `i`.
<br/>
<br/>

### Exercise 2.28
#### Explain the following definitions. Identify any that are illegal.
##### (a) `int i, *const cp;`
Illegal. `const` pointer `cp` is uninitialized. Initialization of `const` pointers is mandatory. <br/>

##### (b) `int *p1, *const p2;`
Illegal. `const` pointer `p2` is uninitialized. Initialization of `const` pointers is mandatory. <br/>

##### (c) `const int ic, &r = ic;`
Illegal. `const int ic` is uninitialized. Initialization of `const` variables is mandatory. <br/>

##### (d) `const int *const p3;`
Illegal. `const` pointer `p3` is left uninitialized. <br/>

##### (e) `const int *p;`
Legal, but not recommended. Pointer `p` is left uninitialized. Initialization of pointers to `const` are optional, since they can point anywhere. 
However, at the moment of definition, its value is undefined, which leads to undefined behavior.
<br/>
<br/>

### Exercise 2.29
#### Using the variables in the previous exercise, which of the following assignments are legal? Explain why.
```c++
// variables
int i, *const cp;          
int *p1, *const p2;         
const int ic, &r = ic;      
const int *const p3;        
const int *p;
```
##### (a) `i = ic;`
Legal. Despite being a `const int`, `ic`'s value can be safely assigned to `i`. <br/>

##### (b) `p1 = p3;`
Legal. Despite being a `const` pointer, `p3`'s address can be safely assigned to `p1`. <br/>

##### (c) `p1 = &ic;`
Illegal. `p1` isn't a pointer to `const`, therefore, it cannot point to a `const int` (or hold the address of a `const` object, which is a better answer
to this, but it's literally what is written in the book so I thought I'd change it up a bit). <br/>

##### (d) `p3 = &ic;`
Illegal. `p3` is uninitialized, and as a `const` pointer, initializing it is mandatory. Now then, even if it was initialized to the proper 
`const int` it demands, assigning anything to it after this (like the exercise proposes) is impossible, even though `ic` is a `const int`. <br/>
	
##### (e) `p2 = p1;`
Illegal. `p2` is a `const` pointer, therefore, it's not possible to assign it new addresses to point to. <br/>

##### (f) `ic = *p3;`
Illegal. `ic` is a `const int`, therefore, it's not possible to assign new values to it other than the one it was initialized with.
<br/>
<br/>

## Exercises Section 2.4.3
### Exercise 2.30
#### For each of the following declarations indicate whether the object being declared has top-level or low-level `const`.
```c++
const int v2 = 0; int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```
##### (a) `const int v2 = 0;`
`v2` has top-level `const`. It is not possible to change it. <br/>

##### (b) `int v1 = v2;`		
`v2` is assigned to `v1`. Top-level `const` in `v2` is ignored. <br/>
 
##### (c) `int *p1 = &v1;`
Regular pointer to regular variable. No `const` identified. <br/>

##### (d) `int &r1 = v1;`
Regular reference to regular variable. No `const` identified. <br/>

##### (e) `const int *p2 = &v2;`
Pointer to `const` `p2` has low-level `const`, and `v2` has a high-level `const`. <br/>

##### (f) `const int *const p3 = &i;` 
`const` pointer to `const` `p3` has a high-level and low-level `const` simultaneously. <br/>

##### (g) `const int &r2 = v2;`
`const` in references is always low-level.
<br/>
<br/>

### Exercise 2.31
#### Given the declarations in the previous exercise determine whether the following assignments are legal. Explain how the top-level or low-level `const` applies in each case.
```c++
r1 = v2;
p1 = p2; p2 = p1;
p1 = p3; p2 = p3;
```
##### (a) `r1 = v2;`
Legal. Copying value from top-level `const` `v2` to regular reference to `r1`. The value is copied normally, the top-level `const` is ignored. `r1` assumes
the value of `v2`. `r1` can be freely changed, while `v2` remains an unchangeable constant. <br/>

##### (b) `p1 = p2;`
Illegal. Copying address from pointer to `const` `p2` to regular pointer `p1`. `p2` has a low-level `const` and `p1` does not. The statement is illegal,
a regular pointer cannot hold the address to a `const` variable. In other words, there should be a low-level `const` present in `p1` for the copy to be successful. <br/>

##### (c) `p2 = p1;`
Legal. Assigning the address of a regular pointer `p1` to a pointer to `const` `p2`.
`p2` has a low-level `const`, and `p1` has no `const`. Conversion takes place (what exactly gets converted?),
from `int*` to `const int*` (probably the address).
OBSERVATIONS: one thing is certain, we won't be able to change `v1` through `p2`. <br/>

##### (d) `p1 = p3;`
Illegal. Assigning the address from `const` pointer to `const` `p3` to regular pointer `p1`.
`p3` has a top-level and low-level `const` simultaneously, while `p1` has none. A regular pointer cannot hold the address to a `const` object. 
In other words, there should be a low-level `const` present in `p1` for the copy to be successful. <br/>

##### (e) `p2 = p3;`
Legal. Assigning the address from `const` pointer to `const` `p3` to pointer to `const` `p2`. `p3` has a top-level and low-level `const` simultaneously, while `p2` only has
a low-level `const`. The top-level `const` is ignored, and the assignment is successful, `p2` now points to wherever `p3` pointed to, i.e. a `const` object.
<br/>
<br/>

## Exercises Section 2.4.4
### Exercise 2.32 
#### Is the following code legal or not? If not, how might you make it legal?
```c++
int null = 0, *p = null;
```
<br/>
<br/>

Surprisingly, `null` is not a C++ reserved keyword. I remember reading somewhere that `NULL` is defined in some preprocessor directive of some header. It's probably
not a good idea to be using it to name stuff, but by including just `iostream`, Visual Studio accepts
`null` as a valid identifier. Now, to fix the code, the address-of operator (`&`) is appended to the pointer's initializer so it gets the address of the variable:
```c++
int null = 0;
int *p = &null;
```
