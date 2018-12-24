// EuropeanOption.cpp
//
// Implementation file for class EuropeanOption.  Derived from VanillaOption.
// Includes standard constructor, copy constructor, assignment operator overload, and destructor.
// This class currently obtains its pricing via pointer to a class called ExactSolutionBSEngine. Therefore current pricing is exact solution black scholes.
// As a future enhancement, this class should be able to obtain pricing via other pricing methodologies such as Monte Carlo, etc.  
// Class also provides greek pricing, put-call parity pricing, and mesh pricing.
//
// Author: Devon Kaberna
//

#ifndef EUROPEAN_OPTION_CPP
#define EUROPEAN_OPTION_CPP

#include "EuropeanOption.hpp"	// Header file that contains definition for object called EuropeanOption

#include <sstream>	// C++ stream buffering
#include <iostream> // C++ style I/O

namespace DevonKaberna
{
	namespace Instrument
	{
		EuropeanOption::EuropeanOption() : VanillaOption() {}  // Default constructor

		EuropeanOption::EuropeanOption(const OptionData& OD) : VanillaOption(OD) { Init(); }  // Overload constructor with option parameters input by end-user

		EuropeanOption::EuropeanOption(const OptionData& OD, const double& b) : VanillaOption(OD, b) { Init(); } // Overload constructor with option parameters input by end-user, along with cost of carry (i.e., "b") override

		EuropeanOption::EuropeanOption(const EuropeanOption& source) : VanillaOption(source) { Copy(source); }	// Copy constructor
		
		EuropeanOption& EuropeanOption::operator = (const EuropeanOption& source)  	// Assignment operator
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			// Call base class assignment
			VanillaOption::operator = (source);

			bs = new ExactSolutionBSEngine();  //Create new pointer to black scholes pricing engine
			*bs = *source.bs;  // Assign existing pointer to new pointer of black scholes pricing engine

			return *this;
		}

		EuropeanOption::~EuropeanOption() { delete bs; } // Destructor
														 //Delete pointer to black scholes pricing engine

		void EuropeanOption::Init()  // Initialization
		{
			// Tried to switch over to a shared_ptr, but am having issues.  Link to black scholes engine is lost everytime class members are called.
			bs = new ExactSolutionBSEngine();  // Initialize pointer to black scholes pricing engine
			//boost::shared_ptr<ExactSolutionBSEngine> bs(new ExactSolutionBSEngine());
		}

		void EuropeanOption::Copy(const EuropeanOption& source)   // Copy private data members
		{
			bs = new ExactSolutionBSEngine();	//Create new pointer to black scholes pricing engine
												// TODO: Pass in initial mean and std dev values to normal distribution class
			*bs = *source.bs; // Assign existing pointer to new pointer of black scholes pricing engine
		}
		
		//Returns option price
		//Pass in option parameters as a vector to the pricing engine
		double EuropeanOption::Price() const
		{
			if (IsCall())  // Call
				return bs->CalculateCallPrice(this->option_vector_data());  
			else
				return bs->CalculatePutPrice(this->option_vector_data());
		}

		//Returns option delta
		//Pass in option parameters as a vector to the pricing engine
		double EuropeanOption::Delta() const  // Get Delta
		{
			if (IsCall())  // Call
				return bs->CalculateCallDelta(this->option_vector_data());
			else
				return bs->CalculatePutDelta(this->option_vector_data());
		}

		//Returns option gamma
		//Pass in option parameters as a vector to the pricing engine
		double EuropeanOption::Gamma() const  // Get Gamma
		{
			return bs->CalculateGamma(this->option_vector_data());
		}

		// Calculate the call(or put) price for a corresponding put(or call) price 
		// Opposite option is passed in as an argument _other_option
		double EuropeanOption::PutCallParity(const EuropeanOption& _other_option) const 
		{
			return bs->CalculatePutCallParity(this->option_vector_data(), _other_option.Price(), this->type());  // Call calc engine and pass in option parameter vector, price of the opposite option, and this object's optoin type (i.e., call/put)
		}

		// Check if a given set of put / call prices satisfy parity
		// Opposite option is passed in as an argument _other_option
		// Epsilon determine margin of error/accuracy
		bool EuropeanOption::IsPutCallParity(const EuropeanOption& _other_option, const double& epsilon) const
		{
			double price = this->Price();  // Obtain price of "this" object
			double price2 = PutCallParity(_other_option);   // Obtain price of the other object
			return ((abs(price - price2)) < epsilon);  // Determine if parity is achieved
		}
		
