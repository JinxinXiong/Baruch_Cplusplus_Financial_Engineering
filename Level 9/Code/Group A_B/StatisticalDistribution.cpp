// StatisticalDistribution.cpp
//
// Implementation file for class StatisticalDistribution
// This class is an abstract base class that contains a pure virtual function - cdf and pdf.
// Also contains standard constructor, copy constructor, destructor, and assignment operator.
// Also contains implementation of mean/std deviation accessor and modifier methods.
//
// Author: Devon Kaberna
//

#ifndef StatisticalDistribution_CPP
#define StatisticalDistribution_CPP

#include "StatisticalDistribution.hpp"	// Header file that contains definition for object called StatisticalDistribution

namespace DevonKaberna
{
	namespace Utilities
	{
		template <typename T>
		StatisticalDistribution<T>::StatisticalDistribution() : m_mean(0.0), m_stdev(0.0) {}  // Default constructor
																							  // Override constructor passes into the initial mean/std deviation that boost library normal_distribution requires - if omitted will default to (0,1)
		template <typename T>
		StatisticalDistribution<T>::StatisticalDistribution(const T& _start_mean, const T& _start_stdev) : m_mean(_start_mean), m_stdev(_start_stdev) {}

		template <typename T>
		StatisticalDistribution<T>::StatisticalDistribution(const StatisticalDistribution<T>& source) : m_mean(source.m_mean), m_stdev(source.m_stdev) {}	// Copy constructor

		template <typename T>
		StatisticalDistribution<T>& StatisticalDistribution<T>::operator = (const StatisticalDistribution<T>& source) // Assignment operator
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;
			
			// Copy state
			m_mean = source.m_mean;
			m_stdev = source.m_stdev;

			return *this;
		}

		template <typename T>
		StatisticalDistribution<T>::~StatisticalDistribution() {}	// Destructor

		// Setter member-function for Mean
		// Modifies object state of data member m_mean
		template <typename T>
		void StatisticalDistribution<T>::Mean(const T& _start_mean) { m_mean = _start_mean; }

		// Getter member-function for Mean
		// Returns data member m_mean
		template <typename T>
		T StatisticalDistribution<T>::Mean() const { return m_mean; }

		// Setter member-function for StandardDeviation
		// Modifies object state of data member m_stdev
		template <typename T>
		void StatisticalDistribution<T>::StandardDeviation(const T& _start_stdev) { m_stdev = _start_stdev; }

		// Getter member-function for Std. Deviation
		// Returns data member m_stdev
		template <typename T>
		T StatisticalDistribution<T>::StandardDeviation() const { return m_stdev; }
	}
}
#endif	// StatisticalDistribution_CPP