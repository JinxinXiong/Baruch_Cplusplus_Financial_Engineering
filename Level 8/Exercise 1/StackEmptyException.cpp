// StackEmptyException.cpp
//
// Implementation file for class StackEmptyException
// Derived class of class StackException
// Contains standard constructor, overloaded constructor, copy constructor, destructor, and assignment operator.
// Implements function GetMessage(), which is an abstract function in the base class.
//
// Author: Devon Kaberna
//

#include "StackEmptyException.hpp"	// Header file that contains definition for object called StackException

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Containers
	{
		StackEmptyException::StackEmptyException() : StackException() {} // Default constructor

		StackEmptyException::StackEmptyException(const StackEmptyException& source) : StackException(source) {}	// Copy constructor

		StackEmptyException& StackEmptyException::operator = (const StackEmptyException& source) // Assignment operator
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			// Call base class assignment
			StackException::operator= (source);

			return *this;
		}

		StackEmptyException::~StackEmptyException() {}  // Destructor

		std::string StackEmptyException::GetMessage() const  // Return a message string saying the stack is empty
		{
			return "Stack is already empty!";
		}
	}
}