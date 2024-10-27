#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	// A vector to store all values.
	vector<double> values;

	// Ask the user to enter values until 0 is entered.
	cout << "Input values, one at a time followed by Enter:" << endl;
	while (true) {
		double value;
		cin >> value;
		if (value == 0.0) {
			break;
		};
		values.push_back(value);
	};

	// Format the values in a table with a couple of columns.
	for (const auto value: values) {
		cout << setw(15) << value
				<< setw(15) << fixed << setprecision(2) << value
				<< setw(15) << scientific << value << endl;
	}
}
