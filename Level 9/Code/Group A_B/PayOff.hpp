// PayOff.hpp
//
// Header file for abstract class PayOff.
// Includes standard constructor, copy constructor, assignment operator overload, and destructor.
// Includes overloaded () operator, which turns the PayOff into an abstract function object
// THIS IS CURRENTLY NOT IN USE, BUT KEPT HERE FOR FUTURE ENHANCEMENTS TO THIS PROJECT.
//
// Author: Devon Kaberna
//

#ifndef PAY_OFF_HPP
#define PAY_OFF_HPP

#include <algorithm> // std::max comparison function
namespace DevonKaberna
{
	namespace CALCULATION
	{
		// Base class
		class PayOff 
		{
		private:
			// Member data for class PayOff

		public:
			PayOff(); // Default constructor
			PayOff(const PayOff& source);	// Copy constructor
			PayOff& operator = (const PayOff& source); // Assignment operator
			virtual ~PayOff();	// Destructor

			virtual double operator() (const double& S) const = 0; // Overloaded () operator, turns the PayOff into an abstract function object
		};

		// PayOffCall.hpp
		//
		// Header file for abstract class PayOffCall. Derived from base class PayOff.
		// Includes standard constructor, copy constructor, assignment operator overload, and destructor.
		// Includes overloaded () operator, which turns the PayOff into an abstract function object
		//
		// Author: Devon Kaberna
		//

		class PayOffCall : public PayOff 
		{
		private:
			double m_K_; // Strike price

		public:
			PayOffCall(); // Default constructor
			PayOffCall(const double& K_);
			PayOffCall(const PayOffCall& source);	// Copy constructor
			PayOffCall& operator = (const PayOffCall& source); // Assignment operator
			virtual ~PayOffCall();

			// Virtual function operator() is now over-ridden
			virtual double operator() (const double& S) const;
		};

		// PayOffPut.hpp
		//
		// Header file for abstract class PayOffCall. Derived from base class PayOff.
		// Includes standard constructor, copy constructor, assignment operator overload, and destructor.
		// Includes overloaded () operator, which turns the PayOff into an abstract function object
		//
		// Author: Devon Kaberna
		//
		class PayOffPut : public PayOff 
		{
		private:
			double m_K_; // Strike price

		public:
			PayOffPut(); // Default constructor
			PayOffPut(const double& K_);
			PayOffPut(const PayOffPut& source);	// Copy constructor
			PayOffPut& operator = (const PayOffPut& source); // Assignment operator
			virtual ~PayOffPut();

			// Virtual function operator() is now over-ridden
			virtual double operator() (const double& S) const;
		};
	}
}

#endif //PAY_OFF_HPP