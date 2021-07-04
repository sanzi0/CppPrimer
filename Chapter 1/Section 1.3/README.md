# Section 1.3
## Exercises Section 1.3
### [Exercise 1.7](/Chapter%201/Section%201.3/ex1.7.cpp)
#### Compile a program that has incorrectly nested comments.
<br/>
<br/>

![ex1.7](/assets/ch1/ex1.7.png)

### [Exercise 1.8](/Chapter%201/Section%201.3/ex1.8.cpp) 
#### Indicate which, if any, of the following output statements are legal:
```
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```
#### After you’ve predicted what will happen, test your answers by compiling a program with each of these statements. Correct any errors you encounter.
<br/>
<br/>

All of them are legal, except for the third one: `std::cout << /* "*/" */;`.

The first two statements represent, indeed, the syntax to form comments. However, they are enclosed within double quotes,
which nullifies their action, effectively being interpreted as string literals to be printed by `cout`. The error lies in the
third statement, where the comment delimiters estabilish a comment solely containing the first double quotes, leaving the second ones unaffected.
Therefore, what is left as source code is this: `" */;`. It looks like a string literal, but the compiler complains we are missing the closing quotes. 
We need to append them to this code so that `*/` is correctly considered as a string literal and gets printed. 
And finally, the fourth statement comments out some quotes, but at the center, `/*` survives and will
be printed out normally.
