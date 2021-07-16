// Function Library / Function Definitions

/*
Given a number, the Collatz Sequence always ends at a 1.
	- If the number is even	: n -> n/2
	- If the number is odd	: n -> 3n + 1

Ex) Starting with 13: 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
*/


#include "includes.h"
#include "function_library.h"


// collatz sequence generator
std::vector<unsigned long long int> collatz_sequence_generator(unsigned long long int num) {
	/*
		Parameters:	[unsigned long long int][num] - The starting point of the Collatz Sequence.
		Return:		[std::vector<int>][collatz_sequence] - The full vector that contains the Collatz Sequence.

		- If the number is even : n -> n/2
		- If the number is odd	: n -> 3n + 1

		We already have working code that produces the Collatz Sequence from Project_Euler/Problem_14
	*/

	// create varaibles:
	std::vector<unsigned long long int> collatz_sequence {};

	// add the first number into the sequence
	collatz_sequence.push_back(num);

	// use a while loop to create the Collatz Sequence:
	while (num > 1) {
		// check to see if current_num is even or not:
		if (num % 2 == 0) {
			num = num / 2;
			collatz_sequence.push_back(num);
		} else {
			num = (3 * num) + 1;
			collatz_sequence.push_back(num);
		}
	}

	return collatz_sequence;
}


// get the size of the vector that has the collatz sequence for that specific number
template <typename T>
std::vector<int> range_vector(const std::vector<T> &collatz_sequence) {
	/*
		Parameters:	[std::vector<int>][&collatz_sequence] - The full vector that contains the whole Collatz Sequence.
		Return:		[std::vector<int>][range_vector] - A vector containing the range from 1 to the size of collatz_sequence.

		This is a helper function. We will use this function to get the x axis, when we plot the Collatz Sequence.
	*/
	
	// initialize variables
	int sequence_size = collatz_sequence.size();
	std::vector<int> range_vector {};
	
	//use a for loop to generate the range vector
	for (int i = 1; i <= sequence_size; i++) {
		range_vector.push_back(i);
	}

	return range_vector;
}


// convert elements from a vector to a valarray
template <typename T>
std::valarray<double> convert_vector_valarray(const std::vector<T> &vec) {
	/*
		Parameters:	[const std::vector<int>][&vec] - Vector. Pass by reference
		Return:		[std::valarray<double>][] - Valarray 
	
		Use the std::copy in the <algorithm> header file
	*/

	// initialize varaibles
	std::valarray<double> val_array(vec.size());

	// use std::copy to copy the elements from the vector into the valarray
	std::copy(begin(vec), end(vec), begin(val_array));

	return val_array;
}


// plot the Collatz Sequence
void plot_sequence(const std::vector<unsigned long long int> &collatz_sequence, int collatz_number) {
	/*
		Parameters:	
			[const std::vector<int>][&collatz_sequence] - This is the full Collatz Sequence.
			[int][collatz_number] - This is the starting number.
		
		Return: [void]
	*/

	using namespace sciplot;

	// initialize variables
	std::string string_collatz = std::to_string(collatz_number);

	// create the x and y axis:
	Vec x = convert_vector_valarray(range_vector(collatz_sequence));
	Vec y = convert_vector_valarray(collatz_sequence);

	// create the plot object:
	Plot plot;
	plot.palette("rdgy");

	// We will use drawCurveWithPoints, this takes in the x and y vectors.
	// place labels:
	plot.xlabel("Range");
	plot.ylabel("Collatz Numbers");

	plot.drawCurve(x, y).label("Collatz Sequence #" + string_collatz);
	
	// save the plot in .PDF format
	plot.save("Collatz_Sequence_" + string_collatz + ".pdf");
}
