// StackFullException.cpp
//
// Implementation file for class StackFullException
// Derived class of class StackException
// Contains standard constructor, overloaded constructor, copy constructor, destructor, and assignment operator.
// Implements function GetMessage(), which is an abstract function in the base class.
//
// Author: Devon Kaberna
//

#include "StackFullException.hpp"	// Header file that contains definition for object called StackException

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Containers
	{
		StackFullException::StackFullException() : StackException() {} // Default constructor

		StackFullException::StackFullException(const StackFullException& source) : StackException(source) {}	// Copy constructor

		StackFullException& StackFullException::operator = (const StackFullException& source) // Assignment operator
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			// Call base class assignment
			StackException::operator= (source);

			return *this;
		}

		StackFullException::~StackFullException() {}  // Destructor

		std::string StackFullException::GetMessage() const  // Return a message string saying the stack is full
		{
			return "Stack is already full!";
		}
	}
}