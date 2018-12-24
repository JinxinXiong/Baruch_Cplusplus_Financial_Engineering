// IsSmaller.cpp
//
// Implementation file for class IsSmaller<type T>, using template functionality in C++.
// Implementation file contains standard constructor, copy constructor, destructor
// overloaded assignment operator, and an overloaded () operator, which allows the class to 'behave' as if it's a function.
//
// Author: Devon Kaberna
//

#ifndef IsSmaller_CPP
#define IsSmaller_CPP

#include "IsSmaller.hpp"	// Header file that contains declaration for object called IsSmaller<t>

namespace DevonKaberna
{
	namespace FunctionalObjects
	{
		template <typename T>
		IsSmaller<T>::IsSmaller() : m_CompareValue(0) {}  // Default constructor

		template <typename T>
		IsSmaller<T>::IsSmaller(const T& compare_value) : m_CompareValue(compare_value) {}  // Overload constructor that sets the compare value

		template <typename T>
		IsSmaller<T>::IsSmaller(const IsSmaller<T>& source) : m_CompareValue(source.m_CompareValue) {}  // Copy constructor

		// Overloaded Assignment operator
		template <typename T>
		IsSmaller<T>& IsSmaller<T>::operator = (const IsSmaller<T>& source)
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			// Copy state
			m_CompareValue = source.compare_value;

			return *this;  // Return reference, NOT a copy of the object
		}

		template <typename T>
		IsSmaller<T>::~IsSmaller() {}  // Destructor

		// Overloaded () operator
		// This is essentially a "function call" operator -  which allows this class to 'behave' as if it's a function
		// Passed in value t of type T
		// Returns a boolean (true) if number of type T is less than data member m_compareValue
		template <typename T>
		bool IsSmaller<T>::operator() (const T& t) const
		{
			return ((t < m_CompareValue) ? 1 : 0);  // Returns true if number of type T is less than data member m_compareValue
		}
	}
}
#endif // IsSmaller_CPP