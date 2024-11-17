#include <iostream>
#include "employee.h"

using namespace std;

int main()
{
	// create and populate an employee
	Employee anEmployee;
	anEmployee.first_initial = 'J';
	anEmployee.last_initial = 'D';
	anEmployee.employee_number = 42;
	anEmployee.salary = 80000;


	// output the values of an employee
	cout << "Employee: " << anEmployee.first_initial << anEmployee.last_initial << endl;
	cout << "Number: " << anEmployee.employee_number << endl;
	cout << "Salary:" << anEmployee.salary << endl;

}
