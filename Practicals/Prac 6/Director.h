#pragma once

#include "Employee.h"
#include <iostream>

namespace HR
{
	class Director : public Employee
	{
	public:
		// Explicitly inherit Employee's constructors.
		using Employee::Employee;
	};
}
