// Stack.cpp
//
// Implementation file for class Stack, using template functionality in C++.
// Implementation file contains standard constructor, overload constructor, copy constructor, destructor
// assignment operator, and two functions, Push and Pop
// 2017-05-11: Added StackEmpty and StackFull Exception handling
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
		template <typename T>
		Stack<T>::Stack() : m_array(Array<T>()), m_current(0) {}	 // Default constructor. Initializes array<T> to 0.  Sets m_current to 0.

		template <typename T>
		Stack<T>::Stack(const int& size_array) : m_array(Array<T>(size_array)), m_current(0) {}  // Overload constructor initializes array<T> based on input size.  Sets m_current to 0.

		template <typename T>
		Stack<T>::Stack(const Stack<T>& source) : m_array(source.m_array), m_current(source.m_current) {} // Copy constructor

		// Overloaded Assignment operator
		// Returns stack object by reference
		template <typename T>
		Stack<T>& Stack<T>::operator = (const Stack<T>& source)
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

		template <typename T>
		Stack<T>::~Stack() {}  // Destructor

		// Stores the element at the current position in the embedded array.  Increments current position afterwards.
		// Make sure current index is not changed when exception is thrown
		template <typename T>
		void Stack<T>::Push(T element)
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
		template <typename T>
		T Stack<T>::Pop()
		{
			try
			{
				// I can't figure out how to meet the requirements of Exercise 4 - namely, to make sure current index is not changed when exception is thrown.
				return  m_array[--m_current];
			}
			catch (ArrayException&)  // Catch for an array exception
			{
				throw StackEmptyException();  // Now throw StackEmptyException
				m_current = 0; // Set current index back to 0
			}
			catch (...)  // If not catch match is found default catch is called
			{
				std::cout << "An unhandled exception has occurred" << endl;
			}
		}
	}
}
#endif // Stack_HPP