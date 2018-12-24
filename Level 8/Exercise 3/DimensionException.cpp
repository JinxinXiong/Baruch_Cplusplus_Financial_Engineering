// DimensionException.cpp
//
// Implementation for code class DimensionException
// Derived class of class ArrayException
// Contains standard constructor, overloaded constructor, copy constructor, destructor, and assignment operator.
// Implements function GetMessage(), which is an abstract function in the base class. 
// Namespace of DevonKaberna::Containers implemented below
//
// Author: Devon Kaberna
//

#include "DimensionException.hpp"	// Header file that contains definition for object called DimensionException

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Containers
	{
		DimensionException::DimensionException() : ArrayException(), m_size(0) {} // Default constructor

		DimensionException::DimensionException(int size) : ArrayException(), m_size(size) {}  // Overload constructor that initializes data member m_size with function argument 

		DimensionException::DimensionException(const DimensionException& source) : ArrayException(source), m_size(source.m_size) {}	// Copy constructor

		DimensionException& DimensionException::operator = (const DimensionException& source) // Assignment operator
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			// Call base class assignment
			ArrayException::operator= (source);

			// Copy state
			m_size = source.m_size;

			return *this;
		}

		DimensionException::~DimensionException() {}  // Destructor

		std::string DimensionException::GetMessage() const  // Return a message string saying two arrays don't have the same size
		{
			return "Two arrays don't have the same size.";
		}
	}
}