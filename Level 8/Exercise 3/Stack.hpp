// Stack.hpp
//
// Header file for class Stack<type T, int size>, using template functionality in C++.
// Header file contains standard constructor, copy constructor, destructor
// assignment operator, and two functions, Push and Pop - which add and remove an element from top of the stack, respectively
// 2017-05-11: Changed template argument from <typename t> to <typename T, int size>
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
		template <typename T, int size>
		class Stack
		{
		private:
			// Member data for class Stack<T>
			int m_current = 0;	// Variable that always points to the 'top' of the stack
			Array <T> m_array;	// The array, which will be used for data storage

		public:
			// Constructors
			Stack();  // Default constructor
			Stack(const Stack<T, size>& source);  // Copy constructor
			Stack<T, size>& operator = (const Stack<T, size>& source);  // Assignment operator
			virtual ~Stack();  // Destructor

			void Push(T element);  // Stores the element at the current position in the embedded array
			T Pop();  // Retrieves the element at the current position in the embedded array
		};
	}
}
#ifndef Stack_CPP
#include "Stack.cpp"
#endif // Stack_CPP

#endif // Stack_HPP