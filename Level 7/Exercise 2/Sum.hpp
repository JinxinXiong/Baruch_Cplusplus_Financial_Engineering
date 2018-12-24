// Sum.hpp
//
// Header file for STLIterators.  Contains function declaration and function definitions for Sum() function
// that 1 is for list/vector and 1 is for map that take a const object container
// and 1 for list/vector and 1 for map that take two iterators.
//
// Author: Devon Kaberna
//

#ifndef Sum_HPP
#define Sum_HPP

#include <map>				// Map containers
#include <list>				// List containers
#include <vector>			// Vector containers

// Function declaration
// Generic template that can be used for a container such as vector or list
// Returns double
template<typename T> double Sum(const T& value);

// Function declaration
// Template specialization specifically for map container
// Returns double
template<typename T, typename U> double Sum (const std::map<T, U> &value);

// Function declaration
// Sum between two iterators for container such as list or vector
// Returns double
template<typename T> double Sum(typename T::const_iterator start, typename T::const_iterator end);

// Function declaration
// Sum between two iterators for map using template specialization
// Returns double
template<typename T, typename U> double Sum(typename std::map<T, U>::const_iterator start, typename std::map<T, U>::const_iterator end);

// Generic template that can be used for a container such as vector or list
// Sums values passed in the generic container
// Returns double
template <typename T>
double Sum(const T& value)
{
	double tempSum = 0;

	for (T::const_iterator i = value.begin(); i != value.end(); ++i)
		tempSum += *i;

	return tempSum;
}

// Template specialization specifically for map container
// Sums values passed in via map container
// Returns double
template<typename T, typename U>
double Sum(const std::map<T, U> &value)
{
	double tempSum = 0;

	for (std::map<T, U>::const_iterator i = value.begin(); i != value.end(); ++i)
		tempSum += i->second;

	return tempSum;
}

// Generic template that sums between two iterators for container such as list or vector
// Returns double
template<typename T> 
double Sum(typename T::const_iterator start, typename T::const_iterator end)
{
	double tempSum = 0;

	for (T::const_iterator i = start; i != end; ++i)
	{
		tempSum += *i;
	}

	return tempSum;
}

// Sum between two iterators for map using template specialization
// Returns double
template<typename T, typename U> 
double Sum(typename std::map<T, U>::const_iterator start, typename std::map<T, U>::const_iterator end)
{
	double tempSum = 0;
	for (std::map<T, U>::const_iterator i = start; i != end; ++i)
	{
		tempSum += i->second;
	}

	return tempSum;
}

#endif // Sum_HPP