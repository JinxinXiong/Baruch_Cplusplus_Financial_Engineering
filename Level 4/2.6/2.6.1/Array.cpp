// Array.cpp
//
// Implementation file for class Array
// Let the class Array manage memory for the user
// Header file contains standard constructor, overload constructor, copy constructor, destructor
// assignment operator, two [] operators (one that is CONST, the other non-CONST.
// Also contains accessing functions for both member data pointers, and a setter function for the m_data member point
// Namespace of DevonKaberna::Containers implemented below
// Note: The full class name including namespace for the Point class is used below
//
// Author: Devon Kaberna
//

#include "Array.hpp"	//Header file that contains definition for object called Array
#include "Point.hpp"	//Header file that contains definition for object called Point

#include <iostream> // C++ style I/O

namespace DevonKaberna
{
	namespace Containers
	{
		Array::Array()	 // Default constructor
		{
			m_size = 10;  // Defaulted to 10 elements
			m_data = new CAD::Point[m_size]; //Instantiate the array of static Point objects

			if (m_data == nullptr)  // Check what new returns to see if its NULL
				std::cout << "Error: memory could not be allocated";
			else
				std::cout << "Default constructor called" << endl;
		}

		// Overload constructor that initializes the array size and allocates number of elements specified by size argument
		Array::Array(const int& size_array)
		{
			m_size = size_array; // Set size based on input argument
			m_data = new  CAD::Point[m_size];  //Instantiate the array of static Point objects

			if (m_data == nullptr)   // Check what new returns to see if its NULL
				std::cout << "Error: memory could not be allocated";
			else
				std::cout << "Overloaded constructor called with size of: " << m_size << endl;
		}

		Array::Array(const Array& a)	// Copy constructor
		{
			//check to make sure not assigning to myself
			if (this != &a)
			{
				m_size = a.m_size; // Get size from the object being copied from
				m_data = new  CAD::Point[a.m_size];  // Allocate a new C array with the same size

				if (m_data == nullptr)  // Check what new returns to see if its NULL
					std::cout << "Error: memory could not be allocated";
				else
				{
					for (int i = 0; i < a.m_size; i++)
					{
						m_data[i] = a.m_data[i];  // Copy each element separately
					}
				}
				std::cout << "Copy constructor called with size of: " << m_size << endl;
			}
		}

		// Overloaded Assignment operator
		// Returns array by reference
		Array& Array::operator = (const Array& source)
		{
			//check to make sure not assigning to myself
			if (this == &source)
			{
				std::cout << "Function to preclude self-assignment works!" << endl;
				return *this;
			}
			else
			{
				delete[] m_data;  // Delete the internal C array before it is copied

				m_size = source.m_size; // Get size from the object being copied from
				m_data = new  CAD::Point[source.m_size];  // Allocate new memory before copying the elements

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
		CAD::Point& Array::operator [] (int index)
		{
			if (index > m_size)  // Check to make sure index number isn't out of bounds
			{
				std::cout << "Index out of bounds!" << endl;
				return m_data[0];  // Just return the first element
			}
			else
			{
				return m_data[index];  // Returns by reference
			}
		}

		// Overloaded [] operator
		// Since we have a CONST object, we also want the function to be CONST, such that this function cannot change the object
		// This will tell the compiler it's SAFE to return the Point object as a reference
		// We pass in index element number
		// Returns a reference of the Point object, but as a CONST
		const CAD::Point& Array::operator [] (int index) const
		{
			if (index > m_size)   // Check to make sure index number isn't out of bounds
			{
				std::cout << "Index out of bounds!" << endl;
				return m_data[0];  // Just return the first element
			}
			else
			{
				std::cout << "[] bracket operator CONST" << endl;
				return m_data[index];  // Returns by reference
			}
		}

		Array::~Array()		// Destructor
		{
			delete[] m_data; // Now delete the array itself
			std::cout << "Destructor called" << endl;
		}

		// Accessing member-function for obtaining size of the array	
		// Returns data member m_size
		int Array::Size() const { return m_size; }	// The size of the array

		// Accessing member-function for obtaining element of the Point array
		// We pass in the index element number
		// Get Point element by reference
		CAD::Point& Array::GetElement(int pt_index) const
		{
			if (pt_index > m_size)
			{
				std::cout << "Index out of bounds!" << endl;  // Check to make sure index number isn't out of bounds
				return m_data[0]; // Just return the first element
			}
			else
			{
				return m_data[pt_index];  // Returns by reference
			}
		}

		// Setter function for setting an element within the Point array
		// We pass in the const Point object by reference, and the index element number
		void Array::SetElement(const CAD::Point& pt, int pt_index)
		{
			if (pt_index > m_size)  // Check to make sure index number isn't out of bounds
			{
				std::cout << "Index out of bounds!" << endl;  // If out of bounds, ignore the "set"
			}
			else
			{
				this->m_data[pt_index] = pt;
			}
		}
	}
}