// Array.hpp
//
// Header file for Array. Let the class Array manage memory for the user
// Header file contains standard constructor, overload constructor, copy constructor, destructor
// assignment operator, two [] operators (one that is CONST, the other non-CONST.
// Also contains accessing functions for both member data pointers, and a setter function for the m_data member point
// Namespace of DevonKaberna::Containers implemented below
//
// Author: Devon Kaberna

#ifndef Array_HPP
#define Array_HPP

#include "Point.hpp" //Header file that contains definition for object called Point

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Containers
	{
		class Array
		{
		private:
			//Member data for class Array that contains dynamic C array of static Point objects and the size of the array
			CAD::Point* m_data;		// Dynamic C array of Point objects
			int m_size;				// Size of the array

		public:
			// Constructors
			Array();											// Default constructor
			Array(const int& size_array);						// Overload constructor that initializes the array size and allocates number of elements specified by size argument
			Array(const Array& a);								// Copy constructor
			Array& operator = (const Array& source);			// Assignment operator
			CAD::Point& operator [] (int index);				// Square bracket operator. Return reference so the [] operator can be used for both reading and writing elements
			const CAD::Point& operator [] (int index) const;	// Square bracket operator - CONST version. More thorough explanation written in the CPP file.
			~Array();											// Destructor

			// Accessing functions for obtaining element and the size of the array				
			int Size() const;										// The size of the array
			CAD::Point& GetElement(int pt_index) const;				// Get element by reference based on index number

			// Setter functions
			void SetElement(const CAD::Point& pt, int pt_index);	// Sets an element based on index number
		};
	}
}
#endif // Array_HPP