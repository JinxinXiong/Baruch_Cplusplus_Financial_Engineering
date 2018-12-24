// ExactSolutionBSEngine.cpp
//
// Implementation file for class ExactSolutionBSEngine.  Derived from class PricingEngine.
// This class is the heart of the black scholes exact solution.  Provides pricing for calls/put, greeks, and mesh pricing.
// This class calls NormalDistribution (aka, Gaussian Distribution) to obtain cdf and pdf via a "wrapper" class.
//
// Author: Devon Kaberna
//

#ifndef EXACT_SOLUTION_BS_ENGINE_CPP
#define EXACT_SOLUTION_BS_ENGINE_CPP

#include "ExactSolutionBSEngine.hpp"	// Header file that contains definition for object called ExactSolutionBSEngine

namespace DevonKaberna
{
	namespace Engine
	{
		ExactSolutionBSEngine::ExactSolutionBSEngine() : PricingEngine() { Init(); }  // Default constructor

		ExactSolutionBSEngine::ExactSolutionBSEngine(const ExactSolutionBSEngine& source) : PricingEngine(source) { Copy(source); }	// Copy constructor

		ExactSolutionBSEngine& ExactSolutionBSEngine::operator = (const ExactSolutionBSEngine& source)  // Assignment operator
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			// Call base class assignment
			PricingEngine::operator = (source);

			myNormal = new NormalDistribution<double>();	// Even if I declared myNormal(), boost would by default initialize variate to (0,1)	
			*myNormal = *source.myNormal;

			return *this;
		}

		ExactSolutionBSEngine::~ExactSolutionBSEngine() { delete myNormal; }	// Destructor deletes pointer

		void ExactSolutionBSEngine::Init() // Initialize
		{
			myNormal = new NormalDistribution<double>(0, 1);    // Create the Standard normal distribution variate {0,1} functor 
																// Even if I declared myNormal(), boost would by default initialize variate to (0,1)
																// TODO: need to parameterize the mean/std dev to initialize other start values
		}

		void ExactSolutionBSEngine::Copy(const ExactSolutionBSEngine& source) // Copy
		{
			myNormal = new NormalDistribution<double>();		// Create new pointer and copy contents of existing pointer over to new ptr										
			*myNormal = *source.myNormal;
		}

		// Boolean functions to determine if object is call or put
		bool ExactSolutionBSEngine::IsCall(const OptionData& OD) const { return OD.type == 1; }
		bool ExactSolutionBSEngine::IsCall(const int& _option_type) const { return _option_type == 1; }

		// Inputs into the standard cumulative normal (Gaussian) distribution function
		// Passes in each individual option parameter as arguments
		double ExactSolutionBSEngine::d1_(const double& S, const double& K, const double& r, const double& T, const double& sig, const double& b) const
		{
			double tmp = sig * sqrt(T);
			return (log(S / K) + (b + (sig*sig)*0.5) * T) / tmp;
		}

		// Inputs into the standard cumulative normal (Gaussian) distribution function
		// Passes in OptionData struct and cost of carry (b) as arguments
		double ExactSolutionBSEngine::d1_(const OptionData& OD, const double& b) const
		{
			double tmp = OD.sig * sqrt(OD.T);
			return (log(OD.S / OD.K) + (b + (OD.sig*OD.sig)*0.5) * OD.T) / tmp;
		}

		// Inputs into the standard cumulative normal (Gaussian) distribution function
		// Passes in each individual option parameter as arguments
		double ExactSolutionBSEngine::d2_(const double& S, const double& K, const double& r, const double& T, const double& sig, const double& b) const
		{
			return d1_(S, K, r, T, sig, b) - (sig * sqrt(T));
		}

		// Inputs into the standard cumulative normal (Gaussian) distribution function
		// Passes in OptionData struct and cost of carry (b) as arguments
		double ExactSolutionBSEngine::d2_(const OptionData& OD, const double& b) const
		{
			return d1_(OD, b) - (OD.sig * sqrt(OD.T));
		}

		// Calculcates vanilla option call price passing in a vector of option params for one option
		double ExactSolutionBSEngine::CalculateCallPrice(const vector<double>& _Option_Params) const
		{
			// The following provide a mapping of the option param vector to each of the individual parameters
			/*v[0] = S();
			v[1] = K();
			v[2] = r();
			v[3] = T();
			v[4] = sig();
			v[5] = b();*/

			return (_Option_Params[0] * exp((_Option_Params[5] - _Option_Params[2])*_Option_Params[3]) * norm_cdf(d1_(_Option_Params[0], _Option_Params[1], _Option_Params[2], _Option_Params[3], _Option_Params[4], _Option_Params[5]))) - (_Option_Params[1] * exp(-_Option_Params[2] * _Option_Params[3])* norm_cdf(d2_(_Option_Params[0], _Option_Params[1], _Option_Params[2], _Option_Params[3], _Option_Params[4], _Option_Params[5])));
		}

