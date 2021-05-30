// brute_force_method_2 Function Definition

/*
	- 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
	- What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/


#include "includes.h"
#include "Method_2.h"


int brute_force_method_2(int limit) {
	/*
		- We only need to test the numbers between 11 and 20, rather than 1 to 20. Numbers between 1 - 10 are in some form
			present from 11 to 20, as in a combination of numbers multiplied from 1 to 10 will result in the numbers from
			11 to 20. ex) 20 = (2^2 * 5), therefore we do not need to test the numbers 2 and 5.
		- Rather than starting from 1 and then incrementing upwards until we find our solution, we can start at 2520 since
			that was the minimum from the previous calculation.

		Parameters:	[int][limit] = the upper limit of the range of numbers we're testing.
		Return:		[int][std::vector<int> result.at(0)] = Return the first element of the vector named result.
	*/

	int lower_bound = 2520;
	std::vector<int> result;

	int lower_limit = limit - 9;
	std::vector<int> vec_range;

	// fill the vector with numbers that defines the range
	for (int i = lower_limit; i <= limit; ++i) {
		vec_range.push_back(i);
	}

	// iterator pointing to the beginning of vec_range
	auto itr = vec_range.begin();

	/*
		- use a while loop, while the loop is empty increment lower_bound and check to see if all of the numbers in vec_range are
			wholly divisible by the current increment of lower_bound.
	*/
	while (result.empty()) {
		while (itr != vec_range.end()) {
			// check to see if lower_bound is completely divisible by itr
			if ((lower_bound % *itr) == 0) {
				++itr;

				// check to see if itr has reached the end of vec_range
				if (itr == vec_range.end()) {
					// if it has reached the end, that means all of the numbers in the vec_range are completely divisible
					// add lower_bound to result
					// break out of all the while loops
					result.push_back(lower_bound);
					break;
					break;
				} else {
					continue;
				}
			}
			
			// reset itr back to the beginning of vec_range
			while (itr != vec_range.begin()) {
				--itr;
			}
			
			// increase lower_bound to the next iteration
			++lower_bound;
		}
	}

	return result.at(0);
}