		// Returns a vector of monotonically increasing range of underlying values of whatever parameter user chooses.
		// Used for end-user presentation purposes.
		// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
		vector<double> EuropeanOption::MeshOptionParamVector(const MeshParamData& _mesh_param_data) const
		{
			Mesher<double> m_mesh_(this->option_vector_data(), _mesh_param_data._start, _mesh_param_data._end, _mesh_param_data._step, _mesh_param_data._property);  // Instantiate Mesher object
			return m_mesh_.MeshVector();   // Call Mesher object and returns mesh array of doubles separated by a mesh size h.
		}

		// Returns a vector of option prices as a function of a monotonically increasing range of S values.
		// Mesher object is passed into the CalculateVector method, along with a function pointer based on whether the object is a call or put.
		// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
		vector<double> EuropeanOption::MeshPriceVector(const MeshParamData& _mesh_param_data) const
		{
			Mesher<double> m_mesh_(this->option_vector_data(), _mesh_param_data._start, _mesh_param_data._end, _mesh_param_data._step, _mesh_param_data._property);  // Instantiate Mesher object
			
			if (IsCall())  // Call
				return bs->CalculateVector(m_mesh_, &DevonKaberna::Engine::ExactSolutionBSEngine::CalculateCallPrice);  // Call CalculateVector function in pricing engine - passing mesher object and CalculateCallPrice as a function pointer
			else
				return bs->CalculateVector(m_mesh_, &DevonKaberna::Engine::ExactSolutionBSEngine::CalculatePutPrice);   // Call CalculateVector function in pricing engine - passing mesher object and CalculatePutPrice as a function pointer
		}

		// Returns a vector of Delta prices as a function of a monotonically increasing range of S values.
		// Mesher object is passed into the CalculateVector method, along with a function pointer based on whether the object is a call or put.
		// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
		vector<double> EuropeanOption::MeshDeltaVector(const MeshParamData& _mesh_param_data) const
		{
			Mesher<double> m_mesh_(this->option_vector_data(), _mesh_param_data._start, _mesh_param_data._end, _mesh_param_data._step, _mesh_param_data._property);  // Instantiate Mesher object

			if (IsCall())  // Call
				return bs->CalculateVector(m_mesh_, &DevonKaberna::Engine::ExactSolutionBSEngine::CalculateCallDelta);  // Call CalculateVector function in pricing engine - passing mesher object and CalculateCallDelta as a function pointer
			else
				return bs->CalculateVector(m_mesh_, &DevonKaberna::Engine::ExactSolutionBSEngine::CalculatePutDelta);  // Call CalculateVector function in pricing engine - passing mesher object and CalculatePutDelta as a function pointer
		}

		// Returns a vector of Gamma prices as a function of a monotonically increasing range of S values.
		// Mesher object is passed into the CalculateVector method, along with a function pointer based on whether the object is a call or put.
		// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
		vector<double> EuropeanOption::MeshGammaVector(const MeshParamData& _mesh_param_data) const
		{
			Mesher<double> m_mesh_(this->option_vector_data(), _mesh_param_data._start, _mesh_param_data._end, _mesh_param_data._step, _mesh_param_data._property);  // Instantiate Mesher object

			return bs->CalculateVector(m_mesh_, &DevonKaberna::Engine::ExactSolutionBSEngine::CalculateGamma);  // Call CalculateVector function in pricing engine - passing mesher object and CalculateGamma as a function pointer
			// currently returns a vector of different S parameters
		}

		// Returns a "matrix" (i.e., vector of vectors) of option parameters. Used for end-user presentation purposes.
		vector<vector<double> > EuropeanOption::MeshOptionParamMatrix(const MeshParamData& _mesh_param_data) const
		{
			Mesher<double> m_mesh_(this->option_vector_data(), _mesh_param_data._start, _mesh_param_data._end, _mesh_param_data._step, _mesh_param_data._property);  // Instantiate Mesher object
			return m_mesh_.MeshParamMatrix();  // Return matrix of option parameters
		}