		// Calculcates vanilla option put price passing in a vector of option params for one option
		double ExactSolutionBSEngine::CalculatePutPrice(const vector<double>& _Option_Params) const
		{
			// The following provide a mapping of the option param vector to each of the individual parameters
			/*v[0] = S();
			v[1] = K();
			v[2] = r();
			v[3] = T();
			v[4] = sig();
			v[5] = b();*/

			return -_Option_Params[0] * exp((_Option_Params[5] - _Option_Params[2])*_Option_Params[3]) * norm_cdf(-d1_(_Option_Params[0], _Option_Params[1], _Option_Params[2], _Option_Params[3], _Option_Params[4], _Option_Params[5])) + _Option_Params[1] * exp(-_Option_Params[2] * _Option_Params[3]) * norm_cdf(-d2_(_Option_Params[0], _Option_Params[1], _Option_Params[2], _Option_Params[3], _Option_Params[4], _Option_Params[5]));
		}

		// Standard cumulative normal(Gaussian) distribution function
		// Calls class NormalDistribution, function CumulativeDistributionFunction via a "wrapper" class
		double ExactSolutionBSEngine::norm_cdf(const double& _d_x) const
		{
			return Wrapper<NormalDistribution<double>, &NormalDistribution<double>::CumulativeDistributionFunction>(*myNormal, _d_x);
		}

		// Standard probability distribution function
		// Calls class NormalDistribution, function ProbabilityDensityFunction via a "wrapper" class
		double ExactSolutionBSEngine::norm_pdf(const double& _d_x) const
		{
			return Wrapper<NormalDistribution<double>, &NormalDistribution<double>::ProbabilityDensityFunction>(*myNormal, _d_x);
		}


		// Calculate the European vanilla call Delta passing in option params
		double ExactSolutionBSEngine::CalculateCallDelta(const double& S, const double& K, const double& r, const double& T, const double& sig, const double& b) const
		{
			double tmp = sig * sqrt(T);

			double d1 = (log(S / K) + (b + (sig*sig)*0.5) * T) / tmp;

			return exp((b - r)*T) * norm_cdf(d1);
		}

		// Calculate the European vanilla call Delta passing in vector of option params
		double ExactSolutionBSEngine::CalculateCallDelta(const vector<double>& _Option_Params) const
		{
			// The following provide a mapping of the option param vector to each of the individual parameters
			/*v[0] = S();
			v[1] = K();
			v[2] = r();
			v[3] = T();
			v[4] = sig();
			v[5] = b();*/

			double tmp = _Option_Params[4] * sqrt(_Option_Params[3]);

			double d1 = (log(_Option_Params[0] / _Option_Params[1]) + (_Option_Params[5] + (_Option_Params[4] * _Option_Params[4])*0.5) * _Option_Params[3]) / tmp;

			return exp((_Option_Params[5] - _Option_Params[2])*_Option_Params[3]) * norm_cdf(d1);
		}

		// Calculate the European vanilla put Delta passing in vector of option params
		double ExactSolutionBSEngine::CalculatePutDelta(const double& S, const double& K, const double& r, const double& T, const double& sig, const double& b) const
		{
			double tmp = sig * sqrt(T);

			double d1 = (log(S / K) + (b + (sig*sig)*0.5) * T) / tmp;

			return exp((b - r)*T) * (norm_cdf(d1) - 1.0);
		}

		// Calculate the European vanilla put Delta passing in option params
		double ExactSolutionBSEngine::CalculatePutDelta(const vector<double>& _Option_Params) const
		{
			// The following provide a mapping of the option param vector to each of the individual parameters
			/*v[0] = S();
			v[1] = K();
			v[2] = r();
			v[3] = T();
			v[4] = sig();
			v[5] = b();*/

			double tmp = _Option_Params[4] * sqrt(_Option_Params[3]);

			double d1 = (log(_Option_Params[0] / _Option_Params[1]) + (_Option_Params[5] + (_Option_Params[4] * _Option_Params[4])*0.5) * _Option_Params[3]) / tmp;

			return exp((_Option_Params[5] - _Option_Params[2])*_Option_Params[3]) * (norm_cdf(d1) - 1.0);
		}

