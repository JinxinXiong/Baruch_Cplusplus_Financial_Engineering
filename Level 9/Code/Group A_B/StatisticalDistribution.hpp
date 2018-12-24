// StatisticalDistribution.hpp
//
// Header file for class StatisticalDistribution
// This class is an abstract base class that contains a pure virtual function - cdf and pdf.
// Also contains standard constructor, copy constructor, destructor, and assignment operator.
// Also contains implementation of mean/std deviation accessor and modifier methods.
//
// Author: Devon Kaberna
//

#ifndef StatisticalDistribution_HPP
#define StatisticalDistribution_HPP

#include <boost/math/distributions.hpp> // For non-member functions of distributions
using namespace boost::math;  // Don't forget to tell compiler which namespace

namespace DevonKaberna
{
	namespace Utilities
	{
		template <typename T>
		class StatisticalDistribution
		{
		private:
			// Data members of StatisticalDistribution
			T m_mean;  // Mean  
			T m_stdev;  // Standard deviation  

		public:
			// Constructors
			StatisticalDistribution();  // Default constructor
			StatisticalDistribution(const T& _start_mean, const T& _start_stdev);  // Override constructor passes into the initial mean/std deviation that boost library normal_distribution requires.  If omitted will default to (0,1)
			StatisticalDistribution(const StatisticalDistribution<T>& source);	// Copy constructor
			StatisticalDistribution<T>& operator = (const StatisticalDistribution<T>& source); // Assignment operator
			virtual ~StatisticalDistribution();	// Destructor

			// Accessing functions
			virtual T ProbabilityDensityFunction(const double& x) const = 0;  // Implementation of the normal (Gaussian) probability density function required in derived classes
			virtual T CumulativeDistributionFunction(const double& x) const = 0;  // Implementation of the normal (Gaussian) distribution function  required in derived classes
			
			// Getter member-function for Mean
			// Returns data member m_mean
			virtual T Mean() const;

			// Getter member-function for Std. Deviation
			// Returns data member m_stdev
			virtual T StandardDeviation() const;

			// Modifier functions

			// Setter member-function for Mean
			// Modifies object state of data member m_mean
			virtual void Mean(const T& x);

			// Setter member-function for StandardDeviation
			// Modifies object state of data member m_stdev
			virtual void StandardDeviation(const T& x);
		};
	}
}
#ifndef StatisticalDistribution_CPP
#include "StatisticalDistribution.cpp"
#endif // StatisticalDistribution_CPP

#endif // StatisticalDistribution_HPP