// StackException.cpp
//
// Implementation file for class StackException
// Contains standard constructor, overloaded constructor, copy constructor, destructor, and assignment operator.
// Implements function GetMessage(), which is an abstract function in the base class.
//
// Author: Devon Kaberna
//

#include "StackException.hpp"	// Header file that contains definition for object called StackException

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Containers
	{
		StackException::StackException() {} // Default constructor

		StackException::StackException(const StackException& source) {}	// Copy constructor

		StackException& StackException::operator = (const StackException& source) // Assignment operator
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			return *this;
		}

		StackException::~StackException() {}  // Destructor
	}
}