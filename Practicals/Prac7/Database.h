#pragma once

#include "Person.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>

namespace HR
{
    class Database
    {
    public:
        Database() = default;

        // Add a person to the database
        void add(std::unique_ptr<Person> person)
        {
            m_people.push_back(std::move(person));
        }

        // Save all people to the specified file (overwrites the file if it exists)
        void save(const std::string& filename) const
        {
            std::ofstream file(filename);
            if (file.is_open())
            {
                for (const auto& person : m_people)
                {
                    person->output(file);
                    file << std::endl;  // Separate each person's output with a newline
                }
            }
            else
            {
                std::cerr << "Failed to open file for writing." << std::endl;
            }
        }

        // Load people from a file
        void load(const std::string& filename)
        {
            std::ifstream file(filename);
            if (file.is_open())
            {
                m_people.clear();  // Clear the current database before loading

                std::string firstName, lastName, initials;
                while (std::getline(file, firstName) && std::getline(file, lastName) && std::getline(file, initials))
                {
                    add(std::make_unique<Person>(firstName, lastName, initials));
                }
            }
            else
            {
                std::cerr << "Failed to open file for reading." << std::endl;
            }
        }

        // Clear all people from the database
        void clear()
        {
            m_people.clear();
        }

        // Output all persons' details
        void outputAll(std::ostream& out) const
        {
            for (const auto& person : m_people)
            {
                person->output(out);
                out << std::endl;  // Separate each person's output with a newline
            }
        }

    private:
        std::vector<std::unique_ptr<Person>> m_people;  // Stores all the persons
    };
}
