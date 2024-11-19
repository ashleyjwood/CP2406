# Week 5

## Memory Management

In modern C++ code, you should avoid low-level memory operations as much as possible in favour of modern constructs such as containers and smart pointers!

When you use the `new` keyword, memory is allocated on the "free store". The following code creates a variable `ptr` on the stack, initialised with `nullptr` and then allocates memory on the free store to which `ptr` points: 

```c++
int *ptr { nullptr };
ptr = new int;
```
this can also be written in one line:
```c++
int *ptr { new int };
```

To free memory on the free store, you use the `delete` keyword with a pointer to the memory as shown here:
```c++
int *ptr { new int };
delete ptr;
ptr = nullptr;
```
**NOTE: `delete` only deallocates memory, but it leaves the pointer intact. It is good practice to set the pointer to `nullptr` to ensure that there are no dangling pointers!**

