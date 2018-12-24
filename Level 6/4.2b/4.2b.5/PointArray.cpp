// PointArray.cpp
//
// Implementation code for class PointArray.
// Inherits (concrete inheritance) from base class Array, of which the template argument is fixed to Point.
// File contains standard constructor, overload constructor, copy constructor, destructor
// assignment operator, and a function, GetLength, that returns total length between two points in an array.
//
// Author: Devon Kaberna
//


#ifndef PointArray_CPP
#define PointArray_CPP

#include "PointArray.hpp"	// Header file that contains definition for object called PointArray
#include "Array.hpp"	// Header file that contains definition for object called Array

#include <iostream> // C++ style I/O

namespace DevonKaberna
{
	namespace Containers
	{
		PointArray::PointArray() : Array() {}	 // Default constructor

		// Overload constructor that initializes the array size and allocates number of elements specified by size argument
		PointArray::PointArray(const int& size_array) : Array(size_array) {}

		PointArray::PointArray(const PointArray& source) : Array(source) {} // Copy constructor

		// Overloaded Assignment operator
		// Returns array by reference
		PointArray& PointArray::operator = (const PointArray& source)
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;
			else
			{
				// Call base class assignment operator
				Array<Point>::operator = (source);
			}
			return *this;  // Return reference, NOT a copy of the object
		}

		PointArray::~PointArray() {} // Destructor

		// Get total length between the points in the array
		// Returns total length 
		double PointArray::Length() const
		{
			double SumPointArray = 0;

			for (int i = 0; i != (*this).Size(); i++)
			{
				if (i != ((*this).Size()) - 1)
				{
					SumPointArray = SumPointArray + (*this)[i].Distance((*this)[i + 1]);  // Add length between points to the sum variable
				}
				else
				{
					SumPointArray = SumPointArray + (*this)[i].Distance((*this)[i]);  // If we are on the last point, just calc length between the very same point, since it's an odd number.
				}
			}

			return SumPointArray;
		}
	}
}
#endif	// PointArray_CPP