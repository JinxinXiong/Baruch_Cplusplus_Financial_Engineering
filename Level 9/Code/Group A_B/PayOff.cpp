// PayOff.cpp
//
// Implementation file for abstract class PayOff.
// Includes standard constructor, copy constructor, assignment operator overload, and destructor.
// Includes overloaded () operator, which turns the PayOff into an abstract function object
// THIS IS CURRENTLY NOT IN USE, BUT KEPT HERE FOR FUTURE ENHANCEMENTS TO THIS PROJECT.
//
// Author: Devon Kaberna
//

#ifndef PAY_OFF_CPP
#define PAY_OFF_CPP

#include "PayOff.hpp"  // Header file

namespace DevonKaberna
{
	namespace CALCULATION
	{
		PayOff::PayOff() {}  // Default constructor

		PayOff::PayOff(const PayOff& source) {}	// Copy constructor

		// Assignment operator
		PayOff& PayOff::operator = (const PayOff& source)
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			return *this;
		}

		PayOff::~PayOff() { }	// Destructor

		// PayOffCall.cpp
		//
		// Implementation file for abstract class PayOffCall. Derived from base class PayOff.
		// Includes standard constructor, copy constructor, assignment operator overload, and destructor.
		// Includes overloaded () operator, which turns the PayOffCall into a function object
		//
		// Author: Devon Kaberna
		//

		PayOffCall::PayOffCall() : PayOff() {}  // Default constructor

		PayOffCall::PayOffCall(const double& _K) : PayOff(), m_K_(_K) {} // Overriden constructor with single strike parameter K

		PayOffCall::PayOffCall(const PayOffCall& source) : PayOff(source) {}	// Copy constructor

		// Assignment operator
		PayOffCall& PayOffCall::operator = (const PayOffCall& source)
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			// Call base class assignment
			PayOff::operator = (source);

			return *this;
		}

		// Over-ridden operator() method, which turns PayOffCall into a function object
		double PayOffCall::operator() (const double& S) const 
		{
			return std::max(S - m_K_, 0.0);  // Standard European Call pay-off
		}

		PayOffCall::~PayOffCall() { }	// Destructor

		// PayOffPut.cpp
		//
		// Implementation file for abstract class PayOffPut. Derived from base class PayOff.
		// Includes standard constructor, copy constructor, assignment operator overload, and destructor.
		// Includes overloaded () operator, which turns the PayOff into a function object
		//
		// Author: Devon Kaberna
		//

		PayOffPut::PayOffPut() : PayOff() {}  // Default constructor

		PayOffPut::PayOffPut(const double& _K) : PayOff(), m_K_(_K) {} // Overriden constructor with single strike parameter K

		PayOffPut::PayOffPut(const PayOffPut& source) : PayOff(source) {}	// Copy constructor

		// Assignment operator
		PayOffPut& PayOffPut::operator = (const PayOffPut& source)
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			// Call base class assignment
			PayOff::operator = (source);

			return *this;
		}

		// Over-ridden operator() method, which turns PayOffPut into a function object
		double PayOffPut::operator() (const double& S) const
		{
			return std::max(m_K_ - S, 0.0);  // Standard European Put pay-off
		}

		PayOffPut::~PayOffPut() { }	// Destructor
	}
}
#endif //PAY_OFF_CPP