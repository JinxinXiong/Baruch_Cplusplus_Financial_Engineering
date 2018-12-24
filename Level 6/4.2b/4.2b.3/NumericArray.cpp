// NumericArray.cpp
//
// Implementation code for class NumericArray,  using template functionality in C++.
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
		template <typename T>
		NumericArray<T> NumericArray<T>::operator * (T factor) const
		{
			NumericArray<T> ScaleNA((*this).Size());

			for (int i = 0; i != (*this).Size(); i++)
			{
				ScaleNA[i] = (*this)[i] * factor;
			}

			return ScaleNA;
		}

		// Add the elements of two numeric arrays. 
		// Throw an exception if two arrays have not the same size.
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
				NumericArray<T> SumNA((*this).Size());

				for (int i = 0; i != (*this).Size(); i++)
				{
					SumNA[i] = (*this)[i] + na.GetElement(i);
				}
				
				return SumNA;
			}
		}

		// Calculates the dot product
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
				T DotProduct = 0;

				for (int i = 0; i != (*this).Size(); i++)
				{
					DotProduct = DotProduct + ((*this)[i] * na.GetElement(i));
				} 

				return DotProduct;
			}
		}
	}
}
#endif	// NumericArray_CPP