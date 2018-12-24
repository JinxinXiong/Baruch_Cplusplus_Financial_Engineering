// TestRandom.cpp
//
// Objective is to create a program that simulates dice throwing, using functionality in Random library by creating a discrete uniform random number 
// generator whose outcomes are in the closed range [1,6]:
//
// Author: Devon Kaberna
//

#include <boost/random.hpp> // Convenience header file
#include <ctime>			// std::time

#include <map>			// Map containers

#include <iostream>  // C++ style I/O
using namespace std;

int main()
{
	// Throwing dice
	// Mersenne Twister.
	boost::random::mt19937 myRng;

	// Set the seed
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));

	// Uniform in range [1,6]
	boost::random::uniform_int_distribution<int> six(1, 6);

	map<int, long> statistics; // Structure to hold outcome + frequencies
	int outcome = 0; // Current outcome
	long frequency = 0;  // Frequency of a particular outcome

	long number_trials = 0;
	cout << "How many trials? ";  // Prompt for number of trials
	cin >> number_trials;  // Obtain input

	for (int n = 0; n <= number_trials; ++n)  // Now loop through and accumulate results in map container statistics
	{
		outcome = six(myRng);  // Generate outcome via distribution (engine)
		statistics[outcome]++;  // Store result in map container
	}

	cout << endl << endl;
	
	for (int i = 1; i <= 6; ++i)  // Now output results
	{
		cout << "Trial " << i << " has " << (static_cast<double> (statistics[i]) / number_trials) * 100 << "% outcomes" << endl;
	}

	statistics.clear(); // Clear content

	return 0;
}