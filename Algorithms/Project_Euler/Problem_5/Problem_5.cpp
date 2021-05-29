// Project Euler Problem #5

/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/


#include <iostream>
#include <vector>


int brute_force_method_1() {
	// TODO: Finish Function
}

int brute_force_method_2(int limit) {
	/*
		- We only need to test the numbers between 11 and 20, rather than 1 to 20. Numbers between 1 - 10 are in some form
			present from 11 to 20, as in a combination of numbers multiplied from 1 to 10 will result in the numbers from 
			11 to 20. ex) 20 = (2^2 * 5), therefore we do not need to test the numbers 2 and 5.
		- Rather than starting from 1 and then incrementing upwards until we find our solution, we can start at 2520 since
			that was the minimum from the previous calculation.

		Parameters:	[int][limit] = the upper limit of the range of numbers we're testing.
		return:		[int][] = 
	*/

	int lower_bound = 2520;
	std::vector<int> result;

	int lower_limit = limit - 9;
	std::vector<int> vec_range;
	
	// fill the vector with numbers that defines the range
	for (int i = lower_limit; i <= limit; ++i) {
		vec_range.push_back(i);
	}

	/*iterator pointing to the beginning of vec_range
	auto itr = vec_range.begin();*/

	/*
		- use a while loop, while the loop is empty increment lower_bound and check to see if all of the numbers in vec_range are
			wholly divisible by the current increment of lower_bound.	
	*/
	while (result.empty()) {
		for (int i = limit; i >= lower_limit; --i) {
			if ((lower_bound % i) != 0) {
				break;

				/*
					- TODO: Finish function.
				*/
			}
		}
	}

	return result.at(0);
}


int main() {
	// Specific solution to the Project Euler Problem number 5:
	int limit = 20;
	
	std::cout << "The smallest positive number that is evenly divisible by all of the numbers up to 20 is: ";
	std::cout << brute_force_method_2(limit);
	
	return 0;
}
