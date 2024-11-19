#include "Database.h"
#include "Person.h"
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
	HR::Database db;

	db.add(std::make_unique<HR::Person>("John", "Doe", "JD"));
	db.add(std::make_unique<HR::Person>("Jane", "Smith", "JS"));

	std::cout << "Outputting all persons:" << std::endl;
	db.outputAll(std::cout);

	db.save("people.txt");

	db.clear();

	db.load("people.txt");

	std::cout << "Outputting all persons after loading from file:" << std::endl;
	db.outputAll(std::cout);
}
