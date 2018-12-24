// OutOfBoundsException.hpp
//
// Header file for class OutOfBoundsException
// Derived class of class ArrayException
// Contains standard constructor, overloaded constructor, copy constructor, destructor, and assignment operator.
// Implements function GetMessage(), which is an abstract function in the base class.
// Namespace of DevonKaberna::Containers implemented below
//
// Author: Devon Kaberna
//

#ifndef OutOfBoundsException_HPP
#define OutOfBoundsException_HPP

#include "ArrayException.hpp"  // Header file that contains definition for object called ArrayException

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Containers
	{ 
		class OutOfBoundsException : public ArrayException
		{
		private:
			// Member data for class ArrayException that contains erroneous array index
			int m_index;  // Contains erroneous array index

		public:
			// Constructors
			OutOfBoundsException();  // Default constructor
			OutOfBoundsException(int index_num);  // Overload constructor that initializes data member m_index with function argument 
			OutOfBoundsException(const OutOfBoundsException& source);	// Copy constructor

			OutOfBoundsException& operator = (const OutOfBoundsException& source);	// Assignment operator
			virtual ~OutOfBoundsException();	// Destructor

			virtual std::string GetMessage() const;  // Return a message string saying the given index is out of bounds
		};
	}
}
#endif // OutOfBoundsException_HPP