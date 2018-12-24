// NumericArray.cpp
//
// Implementation file for class NumericArray, using template functionality in C++.
// Inherits from template <typename T> class Array
// Numeric functionality will be placed in this class, which itself is also a template (generic inheritance).
// Header file contains standard constructor, overload constructor, copy constructor, destructor
// assignment operator, 
// Also contains operator + and operator * overload functions and a method DotProduct.
// 
// Author: Devon Kaberna
//

#ifndef NumericArray_CPP
#define NumericArray_CPP

#include "NumericArray.hpp"	// Header file that contains definition for object called Array
#include "DimensionException.hpp"	// Header file that contains definition for object called DimensionException

#include <iostream> // C++ style I/O

namespace DevonKaberna
{
	namespace Containers
	{
		template <typename T>
		NumericArray<T>::NumericArray() : Array() { std::cout << "Numeric array constructor." << endl; }	 // Default constructor

																											 // Overload constructor that initializes the array size and allocates number of elements specified by size argument
		template <typename T>
		NumericArray<T>::NumericArray(const int& size_array) : Array(size_array) { std::cout << "Numeric array overload constuctor." << endl; }

		template <typename T>
		NumericArray<T>::NumericArray(const NumericArray<T>& source) : Array(source) { std::cout << "Numeric array copy constructor." << endl; }	// Copy constructor

																																					// Overloaded Assignment operator
																																					// Returns array by reference
		template <typename T>
		NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source)
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;
			else
			{
				// Call base class assignment operator
				Array<T>::operator = (source);
			}
			return *this;  // Return reference, NOT a copy of the object
		}

		template <typename T>
		NumericArray<T>::~NumericArray() { std::cout << "Numeric array destructor." << endl; }  // Destructor

																								// Scale the elements of the numeric array by a factor
																								// Passes in argument factor of type T
																								// Returns NumericArray<T> by value
		template <typename T>
		NumericArray<T> NumericArray<T>::operator * (T factor) const
		{
			NumericArray<T> ScaleNA((*this).Size());  // Init variable ScaleNA

			for (int i = 0; i != (*this).Size(); i++)
			{
				ScaleNA[i] = (*this)[i] * factor;  // Scale each element by a factor
			}

			return ScaleNA;  // Return NumericArray
		}

		// Add the elements of two numeric arrays. 
		// Passes in NumericArray<T> na as a reference
		// Throw an exception if two arrays have not the same size.
		// Returns NumericArray<T> by value
		template <typename T>
		NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& na) const
		{
			//Throw exception is array sizes do not equal
			if ((*this).Size() != na.Size())
			{
				throw DimensionException(); // Numeric array sizes don't equal, throw an DimensionException exception
			}
			else
			{
				NumericArray<T> SumNA((*this).Size());  // Init variable SumNA

				for (int i = 0; i != (*this).Size(); i++)
				{
					SumNA[i] = (*this)[i] + na.GetElement(i);  // For each element in both arrays, sum them
				}

				return SumNA;
			}
		}

		// Calculates the dot product
		// Passes in NumericArray<T> na as a reference
		// Throw an exception if two arrays have not the same size.
		// Returns DotProduct calc back by type T
		template <typename T>
		T NumericArray<T>::DotProduct(const NumericArray<T>& na)
		{
			//Throw exception is array sizes do not equal
			if ((*this).Size() != na.Size())
			{
				throw DimensionException(); // Numeric array sizes don't equal, throw an DimensionException exception
			}
			else
			{
				T DotProduct = 0;  // Init variable DotProduct of type T

				for (int i = 0; i != (*this).Size(); i++)
				{
					DotProduct = DotProduct + ((*this)[i] * na.GetElement(i));  // First multiple element in each array, and then use summation
				}

				return DotProduct;  // Return DotProduct calc
			}
		}
	}
}
#endif	// NumericArray_CPP