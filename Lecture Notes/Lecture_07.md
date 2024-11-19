# Week 7

## IO

### File Output Example

```c++
#include <iostream>
#include <iomanip>
#include <fstream>

int main() {
    std::ofstream myFile; // ofstream for output, ifstream for input
    myFile.open("exampleWrite.txt");

    int num{10};
    float i{10.3f};
    double j{10.0};

    myFile << "int num = " << num << std::endl;
    myFile << "float i = " << i << std::endl;
    myFile << "double j = " << j << std::endl;

    myFile.close();
}
```

### File Input Example

```c++
#include <iostream>
#include <fstream>

int main() {
    std::ifstream myFile;
    myFile.open("exampleRead.txt");
    int n1, n2;
    std::cout << "Please enter two integers from file: " << std::endl;
    myFile >> n1 >> n2;
    std::cout << "The sum = " ,, n1 + n2 << std::endl;
    myFile.close();
}
```

## Handling Output Errors

When a stream is in its normal usable state, it is said to be "good". The `good()` method can be called directly on a stream to determine whether the stream is currently good:

```c++
if (std::cout.good()) {
    std::cout << "All good" << std::endl;
}
std::cout.flush();
if (std::cout.fail()) {
    std::cerr << "Unable to flush to standard out" << std::endl;
}
```

Streams have a conversion operator to covert to type `bool`. This conversion operator returns the same as `good()`. So, the previous code snippet can be rewritten as follows:

```c++
std::cout.flush();
if (!std::cout) {
    std::cerr << "Unableto flush to standard out" << std::endl;
}
```

