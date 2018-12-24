// ValueTemplateArgumentTest.cpp
//
// Objective is to test value template arguments, in addition to generic types as template variables.
//
// Author: Devon Kaberna
//

#include "Point.hpp" //Header file that contains definition for object called Point
using DevonKaberna::CAD::Point; 

#include "Stack.hpp"	//Header file that contains definition for object called Stack
using DevonKaberna::Containers::Stack; 

#include "StackException.hpp"	//Header file that contains definition for object called StackException
using DevonKaberna::Containers::StackException;  

#include <iostream>  // C++ style I/O

int main()
{
	// Initialize some different template objects
	Stack<int, 3> s1;
	Stack<double, 3> s2;
	Stack<Point, 1> s3;
	Point p1 = Point(100, 101);

	try
	{
		// Push some objects of type int into s1
		s1.Push(1);
		s1.Push(2);
		s1.Push(3);
	
		// Push some objects of type double into s2
		s2.Push(10);
		s2.Push(22);
		s2.Push(33);

		// Push a Point object into s3, and then pop it back out
		s3.Push(p1);
		cout << s3.Pop() << endl;

		s1.Push(4);	// This should error out
	}
	catch (StackException& stk_ex)  // Catch for a StackException
	{
		std::cout << stk_ex.GetMessage() << endl;  // Output message generated from derived class of StackException
	}
	catch (...)  // If not catch match is found default catch is called
	{
		std::cout << "An unhandled exception has occurred" << endl;
	}

	try
	{
		// Pop out 3, 2, 1 from s1
		cout << s1.Pop() << endl;
		cout << s1.Pop() << endl;
		cout << s1.Pop() << endl;

		cout << s1.Pop() << endl; // This should error, since there are no longer any items in the stack.
								  // I am unable to figure out how to maintain current index in Pop() when an exception is thrown.
	}
	catch (StackException& stk_ex)  // Catch for a StackException
	{
		std::cout << stk_ex.GetMessage() << endl;  // Output message generated from derived class of StackException
	}
	catch (...)  // If not catch match is found default catch is called
	{
		std::cout << "An unhandled exception has occurred" << endl;
	}

	try
	{
		// Pop out 33, 22, 10 from s2
		cout << s2.Pop() << endl;
		cout << s2.Pop() << endl;
		cout << s2.Pop() << endl;
	}
	catch (StackException& stk_ex)  // Catch for a StackException
	{
		std::cout << stk_ex.GetMessage() << endl;  // Output message generated from derived class of StackException
	}
	catch (...)  // If not catch match is found default catch is called
	{
		std::cout << "An unhandled exception has occurred" << endl;
	}

	return 0;
}