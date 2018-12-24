// Stack.cpp
//
// Implementation file for class Stack<type T, int size>, using template functionality in C++.
// Implementation file contains standard constructor, copy constructor, destructor
// assignment operator, and two functions, Push and Pop - which add and remove an element from top of the stack, respectively
// 2017-05-11: Added StackEmpty and StackFull Exception handling
// 2017-05-11: Changed template argument from <typename t> to <typename T, int size>
//
// Author: Devon Kaberna
//

#ifndef Stack_CPP
#define Stack_CPP

#include "Stack.hpp"	// Header file that contains definition for object called Stack
#include "StackEmptyException.hpp"	// Header file that contains definition for object called StackEmptyException
#include "StackFullException.hpp"	// Header file that contains definition for object called StackFullException
#include "ArrayException.hpp"	//Header file that contains definition for object called Array

#include <iostream> // C++ style I/O

namespace DevonKaberna
{
	namespace Containers
	{
		template <typename T, int size>
		Stack<T, size>::Stack() : m_array(size), m_current(0) {}	 // Default constructor. Initializes array<T> to size based on class template parameter.

		template <typename T, int size>
		Stack<T, size>::Stack(const Stack<T, size>& source) : m_array(source.m_array), m_current(source.m_current) {} // Copy constructor

		// Overloaded Assignment operator
		// Returns stack object by reference
		template <typename T, int size>
		Stack<T, size>& Stack<T, size>::operator = (const Stack<T, size>& source)
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;
			else
			{
				// Copy state
				m_array = source.m_array;
				m_current = source.m_current;
			}
			return *this;  // Return reference, NOT a copy of the object
		}

		template <typename T, int size>
		Stack<T, size>::~Stack() {}  // Destructor

		// Stores the element at the current position in the embedded array.  Increments current position afterwards.
		// Make sure current index is not changed when exception is thrown
		template <typename T, int size>
		void Stack<T, size>::Push(T element)
		{
			try
			{
				m_array[m_current] = element;  // Assign element to current position in array.

				m_current++;  // Increment current position.
			}
			catch (ArrayException&)  // Catch for an array exception
			{
				throw StackFullException();  // Now throw StackFullException
			}
			catch (...)  // If not catch match is found default catch is called
			{
				std::cout << "An unhandled exception has occurred" << endl;
			}
		}

		// Decrements current position and then return element at that position.
		// Make sure current index is not changed when exception is thrown
		// Returns element of type T
		template <typename T, int size>
		T Stack<T, size>::Pop()
		{
			try
			{
				T temp_pop = m_array[m_current - 1];  // Save of the value into a temp variable

				m_current--;  // Decrement m_current

				return temp_pop;  // Return element of type T
			}
			catch (ArrayException&)  // Catch for an array exception
			{
				m_current = 0; // Set current index back to 0
				throw StackEmptyException();  // Now throw StackEmptyException
			}
			catch (...)  // If not catch match is found default catch is called
			{
				std::cout << "An unhandled exception has occurred" << endl;
			}
		}
	}
}
#endif // Stack_CPP