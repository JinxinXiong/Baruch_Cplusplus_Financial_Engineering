// ExactSolutionBSEngine.hpp
//
// Header file for class ExactSolutionBSEngine. Derives from class PricingEngine.
// This class is the heart of the black scholes exact solution.  Provides pricing for calls/put, greeks, and mesh pricing.
// This class calls NormalDistribution (aka, Gaussian Distribution) to obtain cdf and pdf via a "wrapper" class.
//
// Author: Devon Kaberna
//

#ifndef EXACT_SOLUTION_BS_ENGINE_HPP
#define EXACT_SOLUTION_BS_ENGINE_HPP

#include "PricingEngine.hpp"  // Base class header

#include "NormalDistribution.hpp"  // Header for NormalDistribution (aka, Gaussian Distribution) class
using DevonKaberna::Utilities::NormalDistribution;

#include "StatisticalDistribution.hpp"  // Header for StatisticalDistribution (aka, Gaussian Distribution) class
using DevonKaberna::Utilities::StatisticalDistribution;

#include "Wrapper.hpp"  // Provides "wrapper" functionality for this class (and for any other class for that matter). 
using DevonKaberna::Utilities::Wrapper;

#include "OptionData.hpp" // Header file for struct that contains all option parameters

#include "Mesher.hpp"  // Provides all functionality needed for obtaining a mesh 
using DevonKaberna::Utilities::Mesher;

//#include <memory>  // Provides std::vector

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Engine
	{
		class ExactSolutionBSEngine : public PricingEngine  // Inherits from PricingEngine
		{
		private:
			// Member data for class ExactSolutionBSEngine
			NormalDistribution<double>* myNormal;  // Needed for NormalDistribution (aka, Gaussian Distribution) cdf and pdf

			void ExactSolutionBSEngine::Init();  // Initialization

			// Inputs into the standard cumulative normal (Gaussian) distribution function
			// Passes in each individual option parameter as arguments
			double d1_(const double& S, const double& K, const double& r, const double& T, const double& sig, const double& b) const;

			// Inputs into the standard cumulative normal (Gaussian) distribution function
			// Passes in OptionData struct and cost of carry (b) as arguments
			double d1_(const OptionData& OD, const double& b) const;

			// Inputs into the standard cumulative normal (Gaussian) distribution function
			// Passes in each individual option parameter as arguments
			double d2_(const double& S, const double& K, const double& r, const double& T, const double& sig, const double& b) const;

			// Inputs into the standard cumulative normal (Gaussian) distribution function
			// Passes in OptionData struct and cost of carry (b) as arguments
			double d2_(const OptionData& OD, const double& b) const;

			double norm_cdf(const double& _d_x) const;  // Standard cumulative normal(Gaussian) distribution function
			double norm_pdf(const double& _d_x) const;  // Probability distribution function

			// Boolean functions to determine if object is call or put
			bool IsCall(const OptionData& OD) const;
			bool IsCall(const int& _option_type) const;

			void Copy(const ExactSolutionBSEngine& source);
		public:
			// Constructors
			ExactSolutionBSEngine(); // Default constructor
			ExactSolutionBSEngine(const ExactSolutionBSEngine& source);	// Copy constructor
			ExactSolutionBSEngine& operator = (const ExactSolutionBSEngine& source); // Assignment operator
			virtual ~ExactSolutionBSEngine();	// Destructor

			// Accessing functions

			// Returns price from black scholes as type double
			// Vector of option parameters (i.e., K, S, r, etc.) are passed into the function
			double CalculateCallPrice(const vector<double>& _Option_Params) const;   // Calculate the European vanilla call price
			double CalculatePutPrice(const vector<double>& _Option_Params) const; // Calculate the European vanilla put price  passing in a vector of option params for one option

			// Calculate the European vanilla call Delta passing in option params
			double CalculateCallDelta(const double& S, const double& K, const double& r, const double& T, const double& sig, const double& b) const;
			
			// Calculate the European vanilla call Delta passing in vector of option params
			double CalculateCallDelta(const vector<double>& _Option_Params) const;
			
			// Calculate the European vanilla put Delta passing in vector of option params
			double CalculatePutDelta(const double& S, const double& K, const double& r, const double& T, const double& sig, const double& b) const;
			
			// Calculate the European vanilla put Delta passing in option params
			double CalculatePutDelta(const vector<double>& _Option_Params) const;
			
			// Calculate the European vanilla gamma  passing in vector of option params
			double CalculateGamma(const vector<double>& _Option_Params) const;

			// Calculate the call(or put) price for a corresponding put(or call) price  passing in vector of option params
			// Opposite option is passed in as an argument of _opposite_option_price
			double CalculatePutCallParity(const vector<double>& _Option_Params, const double& _opposite_option_price, const int& _option_type) const;
			
			// Returns a vector of option prices as a function of a monotonically increasing range of S values.
			// Mesher object is passed into the CalculateVector method, along with a function pointer based on whether the object is a call or put.
			typedef double (ExactSolutionBSEngine::*VectorCalcModel)(const vector<double>&) const;
			vector<double> CalculateVector(const Mesher<double>& mesh, VectorCalcModel vcm) const;

			// Calculcates option price as a function of i) expiry time, ii) volatility, or iii) any of the option pricing parameters.
			// Mesher object provides a "matrix" (i.e., vector of vectors) of option parameters to this function.
			// CallPrice/PutPrice/CallDelta/PutDelta/Gamma passed in as a function pointer in argument vcm.
			typedef double (ExactSolutionBSEngine::*MeshModel)(const vector<double>&) const;
			vector<double> CalculateMesh(const Mesher<double>& mesh, MeshModel mm) const;
		};
	}
}
#endif // EXACT_SOLUTION_BS_ENGINE_HPP