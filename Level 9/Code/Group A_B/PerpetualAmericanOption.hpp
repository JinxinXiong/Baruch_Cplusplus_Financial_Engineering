// PerpetualAmericanOption.hpp
//
// Header file for class PerpetualAmericanOption.  Derived from class AmericanOption.
// Includes standard constructor, copy constructor, assignment operator overload, and destructor.
// This class is considered a separate entity than an American option
// because one distinction is that perpetual option price is the time - homogeneous price and is the same 
// as the normal price when the expiry price T tends to infinity.  Therefore the formulas for perpetual american options are embedded within this class.
// Delta and gamma functionality have not yet been fully developed and currently return a -1.
//
// Author: Devon Kaberna
//

#ifndef PERPETUAL_AMERICAN_OPTION_HPP
#define PERPETUAL_AMERICAN_OPTION_HPP

#include "AmericanOption.hpp"  // Header file for base class VanillaOption

#include "Mesher.hpp"  // Provides all functionality needed for obtaining a mesh 
using DevonKaberna::Utilities::Mesher;  

#include "OptionData.hpp"  // Header file for struct that contains all option parameters

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Instrument
	{
		class PerpetualAmericanOption : public AmericanOption  //Inherits from class AmericanOption, which in turn, inherits from base class VanillaOption
		{
		private:
			// Member data for class PerpetualAmericanOption
			virtual double CallPrice(const vector<double>& _Option_Params) const;  // Return call price to end user as type double
			virtual double PutPrice(const vector<double>& _Option_Params) const;  // Return put price to end user as type double

		public:
			// Constructors
			PerpetualAmericanOption();  // Default constructor
			PerpetualAmericanOption(const OptionData& OD); // Overload constructor with option data entered via end user
			PerpetualAmericanOption(const OptionData& OD, const double& _b); // Overload constructor - allows end user to override cost of carry parameter - b_
			PerpetualAmericanOption(const PerpetualAmericanOption& source);  // Copy constructor

			PerpetualAmericanOption& operator = (const PerpetualAmericanOption& source);  // Assignment operator
			virtual ~PerpetualAmericanOption();	// Destructor

			// Accessing functions
			virtual double Price() const;  // Get Price
			virtual double Delta() const;  // Get Delta - no current functionality.  For future enhancement.
			virtual double Gamma() const;  // Get Gamma - no current functionality.  For future enhancement.

			// Returns a vector of monotonically increasing range of underlying values of whatever parameter user chooses.
			// Used for end-user presentation purposes.
			// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
			virtual vector<double> MeshOptionParamVector(const MeshParamData& _mesh_param_data) const;

			// Returns a vector of option prices as a function of a monotonically increasing range of S values.
			// Mesher object is passed into the CalculateVector method, along with a function pointer based on whether the object is a call or put.
			// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
			virtual vector<double> MeshPriceVector(const MeshParamData& _mesh_param_data) const;
			
			// Returns a "matrix" (i.e., vector of vectors) of option parameters. Used for end-user presentation purposes.
			virtual vector<vector<double> > MeshOptionParamMatrix(const MeshParamData& _mesh_param_data) const;

			// Returns a vector of option prices as a function of i) expiry time, ii) volatility, or iii) any of the option pricing parameters.
			// Mesher object is passed into the CalculateMesh method, along with a function pointer based on whether the object is a call or put.
			// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
			virtual vector<double> MeshPriceMatrix(const MeshParamData& _mesh_param_data) const;

			// Calculcates option price as a function of a monotonically increasing range of S values.
			// This function only caters to the "S" parameter. The method CalculateMesh() function is able to compute prices for ANY parameter.
			// Parameter S varies based on increment h.  All other parameters remain constant.
			// Mesher object passed in.  CallPrice/PutPrice passed in as a function pointer in argument vcm.
			typedef double (PerpetualAmericanOption::*VectorCalcModel)(const vector<double>&) const;
			virtual vector<double> CalculateVector(const Mesher<double>& mesh, VectorCalcModel vcm) const;

			// Calculcates option price as a function of i) expiry time, ii) volatility, or iii) any of the option pricing parameters.
			// Mesher object provides a "matrix" (i.e., vector of vectors) of option parameters to this function.
			// CallPrice/PutPrice passed in as a function pointer in argument vcm.
			typedef double (PerpetualAmericanOption::*MeshModel)(const vector<double>&) const;
			virtual vector<double> CalculateMesh(const Mesher<double>& mesh, MeshModel mm) const;

			virtual string ToString() const;  // Returns string description of the AmericanOption

			// Overloaded Ostream << operator
			friend ostream& operator << (ostream& os, const AmericanOption& a);	// Send to ostream
		};
	}
}
#endif // PERPETUAL_AMERICAN_OPTION_HPP