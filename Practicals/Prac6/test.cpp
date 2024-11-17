#include "hr.h"
#include <memory>
#include <vector>

int main()
{
	std::vector<std::unique_ptr<HR::Person>> staff;

	staff.push_back(std::make_unique<HR::Person>("Name", "LastName"));
	staff.push_back(std::make_unique<HR::Employee>(100, "Otis", "Lowe"));
	staff.push_back(std::make_unique<HR::Manager>(101, "AOtis", "BLowe"));
	staff.push_back(std::make_unique<HR::Director>(102, "COtis", "DLowe"));

	for (const auto &person : staff)
	{
		std::cout << person->toString() << std::endl;
	}
}
