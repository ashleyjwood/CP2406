// import <vector>;
// import <span>;
// import <iostream>;
// import <format>;
// import <functional>;
#include <vector>
#include <iostream>


using namespace std;

template<typename Matcher, typename MatchHandler>
void findMatches(
	const vector<int> &values1, 
	const vector<int> &values2,
	Matcher matcher, MatchHandler handler)
{
	if (values1.size() != values2.size()) { return; } // Both vectors must be same size.

	for (size_t i{ 0 }; i < values1.size(); ++i) {
		if (matcher(values1[i], values2[i])) {
			handler(i, values1[i], values2[i]);
		}
	}
}

void printMatch(size_t position, int value1, int value2)
{
	// cout << format("Match found at position {} ({}, {})",
	// 	position, value1, value2) << endl;
	cout << "Match found at position = " << position << std::endl;
	cout << "value1 = "  << value1 << std::endl;
	cout << "value2 = "  << value2 << std::endl;
}

// class IsLargerThan
// {
// public:
// 	explicit IsLargerThan(int value) : m_value{ value } {}

// 	bool operator()(int value1, int value2) const {
// 		return value1 > m_value && value2 > m_value;
// 	}

// private:
// 	int m_value;
// };

int main()
{
	vector values1{ 2, 500, 6, 9, 10, 101, 1 };
	vector values2{ 4, 4, 2, 9, 0, 300, 1 };

	auto IsLargerThanA{[](int value1, int value2) -> int
					  { return value1 > 100 && value2 > 100; }};
	findMatches(values1, values2, IsLargerThanA, printMatch);

	int MIN_VAL = 100;
	auto IsLargerThanB{[MIN_VAL](int value1, int value2) -> int
					   { return value1 > MIN_VAL && value2 > MIN_VAL; }};
	findMatches(values1, values2, IsLargerThanB, printMatch);


	// from the textbook. 
	findMatches(values1, values2,
		[](int value1, int value2) { return value1 > 100 && value2 > 100; },
		printMatch);

}
