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

    // Add some persons to the database
    db.add(std::make_unique<HR::Person>("John", "Doe", "JD"));
    db.add(std::make_unique<HR::Person>("Jane", "Smith", "JS"));

    // Output all persons to the console
    std::cout << "Outputting all persons:" << std::endl;
    db.outputAll(std::cout);

    // Save the database to a file
    db.save("people.txt");

    // Clear the database
    db.clear();

    // Load the database from the file
    db.load("people.txt");

    // Output all persons from the file
    std::cout << "Outputting all persons after loading from file:" << std::endl;
    db.outputAll(std::cout);
}
