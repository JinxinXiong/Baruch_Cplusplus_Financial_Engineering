// ArrayException.cpp
//
// Implementation code for class ArrayException
// This class is an abstarct base class that contains a pure virtual function - GetMessage().
// Also contains standard constructor, copy constructor, destructor, and assignment operator.
// They don't do anything at this point since there are no data members, but for best practice, I implemented them anyways.
// Namespace of DevonKaberna::Containers implemented below
//
// Author: Devon Kaberna
//

#include "ArrayException.hpp"	// Header file that contains definition for object called ArrayException

namespace DevonKaberna
{
	namespace Containers
	{
		ArrayException::ArrayException() {} // Constructor.  This class has no specific data members

		ArrayException::ArrayException(const ArrayException& source) {} // Copy constructor

		ArrayException& ArrayException::operator = (const ArrayException& source) // Assignment operator
		{
			if (this == &source)
				return *this;

			return *this;
		}

		ArrayException::~ArrayException() {}	// Destructor
	}
}