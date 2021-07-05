# Section 2.6
## Exercises Section 2.6.1
### Exercise 2.39
#### Compile the following program to see what happens when you forget the semicolon after a class definition. Remember the message for future reference.
```c++
struct Foo { /* empty */ } // Note: no semicolon
int main()
{
	return 0;
}
```
<br/>
<br/>

![ex2.39](/assets/ch2/ex2.39.png)
<br/>
<br/>

### [Exercise 2.40](/Chapter%202/Section%202.6/Sales_data.h)
#### Write your own version of the `Sales_data` class.
Note: The book wants you to write the `Sales_data` class within the `main` function of your program at this moment. They'll talk about actually creating your header files after the end of the next section of exercises. `Sales_data.h` will be our own version of the original, more elaborated `Sales_item.h` provided by the authors.
<br/>
<br/>

## Exercises Section 2.6.2
### Exercise 2.41
#### Use your `Sales_data` class to rewrite the exercises in § [1.5.1](/Chapter%201/Section%201.5#exercises-section-151) (p. 22), § [1.5.2](/Chapter%201/Section%201.5#exercises-section-152) (p. 24), and § [1.6](/Chapter%201/Section%201.6#exercises-section-16) (p. 25). For now, you should define your `Sales_data` class in the same file as your main function.

##### [Set of transactions](/Chapter%202/Section%202.6/ex2.41-a.cpp), [ISBN sum 1](/Chapter%202/Section%202.6/ex2.41-b.cpp), [ISBN sum 2](/Chapter%202/Section%202.6/ex2.41-c.cpp), [counter](/Chapter%202/Section%202.6/ex2.41-d.cpp) <br/>
###### Test the previous program by giving multiple transactions representing multiple ISBNs. The records for each ISBN should be grouped together.
![ex2.41-e](/assets/ch2/ex2.41-e.png)
<br/>
<br/>

###### Using the `Sales_item.h` (now defined by us within the code itself) header from the Web site, compile and execute the bookstore program presented in this section.
![ex2.41-e2](/assets/ch2/ex2.41-e2.png)
<br/>
<br/>

[Complete bookstore program](/Chapter%202/Section%202.6/ex2.41-e.cpp)
<br/>
<br/>

## Exercises Section 2.6.3
### Exercise 2.42
#### Write your own version of the `Sales_item.h` header and use it to rewrite the exercise from § [2.6.2](/Chapter%202/Section%202.6/README.md#exercises-section-262) (p. 76).
##### [Set of transactions](/Chapter%202/Section%202.6/ex2.42-a.cpp), [ISBN sum 1](/Chapter%202/Section%202.6/ex2.42-b.cpp), [ISBN sum 2](/Chapter%202/Section%202.6/ex2.42-c.cpp), [counter](/Chapter%202/Section%202.6/ex2.42-d.cpp) <br/>
###### Test the previous program by giving multiple transactions representing multiple ISBNs. The records for each ISBN should be grouped together.
![ex2.41-e](/assets/ch2/ex2.41-e.png)
<br/>
<br/>

###### Using the `Sales_item.h` (now `Sales_data.h` written by us) header from the Web site, compile and execute the bookstore program presented in this section.
![ex2.41-e2](/assets/ch2/ex2.41-e2.png)
<br/>
<br/>

[Complete bookstore program (v2.0)](/Chapter%202/Section%202.6/ex2.42-e.cpp)
<br/>
<br/>