		// Returns a vector of option prices as a function of i) expiry time, ii) volatility, or iii) any of the option pricing parameters.
		// Mesher object is passed into the CalculateMesh method, along with a function pointer based on whether the object is a call or put.
		// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
		vector<double> EuropeanOption::MeshPriceMatrix(const MeshParamData& _mesh_param_data) const
		{
			Mesher<double> m_mesh_(this->option_vector_data(), _mesh_param_data._start, _mesh_param_data._end, _mesh_param_data._step, _mesh_param_data._property);  // Instantiate Mesher object
		
			if (IsCall())  // Call
				return bs->CalculateMesh(m_mesh_, &DevonKaberna::Engine::ExactSolutionBSEngine::CalculateCallPrice);   // Call CalculateMesh function in pricing engine - passing mesher object and CalculateCallPrice as a function pointer
			else
				return bs->CalculateMesh(m_mesh_, &DevonKaberna::Engine::ExactSolutionBSEngine::CalculatePutPrice);   // Call CalculateMesh function in pricing engine - passing mesher object and CalculatePutPrice as a function pointer
		}

		// Returns a vector of delta prices as a function of i) expiry time, ii) volatility, or iii) any of the option pricing parameters.
		// Mesher object is passed into the CalculateMesh method, along with a function pointer based on whether the object is a call or put.
		// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
		vector<double> EuropeanOption::MeshDeltaMatrix(const MeshParamData& _mesh_param_data) const
		{
			Mesher<double> m_mesh_(this->option_vector_data(), _mesh_param_data._start, _mesh_param_data._end, _mesh_param_data._step, _mesh_param_data._property);  // Instantiate Mesher object

			if (IsCall())  // Call
				return bs->CalculateMesh(m_mesh_, &DevonKaberna::Engine::ExactSolutionBSEngine::CalculateCallDelta);   // Call CalculateMesh function in pricing engine - passing mesher object and CalculateCallDelta as a function pointer
			else
				return bs->CalculateMesh(m_mesh_, &DevonKaberna::Engine::ExactSolutionBSEngine::CalculatePutDelta);   // Call CalculateMesh function in pricing engine - passing mesher object and CalculatePutDelta as a function pointer
		}

		// Returns a vector of gamma prices as a function of i) expiry time, ii) volatility, or iii) any of the option pricing parameters.
		// Mesher object is passed into the CalculateMesh method, along with a function pointer based on whether the object is a call or put.
		// Struct MeshParamData is passed in with all necessary mesh parameters needed to instatiate Mesher object.
		vector<double> EuropeanOption::MeshGammaMatrix(const MeshParamData& _mesh_param_data) const
		{
			Mesher<double> m_mesh_(this->option_vector_data(), _mesh_param_data._start, _mesh_param_data._end, _mesh_param_data._step, _mesh_param_data._property);  // Instantiate Mesher object

			return bs->CalculateMesh(m_mesh_, &DevonKaberna::Engine::ExactSolutionBSEngine::CalculateGamma);   // Call CalculateMesh function in pricing engine - passing mesher object and CalculateGamma as a function pointer
		}

		// Uses divided differences to approximate option sensitivities for delta via numerical methods.
		// This function approximate first - order derivatives in S by 3 - point second order approximations.
		// H override passed in as an argument.  Option price is returned from this function.
		double EuropeanOption::DeltaApprox(const double& _h) const // Get delta approximate
		{
			if (IsCall())  // Call
				return CallDeltaApprox(_h);   // Call delta "approx" is returned from this function.
			else
				return PutDeltaApprox(_h);   // Put delta "approx" is returned from this function.
		}

		// Uses divided differences to approximate option sensitivities for gamma via numerical methods.
		// This function approximate second - order derivatives in S by 3 - point second order approximations.
		// H override passed in as an argument.  Option price is returned from this function.
		double EuropeanOption::GammaApprox(const double& _h) const // Get gamma approximate
		{
			if (IsCall())  // Call
				return CallGammaApprox(_h);  // Call gamma "approx" is returned from this function.
			else
				return PutGammaApprox(_h);   // Put gamma "approx" is returned from this function.
		}


		// Uses divided differences to approximate option sensitivities for delta via numerical methods.
		// This function approximate first - order derivatives in S by 3 - point second order approximations.
		// H override passed in as an argument.  Call Delta "approx" is returned from this function.
		double EuropeanOption::CallDeltaApprox(const double& _h) const // Get call delta approximate
		{
			vector<double> _Option_Params_Plus = this->option_vector_data();  // Return this object's option parameters as a vector
			_Option_Params_Plus[0] += _h;  // Add h to S parameter

			vector<double> _Option_Params_Minus = this->option_vector_data();  // Return this object's option parameters as a vector
			_Option_Params_Minus[0] -= _h;  // Subtract h from S parameter

		
			double result_plus_h = bs->CalculateCallPrice(_Option_Params_Plus);  // Obtain call option price for the + scenario
			double result_minus_h = bs->CalculateCallPrice(_Option_Params_Minus);  // Obtain call option price for the - scenario
			
			return (result_plus_h - result_minus_h) / (2 * _h);  // Calc the "approximate" call option price
		}

