// Mesher.cpp
//
// Implementation file for class Mesher. 
// Includes standard constructor, copy constructor, assignment operator overload, and destructor.
// Purpose of this class is to 1.) provide a mesh vector for a monotonically increasing range of underlying values of S, for example 10, 11, 12, …, 50;
// and 2.) return a matrix (vector of vectors) of option parameters based on whatever parameter user chooses (i.e., S, K, r, etc.)
//
// Author: Devon Kaberna
//
#ifndef MESHER_CPP
#define MESHER_CPP

#include "Mesher.hpp"  // Header file

namespace DevonKaberna
{
	namespace Utilities
	{
		template <typename T>
		Mesher<T>::Mesher() : m_start_(0.0), m_end_(0.0), m_step_(0.0), m_property_(0.0) {}   // Default constructor
		
		template <typename T>
		Mesher<T>::Mesher(const std::vector<T>& _option_params, const T& _m_start, const T& _m_end, const T& _m_step, const int& _m_property) { Init(_option_params, _m_start, _m_end, _m_step, _m_property); }   // Overload constructor with mesh settings
		
		template <typename T>
		Mesher<T>::Mesher(const Mesher<T>& source) { Copy(source); } // Copy constructor

		template <typename T>
		Mesher<T>& Mesher<T>::operator = (const Mesher<T>& source) 	// Assignment operator
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			// Copy state
			Copy(source);

			return *this;
		}

		template <typename T>
		Mesher<T>::~Mesher() {} // Destructor

		template <typename T>
		void Mesher<T>::Init(const std::vector<T>& _option_params, const T& _m_start, const T& _m_end, const T& _m_step, const int& _m_property)
		{
			// Initialize member data based on user defined mesh settings
			m_start_ = _m_start;
			m_end_ = _m_end;
			m_step_ = _m_step;
			m_property_ = _m_property;
			m_option_params_ = _option_params;
		}

		template <typename T>
		void Mesher<T>::Copy(const Mesher<T>& source)
		{
			// Copy mesh settings
			m_start_ = source.m_start_;
			m_end_ = source.m_end_;
			m_step_ = source.m_step_;
			m_property_ = source.m_property_;
			m_option_params_ = source.m_option_params_;
		}

		// Returns a mesh array of T separated by a mesh size h
		template <typename T>
		std::vector<T> Mesher<T>::MeshVector() const
		{
			std::vector<T> _mesh_params;

			for (T i = m_start_; i <= m_end_; i += m_step_)  
				_mesh_params.push_back(i);

			return _mesh_params;  
		}

		// Returns a "matrix" (i.e., vector of vectors) of option parameters
		template <typename T>
		std::vector<std::vector<T> > Mesher<T>::MeshParamMatrix() const
		{
			std::vector<T> _mesh_params;
			_mesh_params = MeshVector();  // Obtain mesh array of T separated by a mesh size h

			std::size_t numberOfRows = _mesh_params.size();  // Get number of rows in the 1xN matrix

			std::vector<std::vector<T> > result(numberOfRows, m_option_params_); // Makes 'result' a numberOfRows x vectorOfDoubles matrix(numberOfRows rows, m_option_params_ columns)

			for (std::size_t n = 0; n < _mesh_params.size(); ++n)
			{
				switch (Property())  // Based on the parameter chosen by the user, the matrix will permutate
				{

				case 0:  // S parameter
					result[n][0] = _mesh_params[n];
					break;
				case 1: // K parameter
					result[n][1] = _mesh_params[n];
					break;
				case 2: // T parameter
					result[n][2] = _mesh_params[n];
					break;
				case 3: // r parameter
					result[n][3] = _mesh_params[n];
					break;
				case 4: // sig parameter
					result[n][4] = _mesh_params[n];
					break;
				case 5: // b parameter
					result[n][5] = _mesh_params[n];
					break;
				}
			}
			return result;
		}

		// Setter member-function for m_start_
		// Modifies object state of data member m_start_
		template <typename T>
		void Mesher<T>::Start(const T& _Start) { m_start_ = _Start; }  


		// Getter member-function for m_start_
		// Returns data member m_start_
		template <typename T>
		T Mesher<T>::Start() const { return m_start_; }

		// Setter member-function for m_end_
		// Modifies object state of data member m_end_
		template <typename T>
		void Mesher<T>::End(const T& _End) { m_end_ = _End; }

		// Getter member-function for m_end_
		// Returns data member m_end_
		template <typename T>
		T Mesher<T>::End() const { return m_end_; }

		// Setter member-function for m_step_
		// Modifies object state of data member m_step_
		template <typename T>
		void Mesher<T>::Step(const T& _Step) { m_step_ = _Step; }

		// Getter member-function for m_step_
		// Returns data member m_step_
		template <typename T>
		T Mesher<T>::Step() const { return m_step_; }

		// Setter member-function for m_property_
		// Modifies object state of data member m_property_
		template <typename T>
		void Mesher<T>::Property(const int& _property) { m_property_ = _property; }

		// Getter member-function for m_property_
		// Returns data member m_property_
		template <typename T>
		int Mesher<T>::Property() const { return m_property_; }

		// Setter member-function for m_option_params_
		// Modifies object state of data member m_option_params_
		template <typename T>
		void Mesher<T>::OptionParamsVector(const std::vector<T>& _option_params) { m_option_params_ = _option_params; }
		
		// Getter member-function for m_option_params_
		// Returns data member m_option_params_
		template <typename T>
		std::vector<T> Mesher<T>::OptionParamsVector() const { return m_option_params_; }
	}
}
#endif // MESH_ARRAY_CPP