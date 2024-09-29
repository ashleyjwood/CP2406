<div style='text-align: justify;'>

<!-- TOC -->
* [Week 1](#week-1)
  * [Ch01Pt01 - Intro](#ch01pt01---intro)
  * [Ch01Pt2 - Namespaces, Literals, and Casting](#ch01pt2---namespaces-literals-and-casting)
    * [Namespaces](#namespaces)
    * [Literals](#literals)
    * [Casting](#casting)
  * [Ch01Pt03 - Operators](#ch01pt03---operators)
    * [Basic operators](#basic-operators)
    * [Enumeration](#enumeration)
    * [Structs](#structs)
      * [Struct example](#struct-example)
  * [Ch01Pt04 - Basic loops, The Conditional Operator, and arrays](#ch01pt04---basic-loops-the-conditional-operator-and-arrays)
    * [If/else statements](#ifelse-statements)
    * [Switch cases](#switch-cases)
      * [Switch case example](#switch-case-example)
      * [Converting a switch case to an if/else statement](#converting-a-switch-case-to-an-ifelse-statement)
    * [The Conditional Operator](#the-conditional-operator)
    * [Logical evaluation operators](#logical-evaluation-operators)
    * [Function](#function)
      * [Function overloading](#function-overloading)
    * [Arrays](#arrays)
<!-- TOC -->

# Week 1
## Ch01Pt01 - Intro

No notes taken. Very basic intro.

## Ch01Pt2 - Namespaces, Literals, and Casting

### Namespaces

Multiple namespaces can be used, but try not to do that because it will likely lead to naming clashes that the namespace
tries to solve in the first place.
You can define one specific function within the namespace to include such as:  
`using std::cout;`  
`cout << "Hello, World!" << std::endl;`

**Never put a using directive or using declaration in a header file at global scope; otherwise, you force it on everyone
who includes your header file.**

You can nest namespaces, e.g., `namespace MyLibraries::Networking::FTP`.  
You can also include a shorthand for the namespace (called _namespace alias_), similar to `import as` in Python.
This is done by: `namespace MyFTP = MyLibraries::Networking::FTP`

### Literals

Numbers can be specified with the following literals (the examples represent the same number, 123):

- Decimal: `123`
	- Prefix: none
- Octal: `0173`
	- Prefix: `0`
- Hex: `0x7B`
	- Prefix: `0x`
- Binary: `0b1111011`
	- Prefix: `0b`

Some other literals include:

- Float: `3.14f` (or `float 3.14`)
	- Uses 4 bytes of memory
- Double: `3.14` (or `double 3.14`)
	- Uses 8 bytes of memory
- Single characters: `a`
	- Uses 1 byte of memory

Digit separators can be used in numeric literals (for better readability) and is denoted as a **single quote**, e.g.:
`23'456'789`

C++ variables are strongly typed, so there is always a specific type. Common types include (byte size can vary depending
on architecture):

- `int` e.g., `int i -7;`
	- Usually 4 bytes
- `short int` e.g., `short int s 14;`
	- Usually 2 bytes
- `long int` e.g., `long l -7L;`
	- Usually 4 bytes
- `long long int` e.g., `long long ll 14LL;`
	- Usually 8 bytes
- `unsigned` can be applied to all of the above and limits the preceding types to values >= 0
- `float` e.g., `float f 7.2f;`
	- Usually 4 bytes
- `double` e.g., `double d 7.2;`
	- Usually 8 bytes
	- **DOUBLE IS THE DEFAULT FOR ALL CONSTANTS**
	- Has double the precision of a float
- `long double` e.g., `long double d 16.98;`
- `char` e.g., `char ch 'm';`
	- Can be signed or unsigned
	- Is unsigned by default
- `char8_t`, `char16_t`, `char32_t` is a single _n_-bit UTF-_n_ encoded Unicode character where _n_ can be 8, 16, or 32
- `wchar_t`
	- A single-width character
- `bool` e.g., `bool b true;`

### Casting

Variables can be converted to other types by _casting_ them. For example, a `float` can be cast to an `int`. The
recommended way is the most verbose but also the cleanest and is done as:  
`float myFloat 3.14f;`  
`int i static_cast<int>(myFloat);`  
Note: Casting can be dangerous as it has the ability to lose information as part of the casting. For example, when
casting from a `float` to an `int`, some precision is lost as this "throws away the fractional part of the number, and
the resulting integer can even be completely wrong". That is, casting from `float` to `int` will truncate everything
after the decimal point.

There are some special floating-point numbers:

- **+/- infinity:** Represents positive and negative infinity, for example the result of dividing a non-zero number by
  zero
- **NaN:** Abbreviation for not-a-number, for example the result of dividing zero by zero, a mathematically undefined
  result

To check whether a given floating-point number is NaN, use `std::isnan()`. To check for infinity, use `std::isinf()`.
Both function are defined in `<cmath>`.

## Ch01Pt03 - Operators

### Basic operators

Operators in C++ can be binary (operate on two expressions), unary (operate on a single expression), or ternary (
operates on three expressions). There is only one ternary operator in C++ called "The Conditional Operator".  
The following are all operators:

- `=`, `!` and `!=`, `+` and `-`, `*` and `/`, `%`, `+=` and `-=`, `*=` and `/=`, and `%=`. These are all standard and
  already understood.
- `++` is a unary operator to increment an expression by 1.
	- If the operator occurs _after_ the expression, the result of the expression is the **un-incremented** value
	- If the operator occurs _before_ the expression, the result of the expression is the **pre-incremented** value
- `--` is the unary operator to decrement an expression by 1.
	- The same logic applies as above.
- `&` and `&=` takes the raw bits of one expression and performs a bitwise `AND` with the other expression
- `|` and `|=` takes the raw bits of one expression and performs a bitwise `OR` with the other expression
- `<<`, `<<=`, `>>`, `>>=` bit-shifts an expression the specified number of places
- `^` and `^=` performs a bitwise `XOR` on two expressions

C++ evaluates `/`, `*`, and `%` first (in left-to-right) order, followed by addition and subtraction, *
*_then bitwise operators_**.
Visually, the operators higher in the list below, have a higher precedence:

- `++` `--` (suffix)
- `!` `++` `--` (prefix)
- `*` `/` `%`
- `+` `-`
- `<<` `>>`
- `&`
- `^`
- `|`
- `=` `+=` `-=` `*=` `/=` `&=` `|=` `^=` `<<=` `>>=`
- There are others, but these are the most common.

### Enumeration

When using `enum` always use `enum class` that way the variables defined within the enum are namespace (class) specific.
This allows for having multiple variables named with the same names, as the class differs the separate variables.  
E.g.,  
`bool ok {false};`  
`enum Status {error, ok};`  
will return an error as `ok` is first defined to be a Boolean variable.  
Whereas the following:  
`bool ok {false};`  
`enum class Status {error, ok};`  
will not return any errors.  
_Therefore, it is recommended to always use strongly typed_ enum class _instead of the old-style type-unsafe_ enum
_enumerations._

### Structs

"It's pretty much identical to say 'class something'. You could say that a struct is a class without functions and
without methods. It is a collection of variables."  
In traditional C++, structs are declared in header files (.h or .hpp) and defined in source files (.cpp). Struct members
are public by default, unlike class members, which are private by default.

#### Struct example

You can declare a struct in a header file (employee.h):

```c++
// employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct Employee {
    char first_initial;
    char last_initial;
    int employee_number;
    int salary;
};

#endif
```

Then, in your source file (main.cpp), include the header and use the struct:

```c++
// main.cpp
#include <iostream>
#include <format>
#include "employee.h"  // Include the employee struct definition

using namespace std;

int main() {
    Employee example_employee;
    example_employee.first_initial = 'J';
    example_employee.last_initial = 'D';
    example_employee.employee_number = 42;
    example_employee.salary = 80000;

    cout << format("Employee: {}{}", example_employee.first_initial, example_employee.last_initial) << endl;
    cout << format("Number: {}", example_employee.employee_number) << endl;
    cout << format("Salary: {}", example_employee.salary) << endl;
}
```

## Ch01Pt04 - Basic loops, The Conditional Operator, and arrays

### If/else statements

```c++
if (i > 4) 
{
// Do something
}
else if (i > 2)
{
// Do something else
}
else
{
// Do something else
}
```

### Switch cases

Any switch statement can be written as an if/else statement, and "is an alternate syntax for performing actions based on
the value of an expression".

#### Switch case example

```c++
switch (menu_item) {
    case open_menu_item:
        // Code to open a file
        break;
    case save_menu_item:
        // Code to save a file
        break;
    default:
        // Code to give an error message
        break;
}
```

#### Converting a switch case to an if/else statement

```c++
if (menu_item == open_menu_item) {
    // Code to open a file
    }
else if (menu_item == save_menu_item) {
    // Code to save a file
    }
else {
	// Code to give an error message
	}        
```

### The Conditional Operator

C++ has one operator that takes three arguments known as the _ternary operator_. It is used as a shorthand conditional
expression of the form "if [something] then [perform action], otherwise [perform some other action]". The following code
outputs "yes" if the variable `i` is greater than 2, and "no" otherwise:  
`cout << ((i > 2) ? "yes" : "no");`

### Logical evaluation operators

Many already known, the ones to note are:

- `==` determines if the left-hand side equals the right-hand side. **Not to be confused with the `=` (assignment)
  operator!**
- `<=>` is a three-way comparison operator, also called the "spaceship operator". E.g., `result = i <=> 0;`
	- This will return three values - something "is less than", something "is equal to", and something "is more than"
	- Not often used
- `!` is a logical `NOT`
- `&&` is a logical `AND`
- `||` is a logical `OR`

C++ uses _short-circuit logic_ (also known as shortcut logic) when evaluating logic expressions. I.e., **once the final
result is certain, the rest of the expression won't be evaluated**.  
E.g., `bool result { bool1 || bool2 || (i > 7) && !done };`  
If `bool1` is found to be `true` then the entire expression must be true, so the other parts aren't evaluated.  
This can save code from doing unnecessary work, however it can be a source of hard-to-find bugs if the later expressions
in some way include the state of the program (for example, by calling a separate function).

### Function

Function declarations are often called _function prototypes_ or _function headers_ to emphasise that they represent how
the function can be accessed, but not the code behind it. Without an actual definition to match a function declaration,
the link stage of the compilation process with fail because code that makes use of the function will be calling
nonexistent code. If a function doesn't return anything, it needs to have a `void` in the declaration of the function.

#### Function overloading

Similar to Python. E.g.:

```c++
int add_numbers(int a , int b) { return a + b; }
double add_number(double a, double b) { return a + b; }
```

When calling add_numbers(), the compiler automatically selects the correct function overload based on the provided
arguments.

```c++
cout << add_numbers(1, 2) << endl;          // Calls the integer version
cout << add_numbers(1.11, 2.22) << endl;    // Calls the double version 
```

### Arrays

In arrays in C/C++, you must define the size of the array when the array is declared, and it must be a constant or a
_constant expression_ (`constexpr`). E.g.:

```c++
int my_array[3];
my_array[0] = 0;
my_array[1] = 0;
my_array[2] = 0;
```

Arrays can be zero-initialised with `int my_array[3] = 0;` or even `int my_array[3]`. An array can be initialised
without specifying the size, and the compiler deduces the size of the array automatically. If you do specify the size of
the array and the initialiser list has fewer elements than the given size, the remaining elements are set to `0`. For
example, the following code sets only the first element in the array to the value `2`, and sets all others to `0`:
`int my_array[3] 2`.

To get the size of a stack-based C-style array, you can use the `std::size()` function. E.g.: `size_t array_size { std::
size(my_array) };`

In C++, it is best to avoid C-style arrays and instead use Standard Library functionality, such as `std::array` and
`vector`. Arrays are a fixed size, and, as such, the size of the array must be specified upon declaration of the array.

A `vector` automatically allocates enough memory to hold its elements. It is also dynamic, meaning that elements can be
added and removed while the program is running (i.e., vectors are mutable whereas arrays are immutable). The following
code demonstrates the basic functionality of a vector:

```c++
// Create a vector of integers
std::vector<int> my_vector = {11, 22};

// Add some more integers to the vector using `push_back()`
my_vector.push_back(33);
my_vector.push_back(44);

// Access elements
cout << format("1st element: {}", my_vector[0]) << endl;
```

**A vector is a generic container which can contain almost any type of object, but all elements in a vector must be of
the same type.**

</div>