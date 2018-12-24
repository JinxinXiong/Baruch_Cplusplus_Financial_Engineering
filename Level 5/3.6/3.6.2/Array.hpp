// Array.hpp
//
// Contains class definitions for Array, ArrayException, and OutOfBoundsException
// Namespace of DevonKaberna::Containers implemented below
//
// Author: Devon Kaberna
//

#ifndef Array_HPP
#define Array_HPP

#include "Point.hpp" // Header file that contains definition for object called Point

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Containers
	{
		// Header file for class Array. 
		// Let the class Array manage memory for the user
		// Header file contains standard constructor, overload constructor, copy constructor, destructor
		// assignment operator, two [] operators (one that is CONST, the other non-CONST.
		// Also contains accessing functions for both member data pointers, and a setter function for the m_data member point.

		class Array
		{
		private:
			// Member data for class Array that contains dynamic C array of static Point objects and the size of the array
			CAD::Point* m_data;		// Dynamic C array of Point objects
			int m_size;				// Size of the array

		public:
			// Constructors
			Array();											// Default constructor
			Array(const int& size_array);						// Overload constructor that initializes the array size and allocates number of elements specified by size argument
			Array(const Array& source);							// Copy constructor
			Array& operator = (const Array& source);			// Assignment operator
			CAD::Point& operator [] (int index);				// Square bracket operator. Return reference so the [] operator can be used for both reading and writing elements
			const CAD::Point& operator [] (int index) const;	// Square bracket operator - CONST version. More thorough explanation written in the CPP file.
			virtual ~Array();									// Destructor

			// Accessing functions for obtaining element and the size of the array				
			int Size() const;										// The size of the array
			CAD::Point& GetElement(int pt_index) const;				// Get element by reference based on index number

			// Setter functions
			void SetElement(const CAD::Point& pt, int pt_index);	// Sets an element based on index number
		};

		// Header file for class ArrayException
		// This class is an abstract base class that contains a pure virtual function - GetMessage().
		// Also contains standard constructor, copy constructor, destructor, and assignment operator.
		// They don't do anything at this point since there are no data members, but for best practice, I implemented them anyways.

		class ArrayException
		{
		private:
			// No ArrayException data members at this point

		public:
			// Constructors
			ArrayException();  // Default constructor
			ArrayException(const ArrayException& source);	// Copy constructor
			
			ArrayException& operator = (const ArrayException& source);	// Assignment operator
			virtual ~ArrayException();	// Destructor

			virtual std::string GetMessage() const = 0;  // Abstract function GetMessage() must be implemented in derived classes
		};

		// Header file for class OutOfBoundsException
		// Derived class of class ArrayException
		// Contains standard constructor, overloaded constructor, copy constructor, destructor, and assignment operator.
		// Implements function GetMessage(), which is an abstract function in the base class. 

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

			std::string GetMessage() const;  // Return a message string saying the given index is out of bounds
		};
	}
}
#endif // Array_HPP