		// Calculate the European vanilla gamma  passing in vector of option params
		double ExactSolutionBSEngine::CalculateGamma(const vector<double>& _Option_Params) const
		{
			// The following provide a mapping of the option param vector to each of the individual parameters
			/*v[0] = S();
			v[1] = K();
			v[2] = r();
			v[3] = T();
			v[4] = sig();
			v[5] = b();*/

			return (norm_pdf(d1_(_Option_Params[0], _Option_Params[1], _Option_Params[2], _Option_Params[3], _Option_Params[4], _Option_Params[5])) * exp((_Option_Params[5] - _Option_Params[2])* _Option_Params[3])) / (_Option_Params[0] * _Option_Params[4] * sqrt(_Option_Params[3]));
		} 

		// Calculate the call(or put) price for a corresponding put(or call) price  passing in vector of option params
		// Opposite option is passed in as an argument of _opposite_option_price
		double ExactSolutionBSEngine::CalculatePutCallParity(const vector<double>& _Option_Params, const double& _opposite_option_price, const int& _option_type) const
		{
			// The following provide a mapping of the option param vector to each of the individual parameters
			/*v[0] = S();
			v[1] = K();
			v[2] = r();
			v[3] = T();
			v[4] = sig();
			v[5] = b();*/

			if (IsCall(_option_type))  // Call
			{
				/*price1 = this->CalculatePutPrice(OD, b);
				price2 = price1 + OD.S - (OD.K * exp(-OD.r*OD.T));
				return price2;*/
				return _opposite_option_price + _Option_Params[0] - (_Option_Params[1] * exp(-_Option_Params[2] * _Option_Params[3]));
			}
			else  // Put
			{
				//price1 = this->CalculateCallPrice(OD, b);
				//price2 = price1 - OD.S + (OD.K * exp(-OD.r*OD.T));
				return _opposite_option_price - _Option_Params[0] + (_Option_Params[1] * exp(-_Option_Params[2] * _Option_Params[3]));
			}
		}

		// Returns a vector of option prices as a function of a monotonically increasing range of S values.
		// Mesher object is passed into the CalculateVector method, along with a function pointer based on whether the object is a call or put.
		vector<double> ExactSolutionBSEngine::CalculateVector(const Mesher<double>& mesh, VectorCalcModel vcm) const
		{
			std::vector<double> _AssetPrices = mesh.MeshVector();  // Instantiate Mesher object

			vector<double> _Option_Params(6);
			_Option_Params = mesh.OptionParamsVector(); // Return mesh array of doubles separated by a mesh size h

			int size = mesh.MeshVector().size(); // Size is driven from user input of mesh size
			int start = 0;
			int j = 0;

			std::vector<double> result(size, start); // Sets up the size of the vector

			for (vector<double>::const_iterator i = _AssetPrices.begin(); i != _AssetPrices.end(); ++i)  // STL iterator that iterates through each value of parameter S
			{
				//Parameter S varies based on increment h.  All other parameters remain constant.
				_Option_Params[0] = *i;  // For each S value in the mesh, override parameter S in the option param vector

				result[j] = std::invoke(vcm, this, _Option_Params);  // CallPrice or PutPrice function is passed in via function pointer; store price in result vector

				j++;
			}
			return result;  // Return vector of option prices
		}

		// Calculcates option price as a function of i) expiry time, ii) volatility, or iii) any of the option pricing parameters.
		// Mesher object provides a "matrix" (i.e., vector of vectors) of option parameters to this function.
		// CallPrice/PutPrice/CallDelta/PutDelta/Gamma passed in as a function pointer in argument vcm.
		vector<double> ExactSolutionBSEngine::CalculateMesh(const Mesher<double>& mesh, MeshModel mm) const
		{
			std::size_t numberOfRows = mesh.MeshVector().size();  // Size is driven from user input of mesh size
			int start = 0;
			int row_arr = 0;

			vector<vector<double> > _OptionParamMatrix = mesh.MeshParamMatrix();  // Mesh object returns a "matrix" (i.e., vector of vectors) of option parameters

			std::vector<double> result(numberOfRows, start);  // Will store vector of option prices
			vector<vector<double> >::const_iterator vvi_iterator;   // STL iterator that iterates through each row of the matrix - each row contains one complete set of option parameters in a vector (1xN)

			for (vvi_iterator = _OptionParamMatrix.begin(); vvi_iterator != _OptionParamMatrix.end(); ++vvi_iterator)  // Loop through each row of option parameters (1xN)
			{
				result[row_arr] = std::invoke(mm, this, *vvi_iterator);  // CallPrice/PutPrice/CallDelta/PutDelta/Gamma functions is passed in via function pointer; store price in result vector (1xN)
				row_arr++;
			}
			return result;   // Return vector of option prices
		}
	}
}
#endif	// EXACT_SOLUTION_BS_ENGINE_CPP

