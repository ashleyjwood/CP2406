#include <vector>
#include <iostream>
#include <set>
#include <string>
#include <algorithm>

const int MAX_NUMBER{1'000'000};

std::vector<int> sieve_of_eratosthenes(int limit)
// Initialise a boolean array "prime[0..n]" and fill all entries it as true.
// A value in prime[i] will finally be false if i is Not a prime, else true.

{
    std::vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p <= limit; ++p)
    // If prime[p] is not changed, then it is a prime
    {
        if (is_prime[p])
        {
            // Update all multiples of p
            for (int i = p * p; i <= limit; i += p)
            {
                is_prime[i] = false;
            }
        }
    }

    std::vector<int> prime_numbers;
    for (int p = 2; p <= limit; ++p)
    {
        if (is_prime[p])
        {
            prime_numbers.push_back(p);
        }
    }

    return prime_numbers;
}

bool is_circular_prime(int n, const std::set<int> &primes_set)
{
    std::string string = std::to_string(n);
    int string_length = string.length();

    for (int i = 1; i < string_length; ++i)
    {
        std::rotate(string.begin(), string.begin() + 1, string.end()); // Shift the first char to the end of the string
        int rotated_number = std::stoi(string);                        // Convert string to integer (s to i)

        // Check if the rotated number is prime, return false if not
        if (primes_set.find(rotated_number) == primes_set.end())
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int circular_prime_count{0};

    // Generate prime numbers
    auto primes = sieve_of_eratosthenes(MAX_NUMBER);
    auto primes_set = std::set<int>(primes.begin(), primes.end());

    // Check each prime to see if circular
    for (int prime : primes)
    {
        if (is_circular_prime(prime, primes_set))
        {
            ++circular_prime_count;
            std::cout << "Circular Prime: " << prime << ", Count: " << circular_prime_count << std::endl;
        }
    }

    std::cout << "DONE" << std::endl;
}