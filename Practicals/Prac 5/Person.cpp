#include "Person.h"

// Constructor implementation
Person::Person(const std::string& firstName, const std::string& lastName)
    : m_firstName(firstName), m_lastName(lastName) {}

// Getter implementations
std::string Person::getFirstName() const {
    return m_firstName;
}

std::string Person::getLastName() const {
    return m_lastName;
}

// Setter implementations
void Person::setFirstName(const std::string& firstName) {
    m_firstName = firstName;
}

void Person::setLastName(const std::string& lastName) {
    m_lastName = lastName;
}
