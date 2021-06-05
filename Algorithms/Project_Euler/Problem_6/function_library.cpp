// Function Library / Function definition for Project Euler Problem #6


#include "includes.h"


int difference(const int &limit) {
	/*
		- Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
		- Create 2 vectors, 1) sum_of_squares, and 2) square_of_sum
		- Use a for loop, in the for loop add the squares to sum_of_squares, and add num to square_of_num of all of the numbers
			between 1 to the limit.
		- Use the std::pow() function to square the integers. Use the std::accumulate to find the total sum
		- Return the difference between the sum of the squares and the square of the sum.

		Parameters: [int][limit] = The upper limit of the range
		Return:		[int][result]
	*/

	// initialize variables
	std::vector<int> sum_of_squares;
	std::vector<int> square_of_sums;
	int total_sum_of_squares = 0;
	int total_square_of_sums = 0;
	int result = 0;

	// use a for loop to fill both of the vectors
	for (int i = 1; i <= limit; ++i) {
		// square the current iteration and add it into sum_of_squares
		// std::pow(base, power) raise base to the power provided
		sum_of_squares.push_back(std::pow(i, 2));

		// insert the current iteration int into square_of_sum
		square_of_sums.push_back(i);
	}

	// perform the total sum of all of the squares using std::accumulate(). We've already raised everything in this vector to the
	// second power, we only need to perform the accumulation.
	total_sum_of_squares = std::accumulate(sum_of_squares.begin(), sum_of_squares.end(), 0);

	// perform the square of sums. First use std::accumulate() through the entire vector, and then raise it to the second power
	total_square_of_sums = std::pow(std::accumulate(square_of_sums.begin(), square_of_sums.end(), 0), 2);

	// perform the difference between the square of the sum and the sum of the squares
	// generally the square of the sum will be greater than the sum of the squares. Check to see if that's the case so we don't
	// get negative results

	if (total_square_of_sums > total_sum_of_squares) {
		result = total_square_of_sums - total_sum_of_squares;
	}

	return result;
}
