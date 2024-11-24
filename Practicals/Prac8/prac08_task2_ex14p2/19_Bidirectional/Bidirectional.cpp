#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <sstream>
#include <stdexcept>

using namespace std;

// Updates the phone number for the given ID in the file
void changeNumberForID(string_view filename, int id, string_view newNumber);

int main()
{
	try
	{
		// Test cases to trigger exceptions
		cout << "Running test cases:\n";

		// Case 1: File doesn't exist
		try
		{
			changeNumberForID("nonexistent.txt", 555, "555-555-5555");
		}
		catch (const exception &e)
		{
			cerr << "Exception caught: " << e.what() << endl;
		}

		// Case 2: ID not found in the file
		try
		{
			changeNumberForID("data.txt", 555, "555-555-5555");
		}
		catch (const exception &e)
		{
			cerr << "Exception caught: " << e.what() << endl;
		}

		// Case 3: Normal behavior
		changeNumberForID("data.txt", 263, "620-777-2517");
		cout << "Number updated successfully.\n";
	}
	catch (const exception &e)
	{
		cerr << "Unhandled exception: " << e.what() << endl;
	}
}

void changeNumberForID(string_view filename, int id, string_view newNumber)
{
	ifstream inputFile(filename.data());
	if (!inputFile)
	{
		throw runtime_error("Error: Could not open file " + string(filename));
	}

	ostringstream buffer;
	string line;
	bool idFound = false;

	// Read each line from the file
	while (getline(inputFile, line))
	{
		istringstream record(line);
		int idRead;
		string number;

		// Try reading the ID and number
		if (record >> idRead >> number)
		{
			if (idRead == id)
			{
				// Replace the line with the updated ID and number
				buffer << idRead << " " << newNumber << "\n";
				idFound = true;
				continue; // Skip adding the old line
			}
		}

		// If the line doesn't match, add it as-is
		buffer << line << "\n";
	}

	inputFile.close();

	if (!idFound)
	{
		throw runtime_error("Error: ID " + to_string(id) + " not found in the file.");
	}

	// Write the updated content back to the file
	ofstream outputFile(filename.data());
	if (!outputFile)
	{
		throw runtime_error("Error: Could not open file for writing " + string(filename));
	}

	outputFile << buffer.str();
	outputFile.close();
}
