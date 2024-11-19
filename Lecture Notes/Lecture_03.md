# Week 3

## Structures

A `struct` is a collection of values where components are distict and can have different types.

E.g., a record about a book in a library may contain:
```c++
char title[40];
char author[40];
float value;
int libcode;
```

### Setting Up a Structure Template

A "structure template" is a layout that describes how a structure is put together. For example, a structure for a library book may look like:

```c++
struct book {
    char title[40];
    char author[40];
    float value;
    int libcode;
};
```

- `struct`: reserved keyword to introduce a structure
- book: an optional tag name which follows the keyword `struct` to name the structure declared
- title, author, value, and libcode: the `member` of the structure `book`

The above declares a template, not a variable. **No memory space is allocated**.

The values in one strucutre can be assigned to another:

```c++
struct personTag new_member;
new_member = student;
```

Notation required to reference the members of a structure is `structureVariableName.memberName`. The "." is a member access operator known as the `member operator` (works similar to Python).

## Classes
A class is a user-defined datatype which groups together related pieces of infomation.

### Instances

An instance is an occurence of a class. Different instances can have their own set of values in their fields. Structures, by default, are public. However members of a class must be defined to be either public or private.

```c++
class MITStudent{
    public:
        char *name;
        int studentID;
};

int main() {
    MITStudent student1;
    MITStudent student2;
}
```

To access fields of instances, use `variable.fieldName`.


```c++
class MITStudent{
    public:
        char *name;
        int studentID;
};

int main() {
    MITStudent student1;
    MITStudent student2;
    student1.name = "Geza";
    student1.studentID = 123456789;
    student1.name = "Jesse";
    student1.studentID = 987654321;
    std::cout << "Student1 name is " << student1.name << std::endl;
    std::cout << "Student1 ID is " << student1.studentID << std::endl;
    std::cout << "Student2 name is " << student2.name << std::endl;
    std::cout << "Student2 ID is " << student2.studentID << std::endl;
}
```

## Pointers

A pointer is a variable containing the address of another variable, where a variable is a labelled place to store data. Instead of referring to this data by name, one can refer to it by its `address` in the computer memory.  

Pointers allow you to:
- implement sharing without copying i.e., pass by reference vs pass by copying
- use dynamic memory allocation
- implement complex data structures like linked lists
- have better ease of programming, especially when dealing with strings
- resize the data structure whenever needed

There may be variables which store the addresses of memory locations of some data objects. These variables are called pointers. A `pointer variable` is declared by, for example:
```c++
int *ptrI; // prtI is a pointer. It stores the address of a memory location for an integer
```
The value of a pointer variable is an address. The content of the memory location pointed to by a pointer variable is referred to by using the "indirection operator" `*`.

## Scoping and Memory
Whenever a new variable is declared (`int x`), memory is allocated. The memory can only be freed when the variable goes "out of scope". For example:
```c++
int main() {
    if (true) {
        int x = 5;
    }
    // x is now out of scope, and the memory it used to occupy can be reused
}
```
When a pointer points to a variable that doesn't exist or is no longer accessable, it is called a "dangling pointer". More specifically, a dangling pointer points to memory whose contents are undefined. 

## The `new` operator

The `new` operator is another way to allocated memory, where the memory will remain allocated until you manually de-allocate it. It returns a pointer to the newly allocated memory.

NOTE:
If using `int x;`, the allocation occurs on a region of memory called the `stack`. Whereas if using `new int;`, the allocation occurs on a region of memory caled the `heap`.

## Strings 

`getline()` returns null if it fails, otherwise a pointer to the string is returned. Make sure enough mmemory space is allocated to hold the input string. For example, for the following block of code:

```c++
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Hi, what is your name?" << std::endl;
    std::getline(std::cin, name);
    std::cout << "Hello, " << name << "." << std::endl;
}
```

the output would be as follows:
```
Hi, what is your name?
John Doe
Hello, John Doe.
```
`std::cin` can only handle numbers, so you must use `std::getline()` to handle strings. 

### Length
If you want to get the length of a string, C++ has the `length()` function, which is accessed by dot notation. 


```c++
#include <iostream>
#include <string>

int main() {
    std::string line;
    std::cout << "The length of the string is " << line.length() << "." << std::endl;
    }
```

### Merge
To merge (concatonate) two strings together, you can use the `+` operator.
```c++
#include <iostream>
#include <string>

int main() {
    std::string1{"Problem "};
    std::string2{"Solving"};
    string1 += string2;
    std::cout << "The combined string: " << string1 << std::endl;
    }
```

### Compare
You can find if two strings are the same (case insensitive) by using the `compare()` function. 

```c++
#include <iostream>
#include <string>

int main() {
    std::string string1, string2;
    int result;
    std::cout << "String Comparison:\n";
    do {
        std::cout << "Enter first string: ";
        std::getline(std::cin, string1);
        std::cout << "Enter second string: ";
        std::getline(std::cin, string2);
        result = string1.compare(string2);
        std::cout << "The result is: " << result << std::endl;
    }
}
```

You can also reverse a string by using the `reverse()` function, which takes in the string which you want to reverse.