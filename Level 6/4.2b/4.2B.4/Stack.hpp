// Stack.hpp
//
// Header file for class Stack<type T>, using template functionality in C++.
// Header file contains standard constructor, overload constructor, copy constructor, destructor
// assignment operator, and two functions, Push and Pop - which add and remove an element from top of the stack, respectively.
//
// Author: Devon Kaberna
//

#ifndef Stack_HPP
#define Stack_HPP

#include "Array.hpp"	// Header file that contains definition for object called Array

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Containers
	{
		template <typename T>
		class Stack
		{
		private:
			// Member data for class Stack<T>
			int m_current;	// Variable that always points to the 'top' of the stack
			Array <T> m_array;	// The array, which will be used for data storage

		public:
			// Constructors
			Stack();  // Default constructor
			Stack(const int& size_array);  // Overload constructor that initializes the array size
			Stack(const Stack<T>& source);  // Copy constructor
			Stack<T>& operator = (const Stack<T>& source);  // Assignment operator
			virtual ~Stack();  // Destructor

			void Push(T element);  // Stores the element at the current position in the embedded array
			T Pop();  // Retrieves the element at the current position in the embedded array
		};
	}
}

// TODO: ADD SOME COMMENTARY HERE
#ifndef Stack_CPP
#include "Stack.cpp"
#endif // Stack_CPP

#endif // Stack_HPP