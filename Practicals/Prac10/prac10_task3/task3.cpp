#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <tuple>

int main()
{
    const int MAX_PERIMETRE{120};
    const int MAX_NUMBER{MAX_PERIMETRE / 2}; // Half of the maximum perimeter

    // Map to store results: key is perimeter `perimetre`, value is a vector of tuples (a, b, c)
    std::map<int, std::vector<std::tuple<int, int, int>>> result;
    int best_length{};    // Maximum number of solutions for a perimeter
    int best_perimetre{}; // Perimeter with the maximum solutions

    // Loop through possible side lengths `a` and `b`
    for (int a = 1; a <= MAX_NUMBER; ++a)
    {
        for (int b = a; b <= MAX_NUMBER; ++b)
        {
            double c = sqrt(pow(a, 2) + pow(b, 2)); // Calculate hypotenuse
            int integer_c = static_cast<int>(c);    // Convert hypotenuse to an integer

            // Check if `c` is a perfect square and its integer value is equal to `c`
            if (c == integer_c)
            {
                int perimetre = a + b + integer_c; // Calculate the perimeter

                if (perimetre > MAX_PERIMETRE)
                {
                    continue; // Skip if the perimeter exceeds the maximum limit
                }

                // Add the triangle (a, b, c) to the map for perimeter `perimetre`
                result[perimetre].emplace_back(a, b, integer_c);

                // Update the best perimeter if the current perimeter has more solutions
                if (result[perimetre].size() > static_cast<size_t>(best_length))
                {
                    best_length = result[perimetre].size();
                    best_perimetre = perimetre;
                }
            }
        }
    }

    // Print the results for the perimeter with the most solutions
    std::cout << "Perimeter with maximum solutions: " << best_perimetre << std::endl;
    std::cout << "Number of solutions: " << best_length << std::endl;
    std::cout << "Solutions:" << std::endl;

    for (const auto &triangle : result[best_perimetre])
    {
        int a, b, c;
        std::tie(a, b, c) = triangle;
        std::cout << "(" << a << ", " << b << ", " << c << ")" << std::endl;
    }
}
