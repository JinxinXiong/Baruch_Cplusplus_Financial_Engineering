// Array.cpp
//
// Implementation code for class Array,  using template functionality in C++.
// Let the class Array manage memory for the user
// Contains standard constructor, overload constructor, copy constructor, destructor
// assignment operator, two [] operators (one that is CONST, the other non-CONST.
// Also contains accessing functions for both member data pointers, and a setter function for the m_data member.
// 2017-05-04: Added exception handling in the GetElement(), SetElement(), and index operator functions if index is too small/big.
// Namespace of DevonKaberna::Containers implemented below
// 2017-05-06: Added static member functions to get and set the default size, and added a static private variable, s_default_size.
//
// Author: Devon Kaberna
//

#ifndef Array_CPP
#define Array_CPP

#include "Array.hpp"	// Header file that contains definition for object called Array
#include "OutOfBoundsException.hpp"	// Header file that contains definition for object called OutOfBoundsException

#include <iostream> // C++ style I/O

namespace DevonKaberna
{
	namespace Containers
	{
		template <typename T>
		Array<T>::Array() : m_size(s_default_size), m_data(new T[s_default_size]) { cout << "Array created" << endl; } // Default constructor; Default size to s_default_size; Instantiate the array of T objects

		// Overload constructor that initializes the array size and allocates number of elements specified by size argument
		template <typename T>
		Array<T>::Array(const int& size_array) : m_size(size_array), m_data(new T[size_array]) { cout << "Array created" << endl; }

		template <typename T>
		Array<T>::Array(const Array<T>& source) : m_size(source.m_size), m_data(new T[source.m_size])  	// Copy constructor
		{
			if (m_data == nullptr)  // Check what new returns to see if its NULL
				std::cout << "Error: memory could not be allocated";
			else
			{
				for (int i = 0; i < source.m_size; i++)
				{
					m_data[i] = source.m_data[i];  // Copy each element separately
				}
			}
		}

		// Overloaded Assignment operator
		// Returns array by reference
		template <typename T>
		Array<T>& Array<T>::operator = (const Array<T>& source)
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;
			else
			{
				delete[] m_data;  // Delete the internal C array before it is copied

				m_size = source.m_size; // Get size from the object being copied from
				m_data = new T[source.m_size];  // Allocate new memory before copying the elements

				if (m_data == nullptr)  // Check what new returns to see if its NULL
					std::cout << "Error: memory could not be allocated";
				else
				{
					for (int i = 0; i < source.m_size; i++)
					{
						m_data[i] = source.m_data[i];  // Now copy the elements over
					}
				}
			}
			return *this;  // Return reference, NOT a copy of the object
		}

		// Overloaded [] operator
		// Return reference so the [] operator can be used for both reading and writing elements
		template <typename T>
		T& Array<T>::operator [] (int index)
		{
			if ((index <= m_size - 1) && (index >= 0))  // Check to make sure index number isn't out of bounds
			{
				return m_data[index];  // Returns by reference
			}
			else
			{
				throw OutOfBoundsException(index); // Index is out of bounds, throw an OutOfBoundsException exception
			}
		}

		// Overloaded [] operator
		// Since we have a CONST object, we also want the function to be CONST, such that this function cannot change the object
		// This will tell the compiler it's SAFE to return the T object as a reference
		// We pass in index element number
		// Returns a reference of the T object, but as a CONST
		template <typename T>
		const T& Array<T>::operator [] (int index) const
		{
			if ((index <= m_size - 1) && (index >= 0))   // Check to make sure index number isn't out of bounds
			{
				return m_data[index];  // Returns by reference
			}
			else
			{
				throw OutOfBoundsException(index); // Index is out of bounds, throw an OutOfBoundsException exception
			}
		}

		template <typename T>
		Array<T>::~Array()  // Destructor
		{
			delete[] m_data; // Now delete the array itself
			cout << "Array destructed" << endl;
		}

		// Accessing member-function for obtaining size of the array	
		// Returns data member m_size
		template <typename T>
		int Array<T>::Size() const { return m_size; }	// The size of the array

		// Accessing member-function for obtaining element of the Point array
		// We pass in the index element number
		// Get T element by reference
		template <typename T>
		T& Array<T>::GetElement(int index) const
		{
			if ((index <= m_size - 1) && (index >= 0))
			{
				return m_data[index];  // Returns by reference
			}
			else
			{
				throw OutOfBoundsException(index); // Index is out of bounds, throw an OutOfBoundsException exception
			}
		}

		// Setter function for setting an element within the Point array
		// We pass in the const T object by reference, and the index element number
		template <typename T>
		void Array<T>::SetElement(const T& t, int index)
		{
			if ((index <= m_size - 1) && (index >= 0))  // Check to make sure index number isn't out of bounds
			{
				this->m_data[index] = t;
			}
			else
			{
				throw OutOfBoundsException(index); // Index is out of bounds, throw an OutOfBoundsException exception
			}
		}

		// Initialize static variable s_default_size;
		template <typename T>
		unsigned int Array<T>::s_default_size = 0;

		// Accessing static member function for obtaining default size
		// No arguments passed in
		// Returns static data member s_default_size as unsigned int
		template <typename T>
		unsigned int Array<T>::DefaultSize() { return s_default_size; }  // Get the default size of the array

		// Setter static member function for setting default size
		// Start_size passed in as unsigned int
		template <typename T>
		void Array<T>::DefaultSize(unsigned int start_size) { s_default_size = start_size; }  // Set the default size	
	}
}
#endif	// Array_CPP