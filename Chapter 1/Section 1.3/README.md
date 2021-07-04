# Section 1.3
## Exercises Section 1.3
### [Exercise 1.7]()
Compile a program that has incorrectly nested comments.

[Docs](https://docs.microsoft.com/en-us/cpp/build/reference/cl-filename-syntax?view=msvc-160). 
>The filename extension determines how files are processed. C and C++ files, which have the extension .c, .cxx, or .cpp, are compiled. Other files, including .obj files, 
>libraries (.lib), and module-definition (.def) files, are passed to the linker without being processed.

![ex1.7](/assets/ch1/ex1.1.png)

### [Exercise 1.8]() 
Indicate which, if any, of the following output statements are legal:
```
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```
After you’ve predicted what will happen, test your answers by compiling a
program with each of these statements. Correct any errors you encounter.

All of them are legal, except the third one: `std::cout << /* "*/" */;`.

The first two statements represent, indeed, the syntax to form comments. However, they are enclosed within double quotes,
which nullifies their action, effectively being interpreted as string literals to be printed by `cout`. The error lies in the
third statement, where the comment delimiters estabilish a comment solely containing the first double quotes, leaving the second ones unaffected.
Therefore, the compiler complains we are missing the closing quotes. We need to append them so that `*/` is correctly considered as
a string literal and gets printed. The fourth statement comments out some quotes, but at the center, `/*` survives and will
be printed out normally.
