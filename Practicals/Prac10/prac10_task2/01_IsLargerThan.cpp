#include <vector>
#include <iostream>
#include <functional>

// Function to find matches between two vectors based on a matcher and handler
template <typename Matcher, typename MatchHandler>
void find_matches(const std::vector<int> &values1, const std::vector<int> &values2,
				  Matcher matcher, MatchHandler handler)
{
	// Ensure both vectors have the same size
	if (values1.size() != values2.size())
	{
		return;
	}

	// Iterate through the elements of both vectors
	for (size_t i{0}; i < values1.size(); ++i)
	{
		if (matcher(values1[i], values2[i]))
		{
			handler(i, values1[i], values2[i]);
		}
	}
}

// Function to print details about a match
void print_match(size_t position, int value1, int value2)
{
	std::cout << "Match found at position " << position
			  << " (" << value1 << ", " << value2 << ")" << std::endl;
}

int main()
{
	std::vector<int> values1{2, 500, 6, 9, 10, 101, 1};
	std::vector<int> values2{4, 4, 2, 9, 0, 300, 1};

	// Stateless Lambda: Threshold hardcoded as 100
	auto stateless_matcher = [](int value1, int value2)
	{
		return value1 > 100 && value2 > 100;
	};

	std::cout << "Using stateless lambda:" << std::endl;
	find_matches(values1, values2, stateless_matcher, print_match);
	std::cout << std::endl;
	// Stateful Lambda: Threshold passed as a variable
	int threshold{100};
	auto stateful_matcher = [threshold](int value1, int value2)
	{
		return value1 > threshold && value2 > threshold;
	};

	std::cout << "Using stateful lambda:" << std::endl;
	find_matches(values1, values2, stateful_matcher, print_match);
}
