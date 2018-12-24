// EuropeanOption.hpp
//
// Header file for class EuropeanOption.  Derived from VanillaOption.
// Includes standard constructor, copy constructor, assignment operator overload, and destructor.
// This class currently obtains its pricing via pointer to a class called ExactSolutionBSEngine. Therefore current pricing is exact solution black scholes.
// As a future enhancement, this class should be able to obtain pricing via other pricing methodologies such as Monte Carlo, etc.  
// Class also provides greek pricing, put-call parity pricing, and mesh pricing.
//
// Author: Devon Kaberna
//

#ifndef EUROPEAN_OPTION_HPP
#define EUROPEAN_OPTION_HPP

#include <vector>  // Extensively uses vector as a container

#include "VanillaOption.hpp"   // Header file for base class VanillaOption

#include "Mesher.hpp"  // Provides all functionality needed for obtaining a mesh 
using DevonKaberna::Utilities::Mesher;

#include "OptionData.hpp"  // Header file for struct that contains all option parameters

#include "ExactSolutionBSEngine.hpp"  // Pricing engine for closed form black scholes
using DevonKaberna::Engine::ExactSolutionBSEngine;

#include "boost/shared_ptr.hpp" // Needed for shared_ptr

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Instrument
	{
		class EuropeanOption : public VanillaOption // Inherits from base class VanillaOption
		{
		private:
			// Member data for class EuropeanOption
			ExactSolutionBSEngine* bs;  // Pointer to exact solution black scholes pricing engine
			//boost::shared_ptr<ExactSolutionBSEngine> bs;

			void Init();  // Initialization
			void Copy(const EuropeanOption& source);  // Copy private data members
		
			virtual double CallDeltaApprox(const double& _h) const; // Get call delta approximate
			virtual double PutDeltaApprox(const double& _h) const; // Get put delta approximate
			virtual double CallGammaApprox(const double& _h) const; // Get call gamma approximate
			virtual double PutGammaApprox(const double& _h) const; // Get put gamma approximate

		public:
			// Constructors
			EuropeanOption();  // Default constructor
			EuropeanOption(const OptionData& OD);  // Overload constructor with option parameters input by end-user
			EuropeanOption(const OptionData& OD, const double& b); // Overload constructor with option parameters input by end-user, along with cost of carry (i.e., "b") override
			EuropeanOption(const EuropeanOption& source);  // Copy constructor
			EuropeanOption& EuropeanOption::operator = (const EuropeanOption& source);  // Assignment operator
			virtual ~EuropeanOption();	// Destructor

			// Accessing functions for 1st order/2nd order pricing derivatives
			virtual double Price() const;  // Get Price
			virtual double Delta() const;  // Get Delta
			virtual double Gamma() const;  // Get Gamma
			virtual double DeltaApprox(const double& _h) const; // Get delta approximate
			virtual double GammaApprox(const double& _h) const; // Get gamma approximate
		
			//Put-call parity derivation
			virtual double PutCallParity(const EuropeanOption& _option) const;  // Calculate the call(or put) price for a corresponding put(or call) price 
			virtual bool IsPutCallParity(const EuropeanOption& _other_option, const double& epsilon) const;  // Check if a given set of put / call prices satisfy parity

			// Returns a vector of monotonically increasing range of underlying values of whatever parameter user chooses.
			// Used for end-user presentation purposes.
			// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
			virtual vector<double> MeshOptionParamVector(const MeshParamData& _mesh_param_data) const;
			
			// Returns a "matrix" (i.e., vector of vectors) of option parameters. Used for end-user presentation purposes.
			virtual vector<vector<double> > MeshOptionParamMatrix(const MeshParamData& _mesh_param_data) const;
			
			// Returns a vector of Delta prices as a function of a monotonically increasing range of S values.
			// Mesher object is passed into the CalculateVector method, along with a function pointer based on whether the object is a call or put.
			// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
			virtual vector<double> MeshDeltaVector(const MeshParamData& _mesh_param_data) const;
			
			// Returns a vector of Gamma prices as a function of a monotonically increasing range of S values.
			// Mesher object is passed into the CalculateVector method, along with a function pointer based on whether the object is a call or put.
			// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
			virtual vector<double> MeshGammaVector(const MeshParamData& _mesh_param_data) const;

			// Returns a vector of option prices as a function of a monotonically increasing range of S values.
			// Mesher object is passed into the CalculateVector method, along with a function pointer based on whether the object is a call or put.
			// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
			virtual vector<double> MeshPriceVector(const MeshParamData& _mesh_param_data) const;
			
			// Returns a vector of option prices as a function of i) expiry time, ii) volatility, or iii) any of the option pricing parameters.
			// Mesher object is passed into the CalculateMesh method, along with a function pointer based on whether the object is a call or put.
			// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
			virtual vector<double> MeshPriceMatrix(const MeshParamData& _mesh_param_data) const;

			// Returns a vector of delta prices as a function of i) expiry time, ii) volatility, or iii) any of the option pricing parameters.
			// Mesher object is passed into the CalculateMesh method, along with a function pointer based on whether the object is a call or put.
			// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
			virtual vector<double> MeshDeltaMatrix(const MeshParamData& _mesh_param_data) const;
			
			// Returns a vector of gamma prices as a function of i) expiry time, ii) volatility, or iii) any of the option pricing parameters.
			// Mesher object is passed into the CalculateMesh method, along with a function pointer based on whether the object is a call or put.
			// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
			virtual vector<double> MeshGammaMatrix(const MeshParamData& _mesh_param_data) const;

			virtual string ToString() const;  // Returns string description of the EuropeanOption

			// Overloaded Ostream << operator
			friend ostream& operator << (ostream& os, const EuropeanOption& e);	// Send to ostream
		};
	}
}
#endif // EUROPEAN_OPTION_HPP