// Array.hpp
//
// Header file for class Array, using template functionality in C++.
// Let the class Array manage memory for the user
// Header file contains standard constructor, overload constructor, copy constructor, destructor
// assignment operator, two [] operators (one that is CONST, the other non-CONST.
// Also contains accessing functions for both member data pointers, and a setter function for the m_data member point.
// Namespace of DevonKaberna::Containers implemented below
// 2017-05-06: Added static member functions to get and set the default size, and added a static private variable, s_default_size.
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
			static unsigned int s_default_size;   // Default size of the array

		public:
			// Constructors
			Array();  // Default constructor
			Array(const int& size_array);  // Overload constructor that initializes the array size and allocates number of elements specified by size argument
			Array(const Array<T>& source);  // Copy constructor
			Array<T>& operator = (const Array<T>& source);  // Assignment operator
			T& operator [] (int index);  // Square bracket operator. Return reference so the [] operator can be used for both reading and writing elements
			const T& operator [] (int index) const;  // Square bracket operator - CONST version. More thorough explanation written in the CPP file.
			virtual ~Array();  // Destructor

			// Accessing functions			
			int Size() const;  // The size of the array
			T& GetElement(int index) const;  // Get element by reference based on index number
			static unsigned int DefaultSize();  // Get the default size of the array
			
			// Modifier functions
			static void DefaultSize(unsigned int start_size); // Set the default size of the array
			void SetElement(const T& t, int index);  // Sets an element based on index number
		};
	}
}

#ifndef Array_CPP
#include "Array.cpp"
#endif // Array_CPP

#endif // Array_HPP