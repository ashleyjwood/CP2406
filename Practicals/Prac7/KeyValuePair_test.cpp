#include <string>
#include <iostream>
#include "KeyValuePair.h"

int main()
{
    KeyValuePair<double, std::string> kv1{3.14, "Pi"};
    std::cout << kv1.getKey() << " ≈ " << kv1.getValue() << std::endl;

    KeyValuePair<std::string, int> kv2{"John", 117};
    std::cout << kv2.getKey() << " = " << kv2.getValue() << std::endl;

    // KeyValuePair kv3(42, "The Meaning of Life");
    // std::cout << kv3.getKey() << " = " << kv3.getValue() << std::endl;

    kv1.setKey(1.618);
    kv1.setValue("Phi");
    std::cout << kv1.getKey() << " ≈ " << kv1.getValue() << std::endl;
}
