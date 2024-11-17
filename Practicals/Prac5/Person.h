#pragma once

#include <string>

class Person {
public:
    // Constructor with two parameters
    Person(const std::string& firstName, const std::string& lastName);

    // Getter functions
    std::string getFirstName() const;
    std::string getLastName() const;

    // Setter functions
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);

private:
    std::string m_firstName;
    std::string m_lastName;
};
