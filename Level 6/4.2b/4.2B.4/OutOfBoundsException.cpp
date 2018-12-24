// OutOfBoundsException.cpp
//
// Implementation for code class OutOfBoundsException
// Derived class of class ArrayException
// Contains standard constructor, overloaded constructor, copy constructor, destructor, and assignment operator.
// Implements function GetMessage(), which is an abstract function in the base class. 
// Namespace of DevonKaberna::Containers implemented below
//
// Author: Devon Kaberna
//

#include "OutOfBoundsException.hpp"	// Header file that contains definition for object called OutOfBoundsException

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Containers
	{									
		OutOfBoundsException::OutOfBoundsException() : ArrayException() // Default constructor
		{
			m_index = 0; //Default it to zero
		}

		OutOfBoundsException::OutOfBoundsException(int index_num) : ArrayException(), m_index(index_num) {}  // Overload constructor that initializes data member m_index with function argument 

		OutOfBoundsException::OutOfBoundsException(const OutOfBoundsException& source) : ArrayException(source), m_index(source.m_index) {}	// Copy constructor

		OutOfBoundsException& OutOfBoundsException::operator = (const OutOfBoundsException& source) // Assignment operator
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			// Call base class assignment
			ArrayException::operator= (source);

			// Copy state
			m_index = source.m_index;

			return *this;
		}

		OutOfBoundsException::~OutOfBoundsException() {}  // Destructor

		std::string OutOfBoundsException::GetMessage() const  // Return a message string saying the given index is out of bounds
		{
			return "Given index is out of bounds.";
		}
	}
}