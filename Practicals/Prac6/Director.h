#pragma once

#include "Employee.h"
#include <iostream>

namespace HR
{
	class Director : public Employee
	{
	public:
		using Employee::Employee;

		std::string toString() const override { return Employee::toString() + ", Director"; }
	};
}
