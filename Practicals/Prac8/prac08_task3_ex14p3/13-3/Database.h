#pragma once

#include "Person.h"
#include <vector>
#include <string>
#include <ostream>

class Database
{
public:
    void add(Person person);
    void clear();
    void save(const std::string& filename) const;
    void load(const std::string& filename);
    void outputAll(std::ostream& output) const;

private:
    std::vector<Person> m_persons;
};
