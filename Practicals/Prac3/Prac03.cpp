#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Replace all occurrences of needle in haystack
string replace_all_occurrences(const string &haystack,
                               const string &needle,
                               const string &replacement) {
    string result = haystack;
    size_t position = result.find(needle);

    // Loop until all occurrences are replaced
    while (position != string::npos) {
        result.replace(position, needle.length(), replacement);
        position = result.find(needle, position + replacement.length());
    }

    return result;
}

void floating_point_task() {
}

int main() {
    int choice{};

    for (;;) {
        cout << "Enter '1' for Task 1 (Alphabetical Order of Strings)" << endl;
        cout << "Enter '2' for Task 2 (String Replacement)" << endl;
        cout << "Enter '3' for Task 3 (WIP)" << endl;
        cout << "Enter '4' for Task 4 (Floating Point Numbers)" << endl;
        cout << "Your choice: " << endl;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                // TASK 1: Alphabetical order of two strings
                string first_string, second_string;

                cout << "TASK 1: Alphabetical Order" << endl;

                // Ask the user for two strings to compare
                cout << "Enter the first string: " << endl;
                getline(cin, first_string);

                cout << "Enter the second string: ";
                getline(cin, second_string);

                // Compare and print the strings in alphabetical order
                cout << "Strings in alphabetical order:" << endl;
                if (first_string < second_string) {
                    cout << first_string << "\n" << second_string << endl;
                } else {
                    cout << second_string << "\n" << first_string << endl;
                }
                break;
            }

            case 2: {
                // TASK 2: String replacement
                string haystack, needle, replacement;

                cout << "TASK 2" << endl;

                // Get input from the user
                cout << "Enter the source string (haystack): " << endl;
                getline(cin, haystack);

                cout << "Enter the string to find (needle): " << endl;
                getline(cin, needle);

                cout << "Enter the replacement string: " << endl;
                getline(cin, replacement);

                // Call the replace function and print the result
                const string modifiedString = replace_all_occurrences(haystack, needle, replacement);

                cout << "Modified string: " << modifiedString << endl;
                break;
            }

            case 3: {
                cout << "Task 3 relies on Task 2, which I can't get to work.\n" << endl;
                continue;
            }

            case 4: {
                vector<double> numbers;
                double input;
                constexpr int ColumnWidth{15};

                cout << "Enter floating-point numbers (enter 0 to stop):" << endl;

                // Get numbers from the user
                for (;;) {
                    cout << "Number: ";
                    cin >> input;
                    if (input == 0)
                        break;
                    numbers.push_back(input); // Store the number in the vector
                }

                // Display the numbers in a formatted table
                cout << "\nFormatted Table of Numbers:\n";
                cout << setw(ColumnWidth) << "Original" << setw(ColumnWidth) << "Fixed" << setw(ColumnWidth) <<
                        "Scientific" << endl;
                cout << "-------------------------------------------------------------" << endl;

                // Print each number in different formats
                for (const double number: numbers) {
                    cout << setw(ColumnWidth) << number
                            << setw(ColumnWidth) << fixed << setprecision(2) << number
                            << setw(ColumnWidth) << scientific << number << endl;
                }
                break;
            }

            default:
                cout << "Invalid choice! Please enter 1-4." << endl;
                continue;
        }

        break;
    }
}
