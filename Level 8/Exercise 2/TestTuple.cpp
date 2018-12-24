// TestTuple.cpp
//
// Objective is to create a Person using a tuple, then print out the person's tuple and also increase age of person.
//
// Author: Devon Kaberna
//

#include <boost/tuple/tuple.hpp>  // Tuple class
using boost::tuple;  // Using declaration, for readability purposes

#include <boost/tuple/tuple_io.hpp> // I/O for tuples

#include <iostream>  // C++ style I/O
using namespace std;

// Prints Person's tuple
void PrintPerson(const boost::tuple<string, int, double>& p)
{
	std::cout << "Name: " << p.get<0>() << ", Age: "  << p.get<1>() << ", Length: " << p.get<2>() << endl << endl;
}

// Increase Person's age
// Passes in age of Person via get<T>() function as a reference
template <typename T>
void IncrementElement(T& t)
{
	 ++t;
}

int main()
{
	typedef boost::tuple<string, int, double> Person; // First, let's create a typedef for a Person tuple that contains name, age, and length

	// Creating a couple person tuples
	Person p1 = boost::make_tuple(string("Devon"), 39, 64);
	Person p2 = boost::make_tuple(string("Hannaise"), 37, 53);
	Person p3 = boost::make_tuple(string("Darren"), 41, 60);

	// Print out each person tuple
	PrintPerson(p1);
	PrintPerson(p2);
	PrintPerson(p3);

	IncrementElement(get<1>(p1));  // Now let's increment the age of one of the persons

	cout << "Will now increment age." << endl << endl;

	PrintPerson(p1);  // Now let's verify incrementing age worked

	return 0;
}