		// Uses divided differences to approximate option sensitivities for delta via numerical methods.
		// This function approximate first - order derivatives in S by 3 - point second order approximations.
		// H override passed in as an argument.   Put Delta "approx" is returned from this function.
		double EuropeanOption::PutDeltaApprox(const double& _h) const // Get put delta approximate
		{
			vector<double> _Option_Params_Plus = this->option_vector_data();  // Return this object's option parameters as a vector
			_Option_Params_Plus[0] += _h;   // Add h to S parameter

			vector<double> _Option_Params_Minus = this->option_vector_data();  // Return this object's option parameters as a vector
			_Option_Params_Minus[0] -= _h;   // Subtract h from S parameter


			double result_plus_h = bs->CalculatePutPrice(_Option_Params_Plus);  // Obtain put option price for the + scenario
			double result_minus_h = bs->CalculatePutPrice(_Option_Params_Minus);  // Obtain put option price for the - scenario

			return (result_plus_h - result_minus_h) / (2 * _h);  //Calc the "approximate" put option price
			
		}

		// Uses divided differences to approximate option sensitivities for gamma via numerical methods.
		// This function approximate second - order derivatives in S by 3 - point second order approximations.
		// H override passed in as an argument.  Gamma "approx" is returned from this function.
		double EuropeanOption::CallGammaApprox(const double& _h)  const // Get call gamma approximate
		{
			vector<double> _Option_Params_Plus = this->option_vector_data();  // Return this object's option parameters as a vector
			_Option_Params_Plus[0] += _h;   // Add h to S parameter

			vector<double> _Option_Params_Minus = this->option_vector_data();  // Return this object's option parameters as a vector
			_Option_Params_Minus[0] -= _h;   // Subtract h from S parameter


			double result_plus_h = bs->CalculateCallPrice(_Option_Params_Plus);   // Obtain call option price for the + scenario
			double result_minus_h = bs->CalculateCallPrice(_Option_Params_Minus);   // Obtain call option price for the - scenario
			double result_2x = bs->CalculateCallPrice(this->option_vector_data()) * 2;  //Calc the "approximate" gamma option price

			return (result_plus_h + result_minus_h - result_2x) / (_h * _h);  //Calc the "approximate" gamma call option price
		}

		// Uses divided differences to approximate option sensitivities for gamma via numerical methods.
		// This function approximate second - order derivatives in S by 3 - point second order approximations.
		// H override passed in as an argument.  Gamma "approx" is returned from this function.
		double EuropeanOption::PutGammaApprox(const double& _h) const // Get put gamma approximate
		{
			vector<double> _Option_Params_Plus = this->option_vector_data();  // Return this object's option parameters as a vector
			_Option_Params_Plus[0] += _h;   // Add h to S parameter

			vector<double> _Option_Params_Minus = this->option_vector_data();  // Return this object's option parameters as a vector
			_Option_Params_Minus[0] -= _h;   // Subtract h from S parameter


			double result_plus_h = bs->CalculatePutPrice(_Option_Params_Plus);  // Obtain put gamma option price for the + scenario
			double result_minus_h = bs->CalculatePutPrice(_Option_Params_Minus);  // Obtain put gamma option price for the - scenario
			double result_2x = bs->CalculatePutPrice(this->option_vector_data()) * 2;  //Calc the "approximate" gamma call option price

			return (result_plus_h + result_minus_h - result_2x) / (_h * _h);  //Calc the "approximate" gamma put option price
		}

		// Returns string description of the EuropeanOption
		string EuropeanOption::ToString() const
		{
			std::string s = VanillaOption::ToString();

			stringstream ss;
			ss << s << "EuropeanOption" << endl;

			return ss.str();
		}

		// Overloaded Ostream << operator
		// os is passed in by reference, as is eo of type EuropeanOption
		// Returns os by reference!
		ostream& operator << (ostream& os, const EuropeanOption& e)
		{
			return os << "EuropeanOption" << endl;
		}
	}
}
#endif	// EUROPEAN_OPTION_CPP
