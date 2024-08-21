
#include <chrono>
#include <iostream>
#include <math.h>
#include <random>
using namespace std;

int goal = 177;
int numberOfRuns = 10000;
int numberOfRolls = 231;



int main() {	
	// Gets the current system time in milliseconds. This is used as the start time of the program.
	long long startTime = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

	//
	const uint_least32_t seed = startTime;
	mt19937 generator(seed);

	// Creates a distrubution from 0 to 3 (inclusively 0,1,2 or 3 can be generated).
	std::uniform_int_distribution< uint_least32_t > distribute(0, 3);

	int highestCount = 0;		// Stores the highest count of 0's generated.
	int currentRunNumber = 0;	// Stores which run number the program is currently on.

	// Loops until the number of runs or goal has been exceded.
	while (currentRunNumber < numberOfRuns && highestCount < goal){
		// Stores the number if times 0 is generated as our random number.
		int count = 0;

		// loops for the number of rolls.
		for (int rollNumber = 1; rollNumber < numberOfRolls;rollNumber += 1) {
			// Generates a random number from the generator
			int randomNumber = distribute(generator);

			// If the random number generated is 0 then we add one to the count.
			if (randomNumber == 0) {
				count += 1;
			}
		}

		// If the count of this run is higher than the highest count then make it the highest count.
		if (count > highestCount) {
			highestCount = count;
		}
		currentRunNumber += 1;
	}

	// Prints to the user the highest number.
	cout << "highestNumber : " << highestCount << endl;

	// Gets the current system time in milliseconds again. This is used as the finish time of the program.
	long long finishTime = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

	// Calculates how long the program took to run.
	long long runTime = finishTime - startTime;
	// Prints this to the user.
	cout << "Run time :" << runTime << endl;
}