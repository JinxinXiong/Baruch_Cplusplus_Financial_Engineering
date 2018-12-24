// DimensionException.hpp
//
// Header file for class DimensionException
// Derived class of class ArrayException
// Contains standard constructor, overloaded constructor, copy constructor, destructor, and assignment operator.
// Implements function GetMessage(), which is an abstract function in the base class.
// Namespace of DevonKaberna::Containers implemented below
//
// Author: Devon Kaberna
//

#ifndef DimensionException_HPP
#define DimensionException_HPP

#include "ArrayException.hpp"  // Header file that contains definition for object called ArrayException

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Containers
	{
		class DimensionException : public ArrayException
		{
		private:
			// Member data
			int m_size;  // Contains erroneous array size

		public:
			// Constructors
			DimensionException();  // Default constructor
			DimensionException(int m_size);  // Overload constructor with size as argument
			DimensionException(const DimensionException& source);	// Copy constructor

			DimensionException& operator = (const DimensionException& source);	// Assignment operator
			virtual ~DimensionException();	// Destructor

			virtual std::string GetMessage() const;  // Return a message string saying two arrays don't have the same size
		};
	}
}
#endif // DimensionException_HPP