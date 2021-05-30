// brute_force_method_1 Function Definition

/*
	- Project Euler Problem #5. Brute force method. Start at 2520 and increment upwards (no upper bound) until all numbers
		between 11 and 20 are completely wholy divisible by current iteration number.
	- Once all numbers between 11 and 20 are wholy divisible by current iteration number, return that number and exit the loop.
*/


#include "includes.h"
#include "Method_1.h"


int brute_force_method_1() {
	/*
		- For loop starting at 2520 (the lower_bound) and increment upwards until all numbers from 11 to 20 are wholy divisible by the current
			iteration.

		Parameters:	NONE
		Return:		[int][result]
	*/

	int result;
	std::vector<int> vec;

	for (int lower_bound = 2520; ; ++lower_bound) {
		// manually check all to see if all of the numbers within the range is completely divisible by the current iteration
		if ((lower_bound % 11) == 0 &&
			(lower_bound % 12) == 0 &&
			(lower_bound % 13) == 0 &&
			(lower_bound % 14) == 0 &&
			(lower_bound % 15) == 0 &&
			(lower_bound % 16) == 0 &&
			(lower_bound % 17) == 0 &&
			(lower_bound % 18) == 0 &&
			(lower_bound % 19) == 0 &&
			(lower_bound % 20) == 0
			) {
			vec.push_back(lower_bound);
			break;
		} else {
			++lower_bound;
		}
	}

	result = vec.front();

	return result;
}
