// StackException.hpp
//
// Header file for class StackException
// Contains standard constructor, overloaded constructor, copy constructor, destructor, and assignment operator.
// Implements function GetMessage(), which is an abstract function in the base class.
//
// Author: Devon Kaberna
//

#ifndef StackException_HPP
#define StackException_HPP

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Containers
	{
		class StackException
		{
		private:
			// Member data for class StackException...

		public:
			// Constructors
			StackException();  // Default constructor
			StackException(const StackException& source);	// Copy constructor
			virtual ~StackException();	// Destructor
			StackException& operator = (const StackException& source);	// Assignment operator

			virtual std::string GetMessage() const = 0;  // Abstract function GetMessage() must be implemented in derived classes
		};
	}
}
#endif // StackException_HPP