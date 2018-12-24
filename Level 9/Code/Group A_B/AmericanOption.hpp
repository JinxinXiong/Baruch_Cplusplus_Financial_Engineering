// AmericanOption.hpp
//
// Header file for class AmericanOption.  Derived from VanillaOption.
// Includes standard constructor, copy constructor, assignment operator overload, and destructor.
// Includes a virtual ToString function output, and a Print() function that prints AmericanOption information to the cout object.
// This class currently does not contain any real functionality at current point 
// An American option is a contract that can be exercised at any time prior to T.  Therefore it cannot be priced using an exact solution.
// As a future enhancement, this class might eventually be assocaited with a different pricing engine.
//
// Author: Devon Kaberna
//

#ifndef AMERICAN_OPTION_HPP
#define AMERICAN_OPTION_HPP

#include "VanillaOption.hpp"  // Header file for base class VanillaOption
#include "OptionData.hpp"  // Header file for struct that contains all option parameters

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Instrument
	{
		class AmericanOption : public VanillaOption  //Inherits from base class VanillaOption
		{
		private:
			// No member data for class AmericanOption
			
		public:
			// Constructors
			AmericanOption();  // Default constructor
			AmericanOption(const OptionData& OD);  // Overload constructor
			AmericanOption(const OptionData& OD, const double& _b); //Overload constructor with OptionData struct and cost of carry
			AmericanOption(const AmericanOption& source);  // Copy constructor

			AmericanOption& operator = (const AmericanOption& source);  // Assignment operator
			virtual ~AmericanOption();	// Destructor

			// Accessing functions
			virtual double Price() const;  // Get Price - no current functionality.  For future enhancement.
			virtual double Delta() const;  // Get Delta - no current functionality.  For future enhancement.
			virtual double Gamma() const;  // Get Gamma - no current functionality.  For future enhancement.
			
			virtual string ToString() const;  // Returns string description of the AmericanOption

			// Overloaded Ostream << operator
			friend ostream& operator << (ostream& os, const AmericanOption& a);	// Send to ostream
		};
	}
}
#endif // AMERICAN_OPTION_HPP