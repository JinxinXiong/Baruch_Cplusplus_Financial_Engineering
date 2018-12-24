// VanillaOption.cpp
//
// Implementation file for abstract class VanillaOption.  VanillaOption is comprised of an ID.
// VanillaOption is the base class for all options that are classified as a "vanilla option".
// Contains functions for price, delta, gamma that are abstract, and must be implemented in derived classes.
// Contains accessor/modifier functions for all option parameters.
// Includes getter function for retrieving the id of the VanillaOption.
// Includes a virtual function ToString() that returns the id of the VanillaOption as a string.
// Includes a Print() function that prints VanillaOption information to the cout object.
//
// Author: Devon Kaberna
//

#ifndef VANILLA_OPTION_CPP
#define VANILLA_OPTION_CPP

#include "VanillaOption.hpp"	// Header file that contains definition for object called VanillaOption

#include <sstream>	// C++ stream buffering
#include <iostream> // C++ style I/O

#include "stdlib.h" // Header file that contains rand(), which generates random numbers

namespace DevonKaberna
{
	namespace Instrument
	{
		VanillaOption::VanillaOption() : m_id_(rand()), m_S_(0), m_K_(0), m_T_(0), m_r_(0), m_sig_(0), m_R_(0), m_D_(0), m_type_(0), m_unam_(0), m_b_(0) {}  // Default constructor

		VanillaOption::VanillaOption(const OptionData& OD) { Init(OD); }  //Overload constructor with option data struct 

		VanillaOption::VanillaOption(const OptionData& OD, const double& _b) { Init(OD, _b); }   //Overload constructor with option data struct and overridden cost of carry - "b"

		VanillaOption::VanillaOption(const VanillaOption& source) { Copy(source); }	// Copy constructor

		// Assignment operator
		VanillaOption& VanillaOption::operator = (const VanillaOption& source)
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			// Copy state
			Copy(source);

			return *this;
		}

		VanillaOption::~VanillaOption() { delete m_option_data_; }  // Destructor
																	// Destroy pointer to option data struct
		
		bool VanillaOption::IsCall() const { return m_type_ == 1; }   // True if option is a call option

		void VanillaOption::Init(const OptionData& OD)   // Initialize base class
		{
			m_id_ = rand();
			m_S_= OD.S;
			m_K_ = OD.K;
			m_T_= OD.T;
			m_r_ = OD.r ;
			m_sig_ = OD.sig;
			m_R_ = OD.R;
			m_D_ = OD.D;
			m_type_= OD.type;
			m_unam_ = OD.unam;
			m_b_ = CalculateCoC();

			m_option_data_ = new OptionData(OD);  // Init pointer to optiondata struct
		}

		void VanillaOption::Init(const OptionData& OD, const double& _b)   // Initialize base class
		{
			m_id_ = rand();
			m_S_ = OD.S;
			m_K_ = OD.K;
			m_T_ = OD.T;
			m_r_ = OD.r;
			m_sig_ = OD.sig;
			m_R_ = OD.R;
			m_D_ = OD.D;
			m_type_ = OD.type;
			m_unam_ = OD.unam;
			if (_b > 0)
				m_b_ = _b;  //Override from derived class if input greater than 0, otherwise derive via CalculateCoC()
			else
				m_b_ = CalculateCoC();

			m_option_data_ = new OptionData(OD);  // Init pointer to optiondata struct
		}

		void VanillaOption::Copy(const VanillaOption& source)  // Copy private data members
		{
			m_id_ = source.m_id_;
			m_S_ = source.m_S_;
			m_K_ = source.m_K_;
			m_T_ = source.m_T_;
			m_r_ = source.m_r_;
			m_sig_ = source.m_sig_;
			m_R_ = source.m_R_;
			m_D_ = source.m_D_;
			m_type_ = source.m_type_;
			m_unam_ = source.m_unam_;
			m_b_ = source.m_b_;

			m_option_data_ = new OptionData(source.option_data());  // Init pointer to optiondata struct
			*m_option_data_ = *source.m_option_data_;  // Copy data from existing pointer to new pointer
		}

		// Getter member-function for m_id_, which is the ID of the VanillaOption
		// Returns data member m_id_
		int VanillaOption::ID() const { return m_id_; }

		// Getter member-function for m_option_data_
		// Returns data member m_option_data_ in the form of OptionData struct
		OptionData& VanillaOption::option_data() const { return *m_option_data_; }

