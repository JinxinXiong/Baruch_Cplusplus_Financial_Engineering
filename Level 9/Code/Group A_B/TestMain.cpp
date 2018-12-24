// TestMain.cpp
//
// Objective is to test all requirements in groups A and B.
//
// Author: Devon Kaberna


#include "PerpetualAmericanOption.hpp"  // Header file for PerpetualAmericanOption class
#include "OptionData.hpp"  // Header file for struct that contains all option parameters
#include "MeshParamData.hpp"  // Encapsulate option parameters 

#include "OptionFactory.hpp"  // Header file for option factory
using namespace DevonKaberna::Factory;

#include <boost/shared_ptr.hpp> // Boost shared pointer for more effective memory mangement

#include <vector>  // Vector container

#include <iostream>   // C++ style I/O
using namespace std;

// Some generic print function that prints vector
template <typename T>
void print(const vector<T>& vec)
{
	cout << endl;
	for (std::size_t i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << ", ";
	}
	cout << endl;
}

// Print matrix of option parameters
template <typename T>
void print_matrix(vector<vector<T> >& matrix)
{
	vector<vector<T> >::iterator vvi_iterator;
	vector<T>::iterator vi_iterator;
	cout << "S    K    r     T   sig   b  " << endl;

	for (vvi_iterator = matrix.begin(); vvi_iterator != matrix.end(); ++vvi_iterator) 
	{
		for (vi_iterator = (*vvi_iterator).begin(); vi_iterator != (*vvi_iterator).end(); ++vi_iterator)
		{
			cout << *vi_iterator << ", ";
		}
		cout << "\n" << endl;;
	}
}

