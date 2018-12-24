// NumericArray.hpp
//
// Header file for class NumericArray, using template functionality in C++.
// Inherits from template <typename T> class Array
// Numeric functionality will be placed in this class, which itself is also a template (generic inheritance).
// Header file contains standard constructor, overload constructor, copy constructor, destructor
// assignment operator, 
// Also contains operator + and operator * overload functions and a method DotProduct.
// 
// Author: Devon Kaberna
//

#ifndef NumericArray_HPP
#define NumericArray_HPP

#include "Array.hpp"	// Header file that contains definition for object called Array

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Containers
	{
		template <typename T> 
		class NumericArray : public Array<T>
		{
		private:
			// No member data for class NumericArray

		public:
			// Constructors
			NumericArray();  // Default constructor
			NumericArray(const int& size_array);  // Overload constructor that initializes the array size and allocates number of elements specified by size argument
			NumericArray(const NumericArray<T>& source);  // Copy constructor
			virtual ~NumericArray();  // Destructor

			NumericArray<T>& operator = (const NumericArray<T>& source);  // Assignment operator
			NumericArray<T> operator * (T factor) const;  // Scale the elements of the numeric array by a factor
			NumericArray<T> operator + (const NumericArray<T>& na) const;   // Add the elements of two numeric arrays. Throw an exception if two arrays have not the same size.

			T DotProduct(const NumericArray<T>& na);  // Calculates the dot product
		};
	}
}

#ifndef NumericArray_CPP
#include "NumericArray.cpp"
#endif // NumericArray_CPP

#endif // NumericArray_HPP