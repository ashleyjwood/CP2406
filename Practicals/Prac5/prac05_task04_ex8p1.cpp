#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
    Person person1("John", "Doe");

    cout << "Person 1: " << person1.getFirstName() << " " << person1.getLastName() << endl;

    person1.setFirstName("Jane");
    person1.setLastName("Smith");

    cout << "Modified Person 1: " << person1.getFirstName() << " " << person1.getLastName() << endl;

    Person *person2 = new Person("Alice", "Johnson");

    // Use `->` instead of a pointer to avoid dereferencing
    cout << "Person 2: " << person2->getFirstName() << " " << person2->getLastName() << endl;

    delete person2;
}
