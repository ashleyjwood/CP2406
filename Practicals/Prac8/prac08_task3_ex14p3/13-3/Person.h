#pragma once

#include <string>
#include <ostream>

class Person
{
public:
    Person(std::string firstName, std::string lastName)
        : m_firstName(std::move(firstName)),
          m_lastName(std::move(lastName)),
          m_initials(std::string(1, m_firstName[0]) + m_lastName[0]) {}

    Person() = default;

    Person(std::string firstName, std::string lastName, std::string initials)
        : m_firstName(std::move(firstName)),
          m_lastName(std::move(lastName)),
          m_initials(std::move(initials)) {}

    const std::string& getFirstName() const { return m_firstName; }
    const std::string& getLastName() const { return m_lastName; }
    const std::string& getInitials() const { return m_initials; }

    void output(std::ostream& output) const
    {
        output << m_firstName << " " << m_lastName << " (" << m_initials << ")" << std::endl;
    }

private:
    std::string m_firstName;
    std::string m_lastName;
    std::string m_initials;
};
