// module article_citations;

// import <iostream>;
// import <fstream>;
// import <string>;
// import <stdexcept>;

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

#include "ArticleCitations.h"

ArticleCitations::ArticleCitations(string_view filename)
{
	// All we have to do is read the file.
	readFile(filename);
}

ArticleCitations::ArticleCitations(const ArticleCitations &src)
{
	copy(src);
}

ArticleCitations &ArticleCitations::operator=(const ArticleCitations &rhs)
{
	// Check for self-assignment.
	if (this == &rhs)
	{
		return *this;
	}
	// Free the old memory.
	delete[] m_citations;
	// Copy the data.
	copy(rhs);

	return *this;
}

void ArticleCitations::copy(const ArticleCitations &src)
{
	// Copy the article name, author, etc.
	m_article = src.m_article;
	// Copy the number of citations.
	m_numCitations = src.m_numCitations;
	// Allocate an array of the correct size.
	m_citations = new string[m_numCitations];
	// Copy each element of the array.
	for (int i{0}; i < m_numCitations; i++)
	{
		m_citations[i] = src.m_citations[i];
	}
}

ArticleCitations::~ArticleCitations()
{
	delete[] m_citations;
}

void ArticleCitations::readFile(string_view filename)
{
	// Open the file and check for failure.
	ifstream inputFile{filename.data()};
	if (inputFile.fail())
	{
		throw invalid_argument{"Unable to open file"};
	}

	// Read the article author, title, etc. line.
	getline(inputFile, m_article);

	// Skip the whitespace before the citations start.
	inputFile >> ws;

	int count{0};
	streampos citationsStart{inputFile.tellg()};

	// First count the number of citations.
	cout << "readFile(): counting number of citations" << endl;
	string temp;
	while (getline(inputFile, temp))
	{
		print_stream_state(inputFile);
		if (!temp.empty())
		{
			cout << "Citation " << count << ": " << temp << endl;
			++count;
		}
	}

	// Clear stream state after EOF
	inputFile.clear();

	cout << "Found " << count << " citations" << endl;
	cout << "readFile(): reading citations" << endl;

	if (count != 0)
	{
		m_citations = new string[count];
		m_numCitations = count;

		// Seek back to the start of the citations.
		inputFile.seekg(citationsStart);

		for (count = 0; count < m_numCitations; ++count)
		{
			getline(inputFile, temp);
			if (!temp.empty())
			{
				cout << temp << endl;
				m_citations[count] = temp;
			}
		}
	}
	else
	{
		m_numCitations = -1;
	}

	cout << "readFile(): finished" << endl;
}

const string &ArticleCitations::getArticle() const
{
	return m_article;
}

int ArticleCitations::getNumCitations() const
{
	return m_numCitations;
}

const string &ArticleCitations::getCitation(int i) const
{
	return m_citations[i];
}

void ArticleCitations::print_stream_state(const std::istream &input_stream)
{
	if (input_stream.good())
	{
		std::cout << "Stream state is good" << std::endl;
	}
	if (input_stream.bad())
	{
		std::cout << "Stream state is bad" << std::endl;
	}
	if (input_stream.fail())
	{
		std::cout << "Stream state is fail" << std::endl;
	}
	if (input_stream.eof())
	{
		std::cout << "Stream state is eof" << std::endl;
	}
}
