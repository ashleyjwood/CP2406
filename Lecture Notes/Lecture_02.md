<div style='text-align: justify;'>

<!-- TOC -->

* [Week 2](#week-2)
	* [Ch01Pt05](#ch01pt05)
		* [Structured Bindings](#structured-bindings)
		* [Loops](#loops)
			* [While loop](#while-loop)
			* [For loop](#for-loop)
			* [Range-Based For loop](#range-based-for-loop)
			* [Initialiser Lists](#initialiser-lists)
		* [C++ as an Object-Oriented Language](#c-as-an-object-oriented-language)
			* [Scope](#scope)
			* [Uniform Initialisation](#uniform-initialisation)
	* [Ch01Pt06](#ch01pt06)
		* [Pointers and Dynamic Memory](#pointers-and-dynamic-memory)
		* [Working with Pointers](#working-with-pointers)
		* [Dynamically Allocated Arrays](#dynamically-allocated-arrays)
	* [Ch01Pt07](#ch01pt07)
		* [Constants](#constants)
			* [`const` as a Qualifier for a Type](#const-as-a-qualifier-for-a-type)
			* [`const` with Pointers](#const-with-pointers)
			* [`const` to Protect Parameters](#const-to-protect-parameters)
			* [`const` Methods](#const-methods)
			* [The `constexpr` Keyword](#the-constexpr-keyword)
		* [References](#references)
			* [Reference-to-`const`](#reference-to-const)
	* [Ch01Pt08](#ch01pt08)
		* [Structure Bindings and References](#structure-bindings-and-references)
		* [Reference Data Members](#reference-data-members)
		* [Reference Parameters](#reference-parameters)
			* [Using an output parameter](#using-an-output-parameter)
			* [Returning a value](#returning-a-value)
		* [Pass-by-reference-to-`const`](#pass-by-reference-to-const)
		* [Pass-by-Reference vs. Pass-by-Value](#pass-by-reference-vs-pass-by-value)
		* [Reference Return Values](#reference-return-values)
		* [Deciding Between References and Pointers](#deciding-between-references-and-pointers)

<!-- TOC -->

# Week 2

## Ch01Pt05

### Structured Bindings

Structured bindings allow you to declare multiple variables that are initialised with elements from, for example, an
`array`, `struct`, or `pair`.
Example:

```
array values { 11, 22, 33 };
auto [x, y, z] { values };
```

NOTE:

- You have to use the `auto` keyword for structured bindings
- The number of variables declared with the structured binding has to match the number of values in the expression on
  the right.
- Structured bindings also work with `struct`s **only if all non-static members are public**

Example of Structured Bindings with a struct:

```
struct Point { double m_x, m_y, m_z; };
Point point;
point.m_x = 1.0; point.m_y = 2.0; point.m_z = 3.0;
auto [x, y, z] { point };
```

### Loops

#### While loop

Similar to Python in syntax and structure.

#### For loop

Similar to Python but with more flexibility in syntax.

#### Range-Based For loop

The ranged-based for loop allows for iteration over elements of **all containers in the Standard Library** (e.g.,
`std::array`, `vector`). The key difference with range-based for loops is that it iterates over the elements _without
making copies_ so long as a reference variable is used, making it much more memory efficient. (This will be covered in
more detail later on.)

#### Initialiser Lists

Initialiser lists are defined in `<initializer_list>` and **make it easy to write functions that can accept a variable
number of arguments**. The `std::initializer_list` type is a class template, and so it requires you to specify the type
of elements in the list between angle brackets, similar to how you specify the type of object stored in a `vector`.
The following example shows how to use an initialiser list:

```
#include <initializer_list>
#include <iostream>

int get_total(std::initializer_list<int> values) {
    int total { 0 };
    for (int value : values) {
        total += value;
    }
    return total;
}

int main() {
    std::cout << get_total({ 1, 2, 3, 4 }) << std::endl;  // Outputs 10
}
```

### C++ as an Object-Oriented Language

The definition begins by declaring the class name. Inside a set of curly braces, the _data members_ (properties /
arguments) of the class and its _methods_ (behaviours / functions) are declared. Each data member and method is
associated with a particular _access level_: `public`, `protected`, or `private`. These labels can occur in any order
and can be repeated. Members that are `public` can be accessed from outside the class, while members that are `private`
cannot. **It is recommended to make all your data members `private`** and only give access to them with `public` or
`protected` getters and setters (discussed later on).

```
#include <string>

class AirlineTicket {
public:
    AirlineTicket();
    ~AirlineTicket();

    double calculate_price_in_dollars();

    std::string get_passenger_name();
    void set_passenger_name(const std::string& name);

    int get_number_of_miles();
    void set_number_of_miles(int miles);

    bool has_elite_super_rewards_status();
    void set_has_elite_super_rewards_status(bool status);

private:
    std::string passenger_name;
    int number_of_miles;
    bool elite_super_rewards_status;
};
```

The method that has the same name as the class with no return type is a _constructor_. It is automatically called when
an object of the class is created. The method with a tilde (~) character followed by the class name is a _destructor_.
it is automatically called when the object is destroyed.

There are several ways to initialise data members of a class. One way is to put the initialisations in the body of the
constructor, as shown below:

```
AirlineTicket::AirlineTicket()
{
    // Initialize data members.
    passenger_name = "Unknown Passenger";
    number_of_miles = 0;
    has_elite_super_rewards_status = false;
}
```

However, if the constructor is only initialising data members without doing anything else, then there is actually no
real need for a constructor because data members can be initialised directly inside a class definition, also known as
_in-class initialisers_. For example, instead of writing an `AirlineTicket` constructor, you can modify the data members
in
the class definition to initialise them as follows:

```
private:
	std::string passenger_name { "Unknown Passenger" };
	int number_of_miles { 0 };
	bool has_elite_super_rewards_status { false }
```

If your class additionally needs to perform some other types of initialisation, such as opening a file, allocating
memory, etc., then you still need to write a constructor to handle those initialisations. In this case, the destructor
`~AirlineTicket` wouldn't do anything, as destructors are only required if you need to perform some cleanup, such as
closing files or freeing memory allocated by the constructor.

#### Scope

In C++, _scope_ defines where a name (such as a variable, function, or class) is visible within a program. Scopes are
created using namespaces, function definitions, blocks delimited by curly braces, and class definitions. Variables
declared in loops or conditional statements are only visible within those constructs.

When accessing a name, C++ first checks the nearest enclosing scope, then moves up through progressively larger scopes,
up to the global scope. If the name isn't found in any scope, the compiler raises an undefined symbol error.

C++ provides a way to explicitly specify which scope to use through the _scope resolution operator_ `::`. For example,
if multiple functions with the same name exist in different scopes (global, namespace, class), `::` can be used to
disambiguate which function to call.

Example:

```
class Demo {
    public:
        int get() { return 5; }
};

int get() { return 10; }

namespace NS {
    int get() { return 20; }
}

int main() {
    Demo d;
    println("{}", d.get());     // prints 5
    println("{}", NS::get());   // prints 20
    println("{}", ::get());     // prints 10
    println("{}", get());       // prints 10
}
```

#### Uniform Initialisation

**It is recommended to always use uniform initialisation in C++.**  
In the section "structs" earlier, an `Employee` structure is initialised as follows:

```
Employee an_employee;
an_employee.first_initial = 'J';
an_employee.last_initial = 'D';
an_employee.employee_number = 42;
an_employee.salary = 80'000;
```

With uniform initialisation, this can be rewritten as follows:  
`Employee an_employee { 'J', 'D', 42, 80'000 };`

The definition of `an_employee` automatically calls the constructor of `Employee`. The use of the `=` is optional, so
`Employee an_employee { 'J', 'D', 42, 80'000 };` and `Employee an_employee = { 'J', 'D', 42, 80'000 };` are equivalent.

Uniform initialisation **is not limited** to structures and classes. You can use it to initialise almost anything in
C++. For example, the following code initialised all four variables with value 3:

```
int a = 3;
int b(3);
int c = { 3 };  // Uniform initialization
int d { 3 };    // Uniform initialization
```

## Ch01Pt06

### Pointers and Dynamic Memory

Dynamic memory allows you to build programs with data that is not of a fixed size at compile time. In C++, the
application is divided into two parts—the _stack_ and the _free store_ (or _hip_). One way to visualise the stack is
as a deck of card where the current top card represents the current scope of the program, usually the function that is
currently being executed. All variables declared inside the current function will take up memory in the top stack
frame (or the top "card" of the deck). If the current function calls another function, a new card is put on the deck so
that each function has its own _stack frame_ to work with.

Any parameters passed from the first function to the second
are directly copied into the stack frame. Stack frames provide an isolated memory workspace for each function. When the
function is done running, the stack frame goes away, and all the variables declared within the function no longer
take up memory. That is, variables that are stack-allocated do not need to be deleted by the programmer as it happens
automatically.

If you run something on the stack, you will most likely be running on the CPU chip directly as traversing from CPU to
RAM is much too inefficient. As such, each stack should be small enough to fit on the CPU. Compilers are optimised to be
small enough that they can fit on the CPU.

The _free store_ is an area of memory that is **completely independent** of the current function or stack frame. You can
put variable on the free stock if you want them to exist even when the function in which they were created has
completed. You have to make sure that you deallocate (deleted) any memory that you allocated on the free store. This
does not happen automatically unless you use smart pointers, which are covered later.

Pointers are introduced early because they are much more common in legacy code bases. In new code, however, _raw
pointers_ (or _naked pointers_) are only allowed if there is no ownership involved. Otherwise, you should use one of the
_smart pointers_ explained later.

### Working with Pointers

PLEASE NOTE: For most people, pointers are the most difficult part of C++, so don't expect to understand it instantly.
You may need to read this a few times before everything sinks in. Smart pointers simplify much of this section, but you
need to understand the theory behind pointers as there is a lot of legacy code that does not utilise smart pointers.

You can put anything on the free store by explicitly allocating memory for it. For example, to put an integer on the
free store, you need to allocate memory for it, but first you need to declare a _pointer_: `int* my_integer_pointer;`.
The `*` after the `int` type indicates that the variable you are declaring points to some integer memory. It does not
yet point to anything specific because you haven't assigned it to anything; it is an _uninitialised variable_.
**Uninitialised variables should be avoided at all times**, and especially _uninitialised pointers_ because they point
to
some random place in memory. Working with such pointers will most likely make your program crash, which is why you
should **always declare and initialise your pointers at the same time!** You can initialise them to a null pointer
(`nullptr`) if you don't want to allocate memory right away:  
`int* my_integer_pointer { nullptr };`

A null pointer is a special default value that no valid pointer will ever have and coverts to `false` when used in a
Boolean expression. If you want to point the pointer to something valid, you need to initialise it with the `new`
function:  
`my_integer_pointer = new int;`

In this case, the pointer points to the address of just a single integer value. To access this value, you need to
_dereference_ the pointer. Think of dereferencing as following the pointer's arrow to the actual value on the free
store. To set the value of the newly allocated free store integer, you would use code like the following:  
`*my_integer_pointer = 8;`  
Notice that **this is not the same as setting `my_integer_pointer` to the value `8`**.  
**You are not changing the pointer; you are changing the memory that it points to**.  
If you were to reassign the pointer value, it would point to the memory address `8` which is probably random garbage
that will eventually make your program crash.

After you are finished with your dynamically allocated memory, you need to deallocate the memory using the `delete`
operator. To prevent the pointer from being used after having deallocated the memory it points to, it's recommended to
set it to `nullptr`:

```
delete my_integer_pointer;
my_integer_pointer = nullptr;
```

WARNING: A pointer must be valid **before** it is dereferenced. Dereferencing a null pointer or an uninitialised pointer
causes undefined behaviour. Your program may crash, or it may keep running and start giving strange results.

Pointers don't always need to point to free store memory. You can declare a pointer that points to a variable on the
stack, or even another pointer. To get a pointer to a variable, you used the `&` ("address of") operator:

```
int i { & };
int* my_integer_pointer { &i };  // Points to the variable with the value 8 from above
```

C++ has a special syntax for dealing with pointers to structures or classes. Technically, if you have a pointer to a
structure or a class, you can access its fields by first dereferencing it with `*`, and then using the normal `.`
syntax. For example:

```
Employee* an_employee { get_employee() };
std::cout << (*an_employee).salary << std::endl; 
```

However, this is messy. The -> (arrow) operator lets you perform both the dereference and the field access in one step.
The following code is equivalent, but is easier to read:

```
Employee* an_employee { get_employee() };
cout << an_employee->salary << endl;
```

### Dynamically Allocated Arrays

The free store can also be used to dynamically allocate arrays. You use the `new[]` operator to allocate memory for an
array.

```
int array_size { 8 };
int* my_variable_sized_array { new int[array_size] };
```

This automatically allocates enough memory to hold `array_size` integers. Once the memory has been allocated, you can
work with `my_variable_size_array` as though it were a regular stack-based array:  
`my_variable_size_array[3] = 2;`  
When your code is done with the array, it should remove the array from the free store so that other variables can use
the memory. In order to do this, you use the `delete[]` operator:

```
delete[] my_variable_size_array;
my_variable_size_array = nullptr;
```

**To prevent memory leaks, every call to `new` should be paired with a call to `delete`, and every call to `new[]`
should be paired with a call to `delete[]`. Not calling `delete` or `delete[]`, or mismatching calls, results in memory
leaks or worse.**

## Ch01Pt07

### Constants

The keyword `const` can be used in a few different ways in C++. Since its uses are related, but there differences are
subtle, the differences of `const` can make for excellent interview questions. The compiler enforces that anything
marked as a constant remains unchanged, and any attempt to change it produces an error. When optimisations are enabled,
the compiler can take advantage of this knowledge to produce more efficient code.

#### `const` as a Qualifier for a Type

In the C language, programmers often use `#define` to declare names for values that won't change during the execution of
the program (constants), however, in C++, programmers are encouraged to avoid `#define` in favor of using `const` to
define constants. You can mark any variable `const`, including global variables and class data members. Some examples of
defining `const`s include:

- const int version_number_major { 2 };
- const int version_number_minor { 1 };
- const std::string product_name { "Super Hyper Net Modulator" };
- const double PI { 3.141592653589793238462 };

#### `const` with Pointers

Using constants is straightforward and follows a simple rule: the `const` keyword applies to whatever is immediately to
its left. For example, consider `int const* const ip { nullptr };`. When read from right to left, it indicates that ip
is a constant pointer to a constant integer, with nullptr assigned to it. Both the pointer and the integer it points to
are constant.

The reason this rule becomes confusing is an exception. That is, the first `const` can go before the variable like this:
`const int* const ip { nullptr };`. This "exceptional" syntax is used much more commonly than the other syntax. This
rule can extend to any number of levels of indirection, as in this example:
`const int* const* const* const ip { nullptr };` is a perfectly valid line of code.

#### `const` to Protect Parameters

You can cast a non-`const` variable to a `const` variable. If you are calling a function where you want to ensure that
the function doesn't change the value of an argument you pass in, you can have the function take a `const` parameter. If
the function attempts to change the value of the parameter, it will not compile.

#### `const` Methods

You can mark class methods as `const`, to prevent them from modifying data members of the class. For example, in the
`AirlineTicket` class, the method `bool has_elite_super_rewards_status() const;` is valid because it is a getter
function, meaning it only retrieves information. On the other hand, a setter function like
`void set_elite_super_rewards_status(bool status);` cannot be marked as `const` since it modifies the value of a class
member.

Note: To follow the `const`-correctness principle, it's recommended to declare member functions that do not change any
data members of the object as being `const`. These member functions are also called _inspectors_, compared to `mutators`
for non-`const` member functions.

#### The `constexpr` Keyword

A _constant expression_ is an expression that is evaluated at compile time. When defining an array, the size of the
array needs to be a constant expression. Using the `constexpr` keyword, a function can be defined to allow it to be
called from within a constant expression.  
Example:

```
constexpr int get_array_size() { return 32; }

int main()
{
	int my_array[get_array_size()];
} 
```

Declaring a function as `constexpr` imposes quite a lot of restrictions on what the function can do because the compiler
has to be able to evaluate the function at compile time. For example, a `constexpr` function is allowed to call other
`constexpr` functions, but is not allowed to call any non-`constexpr` functions. Such a function is not allowed to have
any side effects, nor can it throw any exceptions. `constexpr` functions are an advanced feature of C++, and not
discussed further in the textbook.

### References

A _reference_ in C++ is an _alias_ for another variable. All the modifications to the reference change the value of the
variable to which it refers, it is really a pointer to the original variable. If you change the value through either one
of them, the change is visible through the other one as well. **Reference variables must be initialised as soon as they
are created**, like this:

```
int x { 3 };
int& x_ref { x };
```  

Attaching `&` to a type indicates that the variable is a reference. **You cannot declare a reference variable outside
a class definition without initialising it.** Once a reference is initialised to refer to a specific variable, you
cannot change the reference to refer to another variable; you can only change the value of the variable the reference
refers to. `x_ref = &y` does not compile.

#### Reference-to-`const`

Things to note:

- References are `const` by default, in that you can't change to what they refer, however, you can change the value of
  variable they refer to
- You can't create a reference to a reference, so there is usually only one level of indirection with references
	- The only way to get multiple levels of indirection is to create a reference to a pointer

Examples:
The following will compile, as the variable `z` is what is being changed, which in turn changes the value of z_ref.

```
int z;
const int& z_ref { z };
z = 4;  // DOES COMPILE
```

However, the following will **not** compile, as it is trying to change the value of the reference directly;

```
int z;
const int& z_ref { z };
z_ref = 4;  // DOES NOT COMPILE
```

You cannot create a reference to an unnamed value, such as an integer literal, unless the reference is to a `const`
value. Example:

```
int& unnamed_ref_1 { 5 };       // DOES NOT COMPILE
const int& unnamed_ref_2 { 5 }; // Works as expected
```

Taking the address of a reference gives the same result as taking the address of the variable to which the reference
refers. Example:

```
int x { 3 };
int& x_ref { x };
int* x_ptr { &x_ref };  // Address of a reference is pointer to value.
*x_ptr = 100;
```

This code sets `x_ptr` to point to `x` by taking the address of a reference to `x`. Assigning 100 to `*x_ptr` changes
the value of `x` to 100. Writing the comparison `x_ptr == x_ref` will not compile because of a type mismatch; `x_ptr` is
a pointer to an `int`, while `x_ref` is a reference to an `int`. The comparisons `x_ptr == &x_ref` and `x_ptr == &x`
both compile without errors and are both `true`.

## Ch01Pt08

### Structure Bindings and References

Structured bindings were introduced earlier in the chapter. One of the examples given was the following:

```
pair my_pair { "hello", 5 };
auto [some_string, some_int] { my_pair };  // Decompose using structured bindings
```

You can combine structured bindings with references and `const` variables. Example:

```
auto& [some_string, some_int] { my_pair };          // Decompose into references-to-non-const
const auto& [some_string, some_int] { my_pair };    // Decompose into references-to-const
```

### Reference Data Members

Data members of classes can be references. Reference data members cannot be initialised inside the body of a class
constructor, but they must be initialised in the so-called _constructor initialiser_. That is, a constructor initialiser
immediately follows the constructor header and starts with a colon. Example:

```
class MyClass
{
	public:
		MyClass(int& ref) : m_ref { ref } { /* Body of constructor */ }
	private:
		int& m_ref;
};
```

A reference needs to be initialised after the name of the constructor, but before the body of the constructor. If
multiple references must be initialised, they should be separated with a comma, e.g.:
`MyClass(int& ref) : m_ref_1 { ref_1 }, m_ref_2 { ref_2 }, m_ref_3 { ref_3 } { /* Body of constructor */ }`

**Reminder: A reference must always be initialised when it's created. Usually, references are created when they are
declared, but reference data members need to be initialised in the constructor initialiser for the containing class.**

### Reference Parameters

The common / main use of references is for parameters to functions. The default parameter-passing semantics is
pass-by-value: functions receive copies of their arguments. When those parameters are modified, the original arguments
remain unchanged.

**IMPORTANT: By dereferencing the pointer, the function can change the memory that represents the variable even
though that variable isn't in the current stack frame.**

Instead of passing pointers to functions, C++ uses _pass-by-reference_, where parameters are references, instead of
pointers. The following are two implementations of an `add_one()` function. The first one has no effect on the variable
that is passed in because it is passed by value, and thus the function receives a copy of the value passed to it. The
second one uses a reference and thus changes the original variable.

```
void add_one(int i)
{
	i++; // Has no real effect because this is a copy of the original
}

void add_one(int& i)
{
	i++; // Actually changes the original variable
}
```

If a function needs to return an object from a class that's expensive to copy, you might see the function taking a
reference to that object as an input and modifying it, instead of directly returning it. However, it's generally better
to just return the object by value rather than using an output parameter. Example:

#### Using an output parameter

```
class ExpensiveObject {
public:
    ExpensiveObject() { std::cout << "ExpensiveObject created\n"; }
    ExpensiveObject(const ExpensiveObject&) { std::cout << "ExpensiveObject copied\n"; }
    ExpensiveObject& operator=(const ExpensiveObject&) { std::cout << "ExpensiveObject assigned\n"; return *this; }
};

// Function that uses an output parameter (reference to non-const object)
void modifyObject(ExpensiveObject& obj) {
    // Modify the object here
    std::cout << "Modifying ExpensiveObject\n";
}

int main() {
    ExpensiveObject obj;
    modifyObject(obj); // Object passed in and modified
    return 0;
}
```

#### Returning a value

```
class ExpensiveObject {
public:
    ExpensiveObject() { std::cout << "ExpensiveObject created\n"; }
    ExpensiveObject(const ExpensiveObject&) { std::cout << "ExpensiveObject copied\n"; }
    ExpensiveObject& operator=(const ExpensiveObject&) { std::cout << "ExpensiveObject assigned\n"; return *this; }
};

// Function that returns an object by value
ExpensiveObject createObject() {
    ExpensiveObject obj;
    std::cout << "Returning ExpensiveObject by value\n";
    return obj; // Move semantics or Return Value Optimization (RVO) will avoid unnecessary copies
}

int main() {
    ExpensiveObject obj = createObject(); // Object created and returned by value
    return 0;
}
```

**So the recommended way to return objects from a function is to return them by value, instead of using output
parameters.**

### Pass-by-reference-to-`const`

The main value in reference-to-`const` parameters is efficiency. When you pass a value into a function, an entire copy
is made. When you pass a reference, you are really just passing a pointer to the original so the computer doesn't need
to make a copy. By passing a reference-to-`const`, you get the best of both worlds: no copy is made, and the original
variable cannot be changed. References-to-`const` become more important when you are dealing with objects because they
can be large, and making copies of them can have unwanted side effects.

### Pass-by-Reference vs. Pass-by-Value

Pass-by-reference is required when you want to modify the parameter and see those changes reflected in the variable
passed to the function. Pass-by-reference avoids copying the arguments to the function, providing two additional
benefits:

- **Efficiency:** Large objects could take a long time to copy. Pass-by-reference passes only a reference to the object
  into
  the function.
- **Support:** Not all classes allow pass-by-value.

If you want to leverage these benefits but do not want to allow the original objects to be modified, you should mark the
parameters `const`, giving you pass-by-reference-to-`const`.

### Reference Return Values

**WARNING: From a function, never return a reference to a variable that is locally scoped to that function, such as an
automatically allocated variable on the stack that will be destroyed when the function ends.**

### Deciding Between References and Pointers

References in C++ could be considered redundant: everything you can do with references, you can accomplish with
pointers. Here is another example where pass-by-reference comes in handy; it’s a simple swap function to swap the values
of two ints:

```
void swap(int& first, int& second)
{
    int temp { first };
    first = second;
    second = temp;
}
```

You can call it like this:

```
int x { 5 }, y { 6 };
swap(x, y);
```

For example, you could write the earlier shown swap() function like this:

```
void swap(int* first, int* second)
{
    int temp { *first };
    *first = *second;
    *second = temp;
}
```

However, this code is more cluttered than the version with references. References make your programs cleaner and easier
to understand. They are also safer than pointers: it's impossible to have a null reference, and you don't explicitly
dereference references, so you can't encounter any of the dereferencing errors associated with pointers.

**NOTE: Prefer references to pointers; that is, use a pointer only if a reference is not possible.**

**NOTE: Avoid output parameters. If a function needs to return something, just return it by value.**

## Ch01Pt09

### Exceptions

C++ is a flexible language but not a particularly safe one. The compiler will let you write code that scribble on random
memory addresses or tries to divide by zero. One language feature that attempts to add a degree of safety back to the
language is _exceptions_.

One way to handle an error is by returning a special value from the function, such as `nullptr` or an error code.
Exceptions provide a much better mechanism for dealing with problems. Some programmers believe that you should "try to
avoid exceptions as much as possible, the main reason being that exceptions create additional coupling between modules,
which increases the complexity of debugging".

Side note: Exceptions seem to work similarly to Python. Python: try/except; C++: try/catch.

### Typedefs

Before C++11, you had to use `typedef`s to accomplish something similar to type aliases, but in a more convoluted way.
This old mechanism is explained here because you will come across it in legacy code bases.

Just as a type alias, a `typedef` provides a new name for an existing type declaration. For example:
`using int_ptr = int*;` can be written as follows with a `typedef`: `typedef int* int_ptr;`. Type aliases and `typedef`s
are not entirely equivalent though.

**WARNING: Always prefer type aliases over `typedef`s**

### Type Inference

Type inference allows the compiler to automatically deduce the type of an expression. There are two keywords for type
inference: `auto` and `decltype`.

#### The `auto` Keyword

The auto keyword has a number of different uses:

- Deducing a function's return type
- Structure bindings
- Deducing the type of an expression
- Deducing the type of non-type template parameters
- Abbreviated function template syntax
- `decltype(auto)`
- Alternative function syntax
- Generic lambda expressions

`auto` can be used to tell the compiler to automatically deduce the type if a variable at compile time.

**WARNING: Always keep in mind that `auto` strips away reference and `const` qualifiers and thus creates a copy! If you
do not want a copy, use `auto&` or `const auto&`.**



</div>