boost::shared_ptr<DevonKaberna::Instrument::VanillaOption> CreateSharedOptionPtr(boost::shared_ptr<OptionFactory> factory, const OptionData& OD, const double& b)
{
	return factory->CreateOption(OD, b);
}
//
//int main()
//{
//	//Batch 1: 
//	//double T = 0.25; double K = 65; double sig = 0.30; double r = 0.08; double S = 60;
//		//(then C = 2.13337, P = 5.84628).
//	//Batch 2 : 
//	//double T = 1.0; double K = 100; double sig = 0.2; double r = 0.0; double S = 100;
//	//(then C = 7.96557, P = 7.96557)
//	//Batch 3 : 
//	//double T = 1.0; double K = 10; double sig = 0.50; double r = 0.12; double S = 5;
//	//(C = 0.204058, P = 4.07326)
//	//Batch 4 : 
//	//double T = 30.0; double K = 100.0; double sig = 0.30; double r = 0.08; double S = 100.0;
//	// (C = 92.17570, P = 1.24750).
//
//	//Implement the above formulae for gamma for call and put future option pricing 
//	//using the data set : 
//	//double K = 100; double S = 105; double T = 0.5; double r = 0.1; double b = 0; double sig = 0.36;
//	//(exact delta call = 0.5946, delta put = -0.3566)
//
//	cout << "******************************BATCH 1************************************" << endl;
//	OptionData myOptionCallBatch1((OptionParams::assetPrice = 100, OptionParams::strike = 120, OptionParams::expiration = 1.5, OptionParams::interestRate = 0.04,
//		OptionParams::volatility = 0.4, OptionParams::dividend = 0.0,
//		OptionParams::foreignFreeInterestRate = 0.0, OptionParams::optionType = 1, OptionParams::underlyingAssetType = 1));
//
//	OptionData myOptionPutBatch1((OptionParams::assetPrice = 100, OptionParams::strike = 120, OptionParams::expiration = 1.5, OptionParams::interestRate = 0.04,
//		OptionParams::volatility = 0.4, OptionParams::dividend = 0.0,
//		OptionParams::foreignFreeInterestRate = 0.0, OptionParams::optionType = -1, OptionParams::underlyingAssetType = 1));
//
//	EuropeanOption batch_1_call = EuropeanOption(myOptionCallBatch1);
//	EuropeanOption batch_1_put = EuropeanOption(myOptionPutBatch1);
//	cout << "Call Price: " << batch_1_call.Price() << endl;
//	cout << "Call price from put-call parity: " << batch_1_call.PutCallParity(batch_1_put) << endl;
//	cout << "Put Price: " << batch_1_put.Price() << endl;
//	cout << "Put price from put-call parity: " << batch_1_put.PutCallParity(batch_1_call) << endl;
//	cout << "put-call parity test: " << ((batch_1_call.IsPutCallParity(batch_1_put, 0.01)) ? "Put Call Parity satisfied for batch" : "Put Call Parity NOT satisfied") << endl;
//
//	cout << endl << endl;
//	cout << "******************************BATCH 2************************************" << endl;
//
//	OptionData myOptionCallBatch2((OptionParams::assetPrice = 100, OptionParams::strike = 100, OptionParams::expiration = 1.0,
//		OptionParams::interestRate = 0.0,
//		OptionParams::volatility = 0.2, OptionParams::dividend = 0.0,
//		OptionParams::foreignFreeInterestRate = 0.0, OptionParams::optionType = 1, OptionParams::underlyingAssetType = 1));
//
//	OptionData myOptionPutBatch2((OptionParams::assetPrice = 100, OptionParams::strike = 100, OptionParams::expiration = 1.0,
//		OptionParams::interestRate = 0.0,
//		OptionParams::volatility = 0.2, OptionParams::dividend = 0.0,
//		OptionParams::foreignFreeInterestRate = 0.0, OptionParams::optionType = -1, OptionParams::underlyingAssetType = 1));
//
//	EuropeanOption batch_2_call = EuropeanOption(myOptionCallBatch2);
//	EuropeanOption batch_2_put = EuropeanOption(myOptionPutBatch2);
//	cout << "Call Price: " << batch_2_call.Price() << endl;
//	cout << "Call price from put-call parity: " << batch_2_call.PutCallParity(batch_2_put) << endl;
//	cout << "Put Price: " << batch_2_put.Price() << endl;
//	cout << "Put price from put-call parity: " << batch_2_put.PutCallParity(batch_2_call) << endl;
//	cout << "put-call parity test: " << ((batch_2_call.IsPutCallParity(batch_2_put, 0.01)) ? "Put Call Parity satisfied for batch" : "Put Call Parity NOT satisfied") << endl;
//
//	cout << endl << endl;
//	cout << "******************************BATCH 3************************************" << endl;
//
//	OptionData myOptionCallBatch3((OptionParams::assetPrice = 5, OptionParams::strike = 10, OptionParams::expiration = 1.0,
//		OptionParams::interestRate = 0.12,
//		OptionParams::volatility = 0.5, OptionParams::dividend = 0.0,
//		OptionParams::foreignFreeInterestRate = 0.0, OptionParams::optionType = 1, OptionParams::underlyingAssetType = 1));
//
//	OptionData myOptionPutBatch3((OptionParams::assetPrice = 5, OptionParams::strike = 10, OptionParams::expiration = 1.0,
//		OptionParams::interestRate = 0.12,
//		OptionParams::volatility = 0.5, OptionParams::dividend = 0.0,
//		OptionParams::foreignFreeInterestRate = 0.0, OptionParams::optionType = -1, OptionParams::underlyingAssetType = 1));
//
//	EuropeanOption batch_3_call = EuropeanOption(myOptionCallBatch3);
//	EuropeanOption batch_3_put = EuropeanOption(myOptionPutBatch3);
//	cout << "Call Price: " << batch_3_call.Price() << endl;
//	cout << "Call price from put-call parity: " << batch_3_call.PutCallParity(batch_3_put) << endl;
//	cout << "Put Price: " << batch_3_put.Price() << endl;
//	cout << "Put price from put-call parity: " << batch_3_put.PutCallParity(batch_3_call) << endl;
//	cout << "put-call parity test: " << ((batch_3_call.IsPutCallParity(batch_3_put, 0.01)) ? "Put Call Parity satisfied for batch" : "Put Call Parity NOT satisfied") << endl;
//
//	cout << endl << endl;
//	cout << "******************************BATCH 4************************************" << endl;
//
//	OptionData myOptionCallBatch4((OptionParams::assetPrice = 100, OptionParams::strike = 100, OptionParams::expiration = 30.0,
//		OptionParams::interestRate = 0.08,
//		OptionParams::volatility = 0.3, OptionParams::dividend = 0.0,
//		OptionParams::foreignFreeInterestRate = 0.0, OptionParams::optionType = 1, OptionParams::underlyingAssetType = 1));
//
//	OptionData myOptionPutBatch4((OptionParams::assetPrice = 100, OptionParams::strike = 100, OptionParams::expiration = 30.0,
//		OptionParams::interestRate = 0.08,
//		OptionParams::volatility = 0.3, OptionParams::dividend = 0.0,
//		OptionParams::foreignFreeInterestRate = 0.0, OptionParams::optionType = -1, OptionParams::underlyingAssetType = 1));
//
//	EuropeanOption batch_4_call = EuropeanOption(myOptionCallBatch4);
//	EuropeanOption batch_4_put = EuropeanOption(myOptionPutBatch4);
//	cout << "Call Price: " << batch_4_call.Price() << endl;
//	cout << "Call price from put-call parity: " << batch_4_call.PutCallParity(batch_4_put) << endl;
//	cout << "Put Price: " << batch_4_put.Price() << endl;
//	cout << "Put price from put-call parity: " << batch_4_put.PutCallParity(batch_4_call) << endl;
//	cout << "put-call parity test: " << ((batch_4_call.IsPutCallParity(batch_4_put, 0.01)) ? "Put Call Parity satisfied for batch" : "Put Call Parity NOT satisfied") << endl;
//
//	cout << endl << endl;
//
//	cout << "*********************************Now entering A1.C*********************************" << "\n" << endl;
//	/******************************************************************
//	Prompt user to enter interval and step of S
//	******************************************************************/
//
//	OptionData myOptionCallBatch5((OptionParams::assetPrice = 60, OptionParams::strike = 65, OptionParams::expiration = 0.25, OptionParams::interestRate = 0.08,
//		OptionParams::volatility = 0.3, OptionParams::dividend = 0.0,
//		OptionParams::foreignFreeInterestRate = 0.0, OptionParams::optionType = 1, OptionParams::underlyingAssetType = 1));
//
//	OptionData myOptionPutBatch5((OptionParams::assetPrice = 60, OptionParams::strike = 65.0, OptionParams::expiration = 0.25, OptionParams::interestRate = 0.08,
//		OptionParams::volatility = 0.3, OptionParams::dividend = 0.0,
//		OptionParams::foreignFreeInterestRate = 0.0, OptionParams::optionType = -1, OptionParams::underlyingAssetType = 1));
//
//	EuropeanOption batch_5_call = EuropeanOption(myOptionCallBatch5);
//	EuropeanOption batch_5_put = EuropeanOption(myOptionPutBatch5);
//	cout << "Call Price: " << batch_5_call.Price() << endl;
//	cout << "Put Price: " << batch_5_put.Price() << endl;
//
//	int _property = 0;
//
//	double _start = 0, _stop, _step = 0;
//	cout << "Choose parameter to adjust (0=S) ";
//	cin >> _property;
//	cout << "\n " << "Enter start: ";
//	cin >> _start;
//	cout << "\n " << "Enter stop: ";
//	cin >> _stop;
//	cout << "\n " << "Enter step: ";
//	cin >> _step;
//
//	// Sensitivity type assumed to be for price, but it could be for anything else.  Didn't have time to do that.
//	MeshParamData myMeshParamData1((MeshParams::sensitivityType = 0, MeshParams::property = _property, MeshParams::start = _start, MeshParams::end = _stop,
//		MeshParams::step = _step));
//
//	cout << endl << "Mesh input for call" << endl;
//	print(batch_5_call.MeshOptionParamVector(myMeshParamData1));
//
//	cout << endl << endl << "Call Prices are as follows: \n";
//	vector<double> optionVector = batch_5_call.MeshPriceVector(myMeshParamData1);
//	for (auto i : optionVector) cout << i << " ";
//
//	cout << endl << endl << "Mesh input for put" << endl;
//	print(batch_5_put.MeshOptionParamVector(myMeshParamData1));
//
//	cout << endl << "Put Prices are as follows: \n";
//	optionVector = batch_5_put.MeshPriceVector(myMeshParamData1);
//	for (auto i : optionVector) cout << i << " ";
//
//	cout << endl << endl << "*********************************Now entering A1.D*********************************" << "\n" << endl;
//
//	// Matrix functionality here
//	cout << "Choose parameter to adjust (0=S, 1=K, 2=r, 3=T, 4=sig, 5=b) ";
//	cin >> _property;
//	cout << "\n " << "Enter start: ";
//	cin >> _start;
//	cout << "\n " << "Enter stop: ";
//	cin >> _stop;
//	cout << "\n " << "Enter step: ";
//	cin >> _step;
//
//	MeshParamData myMeshParamData2((MeshParams::sensitivityType = 0, MeshParams::property = _property, MeshParams::start = _start, MeshParams::end = _stop,
//		MeshParams::step = _step));
//	//Override sensitivityType = 0 - assumed to be for S in this section, but it could be for anything else (i.e., delta, gamma, etc.)
//
//	cout << endl << endl << "*****Now printing matrix of parameters from mesher prior to pricing*********************************" << "\n" << endl << endl;
//	vector<vector<double> > m_opt_param_matrix = batch_5_call.MeshOptionParamMatrix(myMeshParamData2);
//	print_matrix(m_opt_param_matrix);  //first print matrix of vectors that are fed into the pricing engine via mesher
//
//	vector<double> matrix = batch_5_call.MeshPriceMatrix(myMeshParamData2);
//	cout << endl << endl << "Now printing vector of call prices" << endl;
//	print(matrix);
//
//	//cout << endl << endl << "*****Now printing matrix of put parameters from mesher prior to pricing*********************************" << "\n" << endl << endl;
//	//m_opt_param_matrix = batch_5_put.MeshOptionParamMatrix(myMeshParamData2);
//	//print_matrix(m_opt_param_matrix);  //first print matrix of vectors that are fed into the pricing engine via mesher
//
//	matrix = batch_5_put.MeshPriceMatrix(myMeshParamData2);
//	cout << endl << endl << "Now printing vector of put prices" << endl;
//	print(matrix);
//
//	cout << endl << endl;
//
//	cout << "******************************Option Sensitivites Section************************************" << endl;
//
//	//OptionParams::underlyingAssetType = 3 for futures
//
//	OptionData myOptionSensitivityCall1((OptionParams::assetPrice = 105, OptionParams::strike = 100, OptionParams::expiration = 0.5,
//		OptionParams::interestRate = 0.1,
//		OptionParams::volatility = 0.36, OptionParams::dividend = 0.0,
//		OptionParams::foreignFreeInterestRate = 0.0, OptionParams::optionType = 1, OptionParams::underlyingAssetType = 3)); // future option pricing
//
//	OptionData myOptionSensitivityPut1((OptionParams::assetPrice = 100, OptionParams::strike = 120, OptionParams::expiration = 1.5, OptionParams::interestRate = 0.04,
//		OptionParams::volatility = 0.4, OptionParams::dividend = 0.0,
//		OptionParams::foreignFreeInterestRate = 0.0, OptionParams::optionType = -1, OptionParams::underlyingAssetType = 1));
//
//
//	EuropeanOption option_sensitivity_batch_1_call = EuropeanOption(myOptionSensitivityCall1);
//	EuropeanOption option_sensitivity_batch_1_put = EuropeanOption(myOptionSensitivityPut1);
//	cout << "Call Delta: " << option_sensitivity_batch_1_call.Delta() << "  ";
//	cout << "Put Delta: " << option_sensitivity_batch_1_put.Delta() << endl;
//	cout << "Gamma: " << option_sensitivity_batch_1_call.Gamma() << "  ";
//
//	cout << endl << endl;
//	cout << "******************************A2.b************************************" << endl;
//	cout << endl << endl;
//
//	cout << "Choose parameter to adjust (0=S) ";
//	cin >> _property;
//	cout << "Enter start: ";
//	cin >> _start;
//	cout << "Enter stop: ";
//	cin >> _stop;
//	cout << "Enter step: ";
//	cin >> _step;
//
//	cout << endl << endl;
//
//	MeshParamData myMeshParamData3((MeshParams::sensitivityType = 1, MeshParams::property = _property, MeshParams::start = _start, MeshParams::end = _stop,
//		MeshParams::step = _step));
//
//	//_sensitivity_type = 1; // assumed to be for delta in this section, but it could be for anything else (i.e., gamma, etc.)
//
//	cout << endl << "Mesh input: " << endl;
//	print(option_sensitivity_batch_1_call.MeshOptionParamVector(myMeshParamData3));
//
//	cout << endl << endl << "Delta Call: \n";
//	optionVector = option_sensitivity_batch_1_call.MeshDeltaVector(myMeshParamData3);  //return just a vector
//	for (auto i : optionVector) cout << i << " ";
//
//	cout << endl << endl << "Delta Put : \n";
//	optionVector = option_sensitivity_batch_1_put.MeshDeltaVector(myMeshParamData3);  //return just a vector
//	for (auto i : optionVector) cout << i << " ";
//
//	cout << endl << endl;
//	cout << "******************************A2.C************************************" << endl;
//	cout << endl << endl;
//
//	cout << "Choose parameter to adjust (0=S, 1=K, 2=r, 3=T, 4=sig, 5=b) ";
//	cin >> _property;
//	cout << "Enter start: ";
//	cin >> _start;
//	cout << "Enter stop: ";
//	cin >> _stop;
//	cout << "Enter step: ";
//	cin >> _step;
//
//	cout << endl << endl;
//
//	MeshParamData myMeshParamData4((MeshParams::sensitivityType = 1, MeshParams::property = _property, MeshParams::start = _start, MeshParams::end = _stop,
//		MeshParams::step = _step));
//
//	//cout << endl << endl << "Call Prices are as follows: \n";
//	//optionVector = option_sensitivity_batch_1_call.MeshPriceMatrix(myMeshParamData4);  // now return a matrix
//	//for (auto i : optionVector) cout << i << " ";
//
//	//cout << endl << endl << "Put Prices are as follows: \n";
//	//optionVector = option_sensitivity_batch_1_put.MeshPriceMatrix(myMeshParamData4);
//	//for (auto i : optionVector) cout << i << " ";
//	cout << endl << endl << "*****Now printing matrix of parameters from mesher prior to pricing*********************************" << "\n" << endl << endl;
//	m_opt_param_matrix = option_sensitivity_batch_1_call.MeshOptionParamMatrix(myMeshParamData4);
//	print_matrix(m_opt_param_matrix);  //first print matrix of vectors that are fed into the pricing engine via mesher
//
//	cout << endl << endl << "Delta Call: \n";
//	optionVector = option_sensitivity_batch_1_call.MeshDeltaMatrix(myMeshParamData4);
//	for (auto i : optionVector) cout << i << " ";
//
//	cout << endl << endl << "Delta Put: \n";
//	optionVector = option_sensitivity_batch_1_put.MeshDeltaMatrix(myMeshParamData4);
//	for (auto i : optionVector) cout << i << " ";
//
//	cout << endl << "Gamma: \n";
//	optionVector = option_sensitivity_batch_1_put.MeshGammaMatrix(myMeshParamData4);
//	for (auto i : optionVector) cout << i << " ";
//
//	cout << endl << endl;
//	cout << "******************************A2.d - Divided Differences********************************" << endl;
//	cout << endl << endl << endl;
//	cout << "*************************HOLDING S CONSTANT, WITH VARYING LEVELS OF H BETWEEN [0,1]******************" << endl;
//	cout << endl;
//
//	cout << "Enter step: ";
//	cin >> _step;
//
//	cout << endl;
//
//	MeshParamData myMeshParamData5((MeshParams::sensitivityType = 1, MeshParams::property = 0, MeshParams::start = _start, MeshParams::end = _start,
//		MeshParams::step = _step));
//
//	cout << "Call Delta: " << option_sensitivity_batch_1_call.Delta() << "  ";
//	cout << "Put Delta: " << option_sensitivity_batch_1_put.Delta() << endl;
//	cout << "Gamma: " << option_sensitivity_batch_1_call.Gamma() << "  ";
//
//	//print(option_sensitivity_batch_1_call.MeshOptionParamVector(myMeshParamData5));
//
//	for (double i = 0; i <= 1.0; i += _step)
//	{
//		cout << endl << endl << "Parameter S: " << myMeshParamData5._start << " with H value of:  " << i;
//
//		cout << endl << "Delta Call: ";
//		cout << option_sensitivity_batch_1_call.Delta();
//
//		cout << endl << "Delta Call Approx: ";
//		cout << option_sensitivity_batch_1_call.DeltaApprox(i);
//
//		cout << endl << "Delta Put: ";
//		cout << option_sensitivity_batch_1_put.Delta();
//
//		cout << endl << "Delta Put Approx: ";
//		cout << option_sensitivity_batch_1_put.DeltaApprox(i);
//
//		cout << endl << "Gamma: ";
//		cout << option_sensitivity_batch_1_call.Gamma();
//
//		cout << endl << "Gamma Call Approx: ";
//		cout << option_sensitivity_batch_1_call.GammaApprox(i);
//
//		cout << endl << "Gamma Put Approx: ";
//		cout << option_sensitivity_batch_1_put.GammaApprox(i);
//
//	}
//
//	cout << endl << endl;
//
//	cout << endl << endl;
//	cout << "******************************Perpetual American Options************************************" << endl;
//
//	OptionData myOptionPerpetualCall1((OptionParams::assetPrice = 110, OptionParams::strike = 100, OptionParams::expiration = 0.5,
//		OptionParams::interestRate = 0.1,
//		OptionParams::volatility = 0.1, OptionParams::dividend = 0.0,
//		OptionParams::foreignFreeInterestRate = 0.0, OptionParams::optionType = 1, OptionParams::underlyingAssetType = 1));
//
//	OptionData myOptionPerpetualPut1((OptionParams::assetPrice = 110, OptionParams::strike = 100, OptionParams::expiration = 0.5,
//		OptionParams::interestRate = 0.1,
//		OptionParams::volatility = 0.1, OptionParams::dividend = 0.0,
//		OptionParams::foreignFreeInterestRate = 0.0, OptionParams::optionType = -1, OptionParams::underlyingAssetType = 1));
//
//
//	PerpetualAmericanOption option_perpetual_batch_1_call = PerpetualAmericanOption(myOptionPerpetualCall1, 0.02);
//	PerpetualAmericanOption option_perpetual_batch_1_put = PerpetualAmericanOption(myOptionPerpetualPut1, 0.02);
//
//	cout << "Call Price: " << option_perpetual_batch_1_call.Price() << endl;
//	cout << "Put Price: " << option_perpetual_batch_1_put.Price() << endl;
//
//	cout << endl << endl;
//	cout << "*********************************Now entering B1.C*********************************" << "\n" << endl;
//	/******************************************************************
//	Prompt user to enter interval and step of S
//	******************************************************************/
//
//	cout << "Choose parameter to adjust (0=S) ";
//	cin >> _property;
//	cout << "\n " << "Enter start: ";
//	cin >> _start;
//	cout << "\n " << "Enter stop: ";
//	cin >> _stop;
//	cout << "\n " << "Enter step: ";
//	cin >> _step;
//
//	// Sensitivity type assumed to be for price, but it could be for anything else.  Didn't have time to do that.
//	MeshParamData myMeshParamData6((MeshParams::sensitivityType = 0, MeshParams::property = _property, MeshParams::start = _start, MeshParams::end = _stop,
//		MeshParams::step = _step));
//
//	cout << endl << "Mesh input for call" << endl;
//	print(option_perpetual_batch_1_call.MeshOptionParamVector(myMeshParamData6));
//
//	cout << endl << endl << "Call Prices are as follows: \n";
//	optionVector = option_perpetual_batch_1_call.MeshPriceVector(myMeshParamData6);
//	for (auto i : optionVector) cout << i << " ";
//
//	cout << endl << endl << "Mesh input for put" << endl;
//	print(option_perpetual_batch_1_put.MeshOptionParamVector(myMeshParamData6));
//
//	cout << endl << "Put Prices are as follows: \n";
//	optionVector = option_perpetual_batch_1_put.MeshPriceVector(myMeshParamData6);
//	for (auto i : optionVector) cout << i << " ";
//
//	cout << endl << endl << "*******************************Now entering B1.D*******************************" << "\n" << endl;
//
//	// Matrix functionality here
//	cout << "Choose parameter to adjust (0=S, 1=K, 2=r, 3=T, 4=sig, 5=b) ";
//	cin >> _property;
//	cout << "\n " << "Enter start: ";
//	cin >> _start;
//	cout << "\n " << "Enter stop: ";
//	cin >> _stop;
//	cout << "\n " << "Enter step: ";
//	cin >> _step;
//
//	MeshParamData myMeshParamData7((MeshParams::sensitivityType = 0, MeshParams::property = _property, MeshParams::start = _start, MeshParams::end = _stop,
//		MeshParams::step = _step));
//	//Override sensitivityType = 0 - assumed to be for S in this section, but it could be for anything else (i.e., delta, gamma, etc.)
//
//	cout << endl << endl << "*****Now printing matrix of parameters from mesher prior to pricing*********************************" << "\n" << endl << endl;
//	m_opt_param_matrix = option_perpetual_batch_1_call.MeshOptionParamMatrix(myMeshParamData7);
//	print_matrix(m_opt_param_matrix);  //first print matrix of vectors that are fed into the pricing engine via mesher
//
//	matrix = option_perpetual_batch_1_call.MeshPriceMatrix(myMeshParamData7);
//	cout << endl << endl << "Now printing vector of call prices" << endl;
//	print(matrix);
//
//	cout << endl << endl << "*****Now printing matrix of put parameters from mesher prior to pricing*********************************" << "\n" << endl << endl;
//	m_opt_param_matrix = option_perpetual_batch_1_put.MeshOptionParamMatrix(myMeshParamData7);
//	print_matrix(m_opt_param_matrix);  //first print matrix of vectors that are fed into the pricing engine via mesher
//
//	matrix = option_perpetual_batch_1_put.MeshPriceMatrix(myMeshParamData7);
//	cout << endl << endl << "Now printing vector of put prices" << endl;
//	print(matrix);
//
//
//	cout << endl << endl << "***************************NOW CREATE YOUR OWN OPTION********************************" << "\n" << endl << endl;
//	// Now let's prompt user and let him/her choose whatever option and option parameters
//	int _OptionType, _OptionModel = 0;
//	double _T, _K , _sig , _r , _S, _R, _q, _b = 0.0;
//
//	cout << "Choose option you wish to create (0=European, 1=American Perpetual) ";
//	cin >> _OptionType;
//	cout << "Enter type of model (1=black scholes, 2=morton model, 3=black scholes futures option model, 4=garman and kohlhagen currency option model): ";
//	cin >> _OptionModel;
//	cout << "Enter S: ";
//	cin >> _S;
//	cout << "Enter K: ";
//	cin >> _K;
//	cout << "Enter T (not applicable to perperpetual american options): ";
//	cin >> _T;
//	cout << "Enter sig: ";
//	cin >> _sig;
//	cout << "Enter r: ";
//	cin >> _r;
//	cout << "Enter foreign risk-free rate (if applicable): ";
//	cin >> _R;
//	cout << "Enter continuous dividend yield (if applicable): ";
//	cin >> _q;
//	cout << "Enter override for b (if applicable): ";
//	cin >> _b;
//
//	OptionData myOptionFactoryParams((OptionParams::assetPrice = _S, OptionParams::strike = _K, OptionParams::expiration = _T,
//		OptionParams::interestRate = _r,
//		OptionParams::volatility = _sig, OptionParams::dividend = _q,
//		OptionParams::foreignFreeInterestRate = _R, OptionParams::optionType = 1, OptionParams::underlyingAssetType = _OptionModel));
//
//	boost::shared_ptr<VanillaOption> myOptionCall, myOptionPut;
//	switch (_OptionType) 
//	{
//	case 0:  // vanilla european option
//		myOptionCall = CreateSharedOptionPtr(boost::shared_ptr<OptionFactory>(new EuropeanOptionFactory()), myOptionFactoryParams, _b);
//		myOptionFactoryParams.type *= -1;  // Switch to other option type (i.e., call/put)
//		myOptionPut = CreateSharedOptionPtr(boost::shared_ptr<OptionFactory>(new EuropeanOptionFactory()), myOptionFactoryParams, _b);
//		break;
//	case 1: // Perpetual american option
//		myOptionCall = CreateSharedOptionPtr(boost::shared_ptr<OptionFactory>(new PerpetualAmericanOptionFactory()), myOptionFactoryParams, _b);
//		myOptionFactoryParams.type *= -1;  // Switch to other option type (i.e., call/put)
//		myOptionPut = CreateSharedOptionPtr(boost::shared_ptr<OptionFactory>(new PerpetualAmericanOptionFactory()), myOptionFactoryParams, _b);
//		break;
//	default: // just create european vanilla option
//		myOptionCall = CreateSharedOptionPtr(boost::shared_ptr<OptionFactory>(new EuropeanOptionFactory()), myOptionFactoryParams, _b);
//		myOptionFactoryParams.type *= -1;  // Switch to other option type (i.e., call/put)
//		myOptionPut = CreateSharedOptionPtr(boost::shared_ptr<OptionFactory>(new EuropeanOptionFactory()), myOptionFactoryParams, _b);
//	}
//
//	// Now let's print the prices and greeks
//	cout << endl << endl << "*****Now printing call/put prices along with greeks*********************************" << "\n" << endl << endl;
//	cout << endl << endl;
//	
//	cout << "Call Price: " << myOptionCall->Price() << endl;
//	
//	cout << "Put Price: " << myOptionPut->Price() << endl;
//	
//	cout << endl << "Delta Call (Note: -1 returned for Perpetual American Option): ";
//	cout << myOptionCall->Delta();
//
//	cout << endl << "Delta Put (Note: -1 returned for Perpetual American Option): ";
//	cout << myOptionPut->Delta();
//
//	cout << endl << "Gamma (Note: -1 returned for Perpetual American Option): ";
//	cout << myOptionCall->Gamma();
//
//	cout << endl << endl; 
//
//	return 0;
//}

