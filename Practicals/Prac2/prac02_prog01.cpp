#include <iostream>

using namespace std;

// Define the namespace and struct Employee
namespace HR
{
    enum class Title
    {
        Manager,
        SeniorManager,
        Engineer
    };

    // Initialize an employee struct
    struct Employee
    {
        char first_initial;
        char last_initial;
        int employee_number;
        int salary;
        Title title;
    };
}

string title_to_string(HR::Title title)
{
    switch (title)
    {
    case HR::Title::Manager:
        return "Manager";
    case HR::Title::SeniorManager:
        return "Senior Manager";
    case HR::Title::Engineer:
        return "Engineer";
    default:
        return "Unknown";
    }
}

int main()
{

    // Set values for the employee instance
    HR::Employee employee{'J', 'D', 42, 80'000, HR::Title::Manager};

    // Output the values of the employee
    cout << "Employee: " << employee.first_initial << employee.last_initial << endl;
    cout << "Number: " << employee.employee_number << endl;
    cout << "Salary: " << employee.salary << endl;
    cout << "Position: " << title_to_string(employee.title) << endl;
}
