#include "Database.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>

using namespace std;

void Database::add(Person person)
{
    m_persons.push_back(move(person));
}

void Database::clear()
{
    m_persons.clear();
}

void Database::save(const string &filename) const
{
    ofstream outFile{filename, ios::trunc};
    if (!outFile)
    {
        throw runtime_error("Error: Cannot open file for saving: " + filename);
    }

    for (const auto &person : m_persons)
    {
        outFile << quoted(person.getFirstName()) << quoted(person.getLastName()) << quoted(person.getInitials()) << endl;
    }
}

void Database::load(const string &filename)
{
    ifstream inFile{filename};
    if (!inFile)
    {
        throw runtime_error("Error: Cannot open file for loading: " + filename);
    }

    while (inFile)
    {
        string firstName, lastName, initials;
        if (!(inFile >> quoted(firstName) >> quoted(lastName) >> quoted(initials)))
        {
            if (inFile.eof())
                break; // End of file reached
            throw runtime_error("Error: Malformed line detected in file: " + filename);
        }

        m_persons.emplace_back(move(firstName), move(lastName), move(initials));
    }
}

void Database::outputAll(ostream &output) const
{
    if (m_persons.empty())
    {
        throw runtime_error("Error: Database is empty.");
    }

    for (const auto &person : m_persons)
    {
        person.output(output);
    }
}
