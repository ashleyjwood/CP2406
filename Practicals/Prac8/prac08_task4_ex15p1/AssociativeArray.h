#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>

template <typename T>
class AssociativeArray
{
public:
	virtual ~AssociativeArray() = default;

	T &operator[](const std::string &key);
	const T &operator[](const std::string &key) const;

private:
	class Element
	{
	public:
		Element(std::string key, T value)
			: m_key{std::move(key)}, m_value{std::move(value)} {}
		std::string m_key;
		T m_value;
	};

	std::vector<Element> m_data;
};

template <typename T>
T &AssociativeArray<T>::operator[](const std::string &key)
{
	// See if key already exists
	for (auto &element : m_data)
	{
		if (element.m_key == key)
		{
			return element.m_value;
		}
	}

	// If we arrive here, the key doesn't exist yet, add it
	m_data.emplace_back(key, T{});
	// Return reference to the value we just added
	return m_data.back().m_value;
}

template <typename T>
const T &AssociativeArray<T>::operator[](const std::string &key) const
{
	for (const auto &element : m_data)
	{
		if (element.m_key == key)
		{
			return element.m_value;
		}
	}

	// Construct an error message
	std::ostringstream oss;
	oss << "Key '" << key << "' doesn't exist.";
	throw std::invalid_argument{oss.str()};
}
