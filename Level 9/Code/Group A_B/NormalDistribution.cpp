// NormalDistribution.cpp
//
// Implementation file for class NormalDistribution (aka, Gaussian Distribution).
// Derived class of class StatisticalDistribution
// This class implements cdf and pdf.
// Also contains standard constructor, copy constructor, destructor, and assignment operator.
// Also contains setter/getter functions for mean and std. deviation.
//
// Author: Devon Kaberna
//

#ifndef NORMAL_DISTRIBUTION_CPP
#define NORMAL_DISTRIBUTION_CPP

#include "NormalDistribution.hpp" 	// Header file that contains definition for class called StatisticalDistribution

namespace DevonKaberna
{
	namespace Utilities
	{
		template <typename T>
		NormalDistribution<T>::NormalDistribution() : StatisticalDistribution(), m_normal(new normal_distribution<T>()) {}   // Default constructor
																															 // If omitted will default m_normal to variate (0,1)

		// Override constructor passes into the initial mean/std deviation that boost library normal_distribution requires - if omitted will default to (0,1)
		template <typename T>
		NormalDistribution<T>::NormalDistribution(const T& _start_mean, const T& _start_stdev) : StatisticalDistribution(_start_mean, _start_stdev), m_normal(new normal_distribution<T>(_start_mean, _start_stdev)) {}

		template <typename T>
		NormalDistribution<T>::NormalDistribution(const NormalDistribution<T>& source) : StatisticalDistribution(source) { Copy(source); }	// Copy constructor

		template <typename T>
		NormalDistribution<T>& NormalDistribution<T>::operator = (const NormalDistribution<T>& source) // Assignment operator
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			// Call base class assignment
			StatisticalDistribution<T>::operator= (source);

			// Copy state
			m_normal = new normal_distribution<T>();  //Create new pointer to normal_distribution boost library
			*m_normal = *source.m_normal;  // Assign existing pointer to new pointer of normal_distribution boost library

			return *this;
		}

		template <typename T>
		NormalDistribution<T>::~NormalDistribution() { delete m_normal; }  // Destructor
																		   // Delete pointer

		template <typename T>
		void NormalDistribution<T>::Copy(const NormalDistribution<T>& source)   // Copy private data members
		{
			m_normal = new normal_distribution<T>(this->Mean, this->StandardDeviation);  //Create new pointer to normal_distribution boost library
			*m_normal = *source.m_normal; // Assign existing pointer to new pointer of normal_distribution boost library
		}

		// Implementation of the normal (Gaussian) probability density function
		// Calls boost:math::normal_distribution library - pdf
		// Passes in pointer of type normal_distribution<T>, and parameter x - Distributional properties
		// Returns pdf as type T
		template <typename T>
		T NormalDistribution<T>::ProbabilityDensityFunction(const double& x) const
		{
			using namespace boost::math;
			return pdf(*m_normal, x);  // Call pdf function in boost::math::normal_distribution library via pointer
		}

		// Implementation of the normal (Gaussian) distribution function
		// Calls boost:math::normal_distribution library - cdf
		// Passes in pointer of type normal_distribution<T>, and parameter x - Distributional properties
		// Returns cdf as type T
		template <typename T>
		T NormalDistribution<T>::CumulativeDistributionFunction(const double& x) const
		{
			using namespace boost::math;
			return cdf(*m_normal, x);  // Call cdf function in boost::math::normal_distribution library via pointer
		}
	}
}
#endif	// NORMAL_DISTRIBUTION_CPP