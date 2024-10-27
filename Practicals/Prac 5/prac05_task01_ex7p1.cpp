#include <cstddef>
#include <iostream>
#include <array>

using namespace std;

int main()
{
	const size_t numberOfElements{10};
	array<int, numberOfElements> values;

	for (int index{0}; index < values.size(); ++index)
	{
		values[index] = index;
	}

	values[values.size() - 1] = 99;

	cout << "Values array: ";
	for (const auto &value : values)
	{
		cout << value << " ";
	}
	cout << endl;
}