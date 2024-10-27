#include <cstddef>
#include <iostream>

using namespace std;

int main()
{
	const size_t numberOfElements{10};
	int *values{new int[numberOfElements]};

	for (int index{0}; index < numberOfElements; ++index)
	{
		values[index] = index;
	}

	values[9] = 99;

	for (int index{0}; index <= numberOfElements - 1; ++index)
	{
		cout << values[index] << " ";
	}
}