// Array.hpp
//
// Header file for class Array, using template functionality in C++.
// Let the class Array manage memory for the user
// Header file contains standard constructor, overload constructor, copy constructor, destructor
// assignment operator, two [] operators (one that is CONST, the other non-CONST.
// Also contains accessing functions for both member data pointers, and a setter function for the m_data member point.
// Namespace of DevonKaberna::Containers implemented below
//
// Author: Devon Kaberna
//

#ifndef Array_HPP
#define Array_HPP

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Containers
	{
		template <typename T> 
		class Array
		{
		private:
			// Member data for class Array<T>
			T* m_data;	// Dynamic C array of T* objects
			int m_size;	 // Size of the array

		public:
			// Constructors
			Array();  // Default constructor
			Array(const int& size_array);  // Overload constructor that initializes the array size and allocates number of elements specified by size argument
			Array(const Array<T>& source);  // Copy constructor
			Array<T>& operator = (const Array<T>& source);  // Assignment operator
			T& operator [] (int index);  // Square bracket operator. Return reference so the [] operator can be used for both reading and writing elements
			const T& operator [] (int index) const;  // Square bracket operator - CONST version.
			virtual ~Array();  // Destructor

			// Accessing functions for obtaining element and the size of the array				
			int Size() const;  // The size of the array
			T& GetElement(int index) const;  // Get element by reference based on index number

			// Modifier functions
			void SetElement(const T& t, int index);  // Sets an element based on index number
		};
	}
}

// The #ifndef/#endif statements for Array_CPP are also inserted in Array.cpp
// By way of doing this below, I am able to maintain consistency in including header file 
// in my test program, rather than including source file. 

#ifndef Array_CPP
#include "Array.cpp"
#endif // Array_CPP

#endif // Array_HPP