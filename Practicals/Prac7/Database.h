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

        void add(std::unique_ptr<Person> person)
        {
            m_people.push_back(std::move(person));
        }

        void save(const std::string &filename) const
        {
            std::ofstream file(filename);
            if (file.is_open())
            {
                for (const auto &person : m_people)
                {
                    person->output(file);
                    file << std::endl;
                }
            }
        }

        void load(const std::string &filename)
        {
            std::ifstream file(filename);
            if (file.is_open())
            {
                m_people.clear();

                std::string firstName, lastName, initials;
                while (std::getline(file, firstName) && std::getline(file, lastName) && std::getline(file, initials))
                {
                    add(std::make_unique<Person>(firstName, lastName, initials));
                }
            }
        }

        void clear()
        {
            m_people.clear();
        }

        void outputAll(std::ostream &out) const
        {
            for (const auto &person : m_people)
            {
                person->output(out);
                out << std::endl;
            }
        }

    private:
        std::vector<std::unique_ptr<Person>> m_people;
    };
}
