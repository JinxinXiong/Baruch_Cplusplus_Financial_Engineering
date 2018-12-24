// IsSmaller.hpp
//
// Header file for class IsSmaller<type T>, using template functionality in C++.
// Implementation file contains standard constructor, copy constructor, destructor
// overloaded assignment operator, and an overloaded () operator, which allows the class to 'behave' as if it's a function.
//
// Author: Devon Kaberna
//

#ifndef IsSmaller_HPP
#define IsSmaller_HPP

namespace DevonKaberna
{
	namespace FunctionalObjects
	{
		template <typename T>
		class IsSmaller
		{
		private:
			// Member data for class IsSmaller<T>
			T m_CompareValue;  // Variable that stores value to be compared to

		public:
			// Constructors
			IsSmaller();  // Default constructor
			IsSmaller(const T& compare_value);  // Overload constructor that sets the compare value
			IsSmaller(const IsSmaller<T>& source);  // Copy constructor
			IsSmaller<T>& operator = (const IsSmaller<T>& source);  // Assignment operator
			virtual ~IsSmaller();  // Destructor

			bool operator() (const T& t) const; 	// Overloaded () operator
													// This is essentially a "function call" operator -  which allows this class to 'behave' as if it's a function
		};
	}
}

#ifndef IsSmaller_HPP_CPP
#include "IsSmaller.cpp"
#endif // IsSmaller_HPP

#endif // IsSmaller_HPP