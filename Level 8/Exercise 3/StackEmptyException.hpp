// StackEmptyException.hpp
//
// Header file for class StackEmptyException
// Derived class of class StackException
// Contains standard constructor, overloaded constructor, copy constructor, destructor, and assignment operator.
// Implements function GetMessage(), which is an abstract function in the base class.
//
// Author: Devon Kaberna
//

#ifndef StackEmptyException_HPP
#define StackEmptyException_HPP

#include "StackException.hpp"  // Header file that contains definition for object called StackException

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Containers
	{
		class StackEmptyException : public StackException
		{
		private:
			// Member data for class StackEmptyException...

		public:
			// Constructors
			StackEmptyException();  // Default constructor
			StackEmptyException(const StackEmptyException& source);	// Copy constructor
			virtual ~StackEmptyException();	// Destructor
			StackEmptyException& operator = (const StackEmptyException& source);	// Assignment operator

			virtual std::string GetMessage() const;  // Return a message string
		};
	}
}
#endif // StackEmptyException_HPP