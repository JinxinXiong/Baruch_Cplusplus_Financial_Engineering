// STLIteratorTest.cpp
//
// Objective is to test creating iterators using list, vector, and map containers
//
// Author: Devon Kaberna
//
#include "Sum.hpp"  // Header file that contains function template declarations and also function template definitions used belows

#include <iostream>  // C++ style I/O

int main()
{
	double test_values[10] = { 2.12, 87.56, 51, 14, 4, 439, -12.79, 9, 576, 5.9 };  // Let's create some test values

	std::list<double> l; // Let's create a list of doubles

	for (int i = 0; i < 10; i++)
	{
		l.push_back(test_values[i]); // Add the values to the list
	}

	std::cout << "Sum using list is: " << Sum(l) << std::endl << std::endl;  // Let's verify Sum() works on a list of doubles

	std::vector<double> v; // Let's create a vector of doubles
	v.reserve(10);   // Reserve space for 20 elements

	for (int i = 0; i < 10; i++)
	{
		v.push_back(test_values[i]); // Add the values to the vector
	}

	std::cout << "Sum using vector is: " << Sum(v) << std::endl << std::endl;   // Let's verify Sum() works on a vector of doubles

	std::map<std::string, double> map;  // Let's create a map that maps strings to doubles

	// Fill map
	map["a"] = 4.1;
	map["b"] = 12.1;
	map["d"] = 4;
	map["e"] = -9;
	map["f"] = 31.2;

	std::cout << "Sum using map is: " << Sum(map) << std::endl << std::endl;  // Let's verify Sum() works on a map

	// Now let's test using Sum() whereby we pass both a start and an end iterator
	std::cout << "Sum using list with beginning/end iterator is: " << Sum<std::list<double> > (l.begin(), l.end()) << std::endl << std::endl;  // Passing a list<double>
	std::cout << "Sum using vector with beginning/end iterator is: " << Sum<std::vector<double> >(v.begin(), v.end()) << std::endl << std::endl; // Passing a vector<double>
	std::cout << "Sum using map with beginning/end iterator is: " << Sum<std::string, double>(map.begin(), map.end()) << std::endl << std::endl; // Passing a map<string, double>


	return 0;
}