		// Getter member-function for m_D_
		// Returns data member m_option_data_ in the form of a vector
		vector<double> VanillaOption::option_vector_data() const
		{
			std::vector<double> v(6);
			
			/*v[0] = S();
			v[1] = K();
			v[2] = r();
			v[3] = T();
			v[4] = sig();
			v[5] = b();*/
			
			// Assign each option parameter to vector
			v[0] = m_S_;
			v[1] = m_K_;
			v[2] = m_r_;
			v[3] = m_T_;
			v[4] = m_sig_;
			v[5] = m_b_;
		
			return v;
		}

		// Underlying asset price
		// Getter member-function for m_S_
		// Returns data member m_S_
		double VanillaOption::S() const { return m_S_; }

		// Strike price
		// Getter member-function for m_K_
		// Returns data member m_K_
		double VanillaOption::K() const { return m_K_; }

		// Expiry
		// Getter member-function for m_T_
		// Returns data member m_T_
		double VanillaOption::T() const { return m_T_; }

		// Interest rate
		// Getter member-function for m_r_
		// Returns data member m_r_
		double VanillaOption::r() const { return m_r_; }

		// Volatility
		// Getter member-function for m_sig_
		// Returns data member m_sig_
		double VanillaOption::sig() const { return m_sig_; }

		// Divididend
		// Getter member-function for m_D_
		// Returns data member m_D_
		double VanillaOption::D() const { return m_D_; }

		// Foreign risk free rate
		// Getter member-function for m_R_
		// Returns data member m_R_
		double VanillaOption::R() const { return m_R_; }

		// Option type: call or put
		// Getter member-function for m_type_
		// Returns data member m_type_
		int VanillaOption::type() const { return m_type_; }

		// Getter member-function for m_unam_
		// Returns data member m_unam_
		// 1=black-scholes option model; 2= morton model with continuous dividend yield D; 
		// 3=balck-scholes futures option model; 4=garman and kohlhagen currency option model
		int VanillaOption::unam() const { return m_unam_; }

		// Getter member-function for m_b_
		// Returns data member m_b_
		double VanillaOption::b() const { return m_b_; }

		// Getter member-function for cost of carry
		// This is assigned to m_b_ - assuming user has not overriden m_b_
		double VanillaOption::CalculateCoC() const
		{
			double temp_b; 
			switch (m_unam_) 
			{
			case 1: // black-scholes option model
				temp_b = m_r_;
				break;
			case 2: // morton model with continuous dividend yield D
				temp_b = m_r_ - m_D_;
				break;
			case 3: // balck-scholes futures option model
				temp_b = 0;
				break;
			case 4: // garman and kohlhagen currency option model
				temp_b = m_r_ - m_R_;
				break;
			default:
				temp_b = m_r_;
				break;
			}
			return temp_b;
		}
		
		// Underlying asset price
		// Setter member-function for m_S_
		// Modifies object state of data member m_S_
		void VanillaOption::S(const double& _S) { m_S_ = _S; }

		// Strike price
		// Setter member-function for m_K_
		// Modifies object state of data member m_K_
		void VanillaOption::K(const double& _K) { m_K_ = _K; }

		// Expiry
		// Setter member-function for m_T_
		// Modifies object state of data member m_T_
		void VanillaOption::T(const double& _T) { m_T_ = _T; }

		// Interest rate
		// Setter member-function for m_r_
		// Modifies object state of data member m_r_
		void VanillaOption::r(const double& _r) { m_r_ = _r; }

		// Volatility
		// Setter member-function for m_sig_
		// Modifies object state of data member m_sig_
		void VanillaOption::sig(const double& _sig) { m_sig_ = _sig; }

		// Divididend
		// Setter member-function for m_D_
		// Modifies object state of data member m_D_
		void VanillaOption::D(const double& _D) { m_D_ = _D; }

		// Foreign risk free rate
		// Setter member-function for m_R_
		// Modifies object state of data member m_R_
		void VanillaOption::R(const double& _R) { m_R_ = _R; }

		// Option type: call or put
		// Setter member-function for m_type_
		// Modifies object state of data member m_type_
		void VanillaOption::type(const int& _type) { m_type_ = _type; }
		
		// Returns string description of the VanillaOption
		string VanillaOption::ToString() const
		{
			stringstream ss;
			//ss << "ID: " << m_id_ << " Expiry: " << m_T_ << ", " << " Strike: " << m_K_ << ", ";
			ss << "ID: " << m_id_ << endl;

			return ss.str();
		}

		// Prints VanillaOption information to the cout object
		void VanillaOption::Print() const	{std::cout << ToString();}
	}
}
#endif	// VANILLA_OPTION_CPP