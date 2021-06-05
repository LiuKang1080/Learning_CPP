// Function Libarary / Function Definitions

/*

*/


#include "includes.h"
#include "function_library.h"


// brute force method
int brute_force_method() {
	/*
		- Brute force method.
		- Calculate the special pythagorean triplet.

		Parameters: NONE
		Return:		[int][result]
	*/

	int result = 0;
	std::vector<int> vec {};

	// use a triple for loop to loop through all of the numbers between 1 and 1000 to find the special pythagorean triplet
	for (int a = 1; a < 1000; ++a) {
		for (int b = 1; b < 1000; ++b) {
			for (int c = 1; c < 1000; ++c) {
				if ((a + b + c == 1000) && ((a*a) + (b*b) == (c*c)) && (a < b < c)) {
					vec.push_back(a * b * c);
				}
			}
		}

		// if vec is not empty, that means the pythagorean triplet has been found, break out of the loop
		if (!vec.empty()) {
			break;
		}
	}

	result = vec.at(0);

	return result;
}

// pythagorean triplet
int pythagorean_triplet() {
	/*
		- calculate c^2 at the outter most loop, this prevents the calculation of c^2 in the inner loops. 
		- Remove the checks for a + b + c = 1000 in the inner loop, do it once in the outer loop.
		- We can remove the checks for a < b < c by ensuring the loop ranges:
			- the outer loop will have c start at 3, and go to 1000. The inner loop will have b start at 2 and go until c-1.
				This will ensure that b will always start below c, and will always be below c. Now in the inner loop we will
				have a move downward from 1000, by subtracting c and b from 1000. a = 1000 - b - c 
	*/

	int result = 0;
	std::vector<int> vec {};
	int c_squared = 0;
	int c = 0;
	int b = 0;
	int a = 0;

	for (c = 3; c < 1000; ++c) {
		// calculate c^2 here instead of the inner loop
		c_squared = c * c;
		
		for (b = 2; b < (c - 1); ++b) {
			a = 1000 - b - c;

			if (((a*a) + (b*b)) == c_squared) {
				vec.push_back(a * b * c);
			}
		}
	}

	// check to see if the vector has an element
	if (!vec.empty()) {
		result = vec.at(0);
		return result;
	} else {
		return 0;
	}
}