int main()
{


	cout << endl << endl << "***************************NOW CREATE YOUR OWN OPTION********************************" << "\n" << endl << endl;
	// Now let's prompt user and let him/her choose whatever option and option parameters
	int _OptionType, _OptionModel = 0;
	double _T, _K, _sig, _r, _S, _R, _q, _b = 0.0;

	cout << "Choose option you wish to create (0=European, 1=American Perpetual) ";
	cin >> _OptionType;
	cout << "Enter type of model (1=black scholes, 2=morton model, 3=black scholes futures option model, 4=garman and kohlhagen currency option model): ";
	cin >> _OptionModel;
	cout << "Enter S: ";
	cin >> _S;
	cout << "Enter K: ";
	cin >> _K;
	cout << "Enter T (not applicable to perperpetual american options): ";
	cin >> _T;
	cout << "Enter sig: ";
	cin >> _sig;
	cout << "Enter r: ";
	cin >> _r;
	cout << "Enter foreign risk-free rate (if applicable): ";
	cin >> _R;
	cout << "Enter continuous dividend yield (if applicable): ";
	cin >> _q;
	cout << "Enter override for b (if applicable): ";
	cin >> _b;

	OptionData myOptionFactoryParams((OptionParams::assetPrice = _S, OptionParams::strike = _K, OptionParams::expiration = _T,
		OptionParams::interestRate = _r,
		OptionParams::volatility = _sig, OptionParams::dividend = _q,
		OptionParams::foreignFreeInterestRate = _R, OptionParams::optionType = 1, OptionParams::underlyingAssetType = _OptionModel));

	boost::shared_ptr<VanillaOption> myOptionCall, myOptionPut;
	switch (_OptionType)
	{
	case 0:  // vanilla european option
		myOptionCall = CreateSharedOptionPtr(boost::shared_ptr<OptionFactory>(new EuropeanOptionFactory()), myOptionFactoryParams, _b);
		myOptionFactoryParams.type *= -1;  // Switch to other option type (i.e., call/put)
		myOptionPut = CreateSharedOptionPtr(boost::shared_ptr<OptionFactory>(new EuropeanOptionFactory()), myOptionFactoryParams, _b);
		break;
	case 1: // Perpetual american option
		myOptionCall = CreateSharedOptionPtr(boost::shared_ptr<OptionFactory>(new PerpetualAmericanOptionFactory()), myOptionFactoryParams, _b);
		myOptionFactoryParams.type *= -1;  // Switch to other option type (i.e., call/put)
		myOptionPut = CreateSharedOptionPtr(boost::shared_ptr<OptionFactory>(new PerpetualAmericanOptionFactory()), myOptionFactoryParams, _b);
		break;
	default: // just create european vanilla option
		myOptionCall = CreateSharedOptionPtr(boost::shared_ptr<OptionFactory>(new EuropeanOptionFactory()), myOptionFactoryParams, _b);
		myOptionFactoryParams.type *= -1;  // Switch to other option type (i.e., call/put)
		myOptionPut = CreateSharedOptionPtr(boost::shared_ptr<OptionFactory>(new EuropeanOptionFactory()), myOptionFactoryParams, _b);
	}

	// Now let's print the prices and greeks
	cout << endl << endl << "*****Now printing call/put prices along with greeks*********************************" << "\n" << endl << endl;
	cout << endl << endl;

	cout << "Call Price: " << myOptionCall->Price() << endl;

	cout << "Put Price: " << myOptionPut->Price() << endl;

	cout << endl << "Delta Call (Note: -1 returned for Perpetual American Option): ";
	cout << myOptionCall->Delta();

	cout << endl << "Delta Put (Note: -1 returned for Perpetual American Option): ";
	cout << myOptionPut->Delta();

	cout << endl << "Gamma (Note: -1 returned for Perpetual American Option): ";
	cout << myOptionCall->Gamma();

	cout << endl << endl;

	return 0;
}