// NormalDistribution.hpp
//
// Header file for class NormalDistribution (aka, Gaussian Distribution).
// Derived class of class StatisticalDistribution
// This class implements cdf and pdf.
// Also contains standard constructor, copy constructor, destructor, and assignment operator.
// Also contains setter/getter functions for mean and std. deviation.
//
// Author: Devon Kaberna
//

#ifndef NORMAL_DISTRIBUTION_HPP
#define NORMAL_DISTRIBUTION_HPP

#include "StatisticalDistribution.hpp" 	// Header file that contains definition for class called StatisticalDistribution

#include <boost/math/distributions/normal.hpp>  // Normal distribution header file
using namespace boost::math; // Don't forget to tell compiler which namespace

namespace DevonKaberna
{
	namespace Utilities
	{
		template <typename T> // T is the 'class RealType' within boost library class normal_distribution,  U is mean, V is std. dev
		class NormalDistribution : public StatisticalDistribution<T>
		{
		private:
			// Data members of NormalDistribution
			boost::math::normal_distribution<T>* m_normal;  // Pointer to boost::math::normal_distribution<T> library

		public:
			// Constructors
			NormalDistribution();  // Default constructor
			NormalDistribution(const T& _start_mean, const T& _start_stdev);  // Override constructor passes into the initial mean/std deviation that boost library normal_distribution requires.  If omitted will default to (0,1)
			NormalDistribution(const NormalDistribution<T>& source);  // Copy constructor
			NormalDistribution<T>& operator = (const NormalDistribution<T>& source);  // Assignment operator
			virtual ~NormalDistribution();	// Destructor

			void Copy(const NormalDistribution<T>& source); // Copy privata data members

			// Implementation of the normal (Gaussian) probability density function
			// Calls boost:math::normal_distribution library - pdf
			// Passes in pointer of type normal_distribution<T>, and parameter x - Distributional properties
			// Returns pdf as type T
			virtual T ProbabilityDensityFunction(const double& x) const;

			// Implementation of the normal (Gaussian) distribution function
			// Calls boost:math::normal_distribution library - cdf
			// Passes in pointer of type normal_distribution<T>, and parameter x - Distributional properties
			// Returns cdf as type T
			virtual T CumulativeDistributionFunction(const double& x) const; 
		};
	}
}
#ifndef NORMAL_DISTRIBUTION_CPP
#include "NormalDistribution.cpp"
#endif // NORMAL_DISTRIBUTION_CPP

#endif // NORMAL_DISTRIBUTION_HPP