// #include "..\Prac6\hr.h"
#include "Person.h"
#include <memory>
#include <vector>

int main()
{
	std::vector<std::unique_ptr<HR::Person>> staff;

	staff.push_back(std::make_unique<HR::Person>("Name", "LastName"));
	staff.push_back(std::make_unique<HR::Person>("John", "Smith"));

    for (const auto &person : staff)
    {
        person->output();
    }
}
