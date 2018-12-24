// STLAlgorithmTest.cpp
//
// Objective is to test STL Algorithms, and the count_if algorithm in particular.  First I create a global function to count the number of elements smaller than a literal value - 39.8.
// I then replace this with a function object of the same name and signature.  This function object is defined in class - IsSmaller.
//
// Author: Devon Kaberna
//
#include <list> // List container
#include <algorithm>  // STL algorithms

#include "IsSmaller.hpp"	// Header file that contains definition for object called IsSmaller<t>

#include <iostream>  // C++ style I/O

// Global checking function that returns true if number of type T is less than a fixed number of 39.8
template <typename T>
bool IsSmaller(const T& t)
{
	T test_val = 39.8; 

	return ((t < test_val) ? 1 : 0);  // Returns true if number of type T is less than 39.8
}

int main()
{
	double test_values[10] = { 2.12, 87.56, 51, 14, 4, 439, -12.79, 9, 576, 5.9 };  // Let's create some test values

	std::list<double> l; // Let's create a list of doubles

	double test_value = 39.8;  // Create value to be compared to, and passed into the function object

	for (int i = 0; i < 10; i++)
	{
		l.push_back(test_values[i]); // Add the values to the list
	}

	// Use count_if algorithm to count the number of elements smaller than 39.8
	// Pass global function - IsSmaller - that checks the double input is smaller than 39.8, and returns the number of elements.
	std::cout << "Number of elements smaller than " << test_value << " is: " << std::count_if (l.begin(), l.end(), IsSmaller<double>)<< std::endl;

	// Now I will replace the global checking function, IsSmaller, by a function object
	std::cout << "Number of elements smaller than " << test_value << " using function object is: " << std::count_if(l.begin(), l.end(), DevonKaberna::FunctionalObjects::IsSmaller<double>(test_value)) << std::endl;

	return 0;
}