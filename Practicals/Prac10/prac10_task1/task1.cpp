#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> values{2, 5}, second_vector{0, 1}, third_vector;

    values.insert(values.begin() + 1, 3); // Insert 3 at the second position
    values.insert(values.begin() + 2, 4); // Insert 4 at the third position

    values.insert(values.begin(), second_vector.begin(), second_vector.end()); // Insert the contents of second_vector at the beginning of values

    for (auto reverse_values = values.rbegin(); reverse_values != values.rend(); ++reverse_values)
    {
        third_vector.push_back(*reverse_values); // Insert elements in reverse order
    }

    std::cout << "Contents of third_vector: ";
    for (const int &val : third_vector)
    {
        std::cout << val << " ";
    }
}
