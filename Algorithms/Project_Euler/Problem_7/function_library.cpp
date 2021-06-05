// Function library / Function definitions for Project Euler Problem #7

/*

*/


#include "includes.h"


// prime number check function
bool prime_check(const int &num) {
	/*
		- Checks to see if the provided number is a prime number

		Parameters:	[int][num] = The number passed in will be checked to see if it is a prime number
		Return:		[bool]
	*/
	
	int count = 0;

	// loop from 2 to num
	for (int i = 2; i < num; i++) {
		// check to see if num is completely divisible by the current iteration, if it is then that means it is not a prime
		// number. we break and move onto the next iteration.
		if ((num % i) == 0) {
			return false;
			break;
		} else {
			count += 1;
		}
	}

	// return true if count equals num - 2. We do num - 2 since our loop started with 2, and not 0.
	if (count == (num - 2)) {
		return true;
	}
}


// prime number term function
int prime_num_term(const int &limit) {
	/*
		- Increment upwards, if the current number is a prime number, then add it to a counter. Once the counter reaches the
			provided limit, return that number.

		Parameters:	[int][limit] = The upper limit of the loop
		Return:		[int][result]
	*/

	int num = 0;
	int count = 0;

	// loop upwards until count equals the limit provided
	while (count != limit) {
		// increment num by 1
		num += 1;

		// check to see if the current iteration of num is a prime number
		if (prime_check(num)) {
			// if num is a prime number, then increment count
			count += 1;
		}
	}

	// return num
	return num;
}
