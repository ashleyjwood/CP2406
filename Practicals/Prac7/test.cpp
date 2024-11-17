#include "Person.h"
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
	std::vector<std::unique_ptr<HR::Person>> staff;

	staff.push_back(std::make_unique<HR::Person>("Name", "LastName"));
	staff.push_back(std::make_unique<HR::Person>("John", "Smith"));

	for (const auto &person : staff)
	{
		person->output(std::cout);
	}

	for (const auto &person : staff)
	{
		std::ostringstream output_stream;
		person->output(output_stream);
		std::cout << output_stream.str();
	}

	std::ofstream file("person_output.txt");
	if (file.is_open())
	{
		for (const auto &person : staff)
		{
			person->output(file);
		}
		file.close();

		std::cout << "Details written to file 'person_output.txt'" << std::endl;
	}
}
