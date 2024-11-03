#pragma once

#include <string>
#include <iostream>
#include "Person.h"

namespace HR
{
	class Employee : public Person
	{
	public:
		Employee(int id, std::string firstName, std::string lastName)
			: Person{std::move(firstName), std::move(lastName)}, m_id{id}
		{
			std::cout << "I am Employee" << std::endl;
			std::cout << "id=" << id << std::endl;
		}

		virtual int getID() const { return m_id; }
		virtual void setID(int id) { m_id = id; }

	private:
		int m_id{0};
	};
}
