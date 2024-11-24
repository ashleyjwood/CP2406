#include "Database.h"
#include <iostream>
#include <exception>

using namespace std;

int main()
{
    Database db;

    try
    {
        // Trigger 1: Attempt to save to a file without permissions
        try
        {
            db.save("nonexistent_folder/person.db"); // Invalid directory
        }
        catch (const exception &e)
        {
            cerr << "Exception caught: " << e.what() << endl;
        }

        // Trigger 2: Load a nonexistent file
        try
        {
            db.load("nonexistent_file.db");
        }
        catch (const exception &e)
        {
            cerr << "Exception caught: " << e.what() << endl;
        }

        // Add some valid data
        db.add(Person{"John", "Doe"});
        db.add(Person{"Marc", "Gregoire", "MG"});

        // Trigger 3: Save the database to a valid file
        try
        {
            db.save("person.db");
        }
        catch (const exception &e)
        {
            cerr << "Exception caught: " << e.what() << endl;
        }

        // Clear the database
        db.clear();

        // Trigger 4: Output an empty database
        try
        {
            db.outputAll(cout);
        }
        catch (const exception &e)
        {
            cerr << "Exception caught: " << e.what() << endl;
        }

        // Trigger 5: Load malformed data
        try
        {
            db.load("malformed_person.db"); // Ensure the file has bad data for testing
        }
        catch (const exception &e)
        {
            cerr << "Exception caught: " << e.what() << endl;
        }
    }
    catch (const exception &e)
    {
        cerr << "Unhandled exception: " << e.what() << endl;
    }

    return 0;
}
