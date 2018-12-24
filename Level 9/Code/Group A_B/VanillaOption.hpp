// VanillaOption.hpp
//
// Header file for abstract class VanillaOption.  VanillaOption is comprised of an ID.
// VanillaOption is the base class for all options that are classified as a "vanilla option".
// Contains functions for price, delta, gamma that are abstract, and must be implemented in derived classes.
// Contains accessor/modifier functions for all option parameters.
// Includes getter function for retrieving the id of the VanillaOption.
// Includes a virtual function ToString() that returns the id of the VanillaOption as a string.
// Includes a Print() function that prints VanillaOption information to the cout object.
//
// Author: Devon Kaberna
//

#ifndef VANILLA_OPTION_HPP
#define VANILLA_OPTION_HPP

#include "OptionData.hpp"  // Header file for struct that contains all option parameters
#include "MeshParamData.hpp"  // Encapsulate mesh parameters

#include "ExactSolutionBSEngine.hpp"
using DevonKaberna::Engine::ExactSolutionBSEngine;

#include "boost/shared_ptr.hpp" // Needed for shared_ptr

#include <iostream> // C++ style I/O
using namespace std;

namespace DevonKaberna
{
	namespace Instrument
	{
		class VanillaOption
		{
		private:
			// Member data for class VanillaOption
			int m_id_;	// Random ID assigned to class for purposes of debugging
			OptionData* m_option_data_;  // Pointer to Option data struct

			double m_S_; // Underlying asset price
			double m_K_;  // Strike
			double m_T_;  // Expiry
			double m_r_;  // Interest rate
			double m_sig_;  // Volatility
			double m_R_;  // Foreign risk free interest rate
			double m_D_;  // dividend
			int m_type_;  // 1 == call, -1 == put
			int m_unam_;  //TODO: Underlying asset; need to improve this
			double m_b_;  // cost of carry;

			void Init(const OptionData& OD, const double& _b);   // Initialize base class
			void Init(const OptionData& OD);   // Initialize base class
			void Copy(const VanillaOption& source);  // Copy base class

		public:
			
			// Constructors
			VanillaOption(); // Default constructor
			VanillaOption(const OptionData& OD);  //Overload constructor with option data struct 
			VanillaOption(const OptionData& OD, const double& _b);  //Overload constructor with option data struct and overridden cost of carry - "b"
			VanillaOption(const VanillaOption& source);	// Copy constructor

			VanillaOption& operator = (const VanillaOption& source); // Assignment operator
			virtual ~VanillaOption();	// Destructor

			bool IsCall() const;  // True if option is a call option
			
			// Accessing functions
			int ID() const;	// Retrieves the ID of the VanillaOption

			// Core functions that must be implemented in all derived classes
			virtual double Price() const = 0; // Get price
			virtual double Delta() const = 0; // Get Delta
			virtual double Gamma() const = 0; // Get Gamma

			// Underlying asset price
			// Getter member-function for m_S_
			// Returns data member m_S_
			virtual double S() const;
			
			// Strike price
			// Getter member-function for m_K_
			// Returns data member m_K_
			virtual double K() const;
			
			// Expiry
			// Getter member-function for m_T_
			// Returns data member m_T_
			virtual double T() const;
			
			// Interest rate
			// Getter member-function for m_r_
			// Returns data member m_r_
			virtual double r() const;
			
			// Volatility
			// Getter member-function for m_sig_
			// Returns data member m_sig_
			virtual double sig() const;
			
			// Foreign risk free rate
			// Getter member-function for m_R_
			// Returns data member m_R_
			virtual double R() const;
			
			// Divididend
			// Getter member-function for m_D_
			// Returns data member m_D_
			virtual double D() const;
			
			// Option type: call or put
			// Getter member-function for m_type_
			// Returns data member m_type_
			virtual int type() const;
			
			// Getter member-function for m_unam_
			// Returns data member m_unam_
			// 1=black-scholes option model; 2= morton model with continuous dividend yield D; 
			// 3=balck-scholes futures option model; 4=garman and kohlhagen currency option model
			virtual int unam() const;
			
			// Getter member-function for m_b_
			// Returns data member m_b_
			virtual double b() const;
			
			// Getter member-function for cost of carry
			// This is assigned to m_b_ - assuming user has not overriden m_b_
			virtual double CalculateCoC() const;
			
			// Getter member-function for m_option_data_
			// Returns data member m_option_data_ in the form of OptionData struct
			virtual OptionData& option_data() const;

			// Getter member-function for m_D_
			// Returns data member m_option_data_ in the form of a vector
			virtual vector<double> option_vector_data() const;

			// Underlying asset price
			// Setter member-function for m_S_
			// Modifies object state of data member m_S_
			virtual void S(const double& _S); 
			
			// Strike price
			// Setter member-function for m_K_
			// Modifies object state of data member m_K_
			virtual void K(const double& _K);

			// Expiry
			// Setter member-function for m_T_
			// Modifies object state of data member m_T_
			virtual void T(const double& _T);
			
			// Interest rate
			// Setter member-function for m_r_
			// Modifies object state of data member m_r_
			virtual void r(const double& _r);

			// Volatility
			// Setter member-function for m_sig_
			// Modifies object state of data member m_sig_
			virtual void sig(const double& _sig);

			// Divididend
			// Setter member-function for m_D_
			// Modifies object state of data member m_D_
			virtual void D(const double& _D);

			// Foreign risk free rate
			// Setter member-function for m_R_
			// Modifies object state of data member m_R_
			virtual void R(const double& _R);

			// Option type: call or put
			// Setter member-function for m_type_
			// Modifies object state of data member m_type_
			virtual void type(const int& _type);
			
			virtual string ToString() const;  // Returns member data of VanillaOption as a string
			void Print() const;	// Prints VanillaOption information to the cout object
		};
	}
}
#endif // VANILLA_OPTION_HPP