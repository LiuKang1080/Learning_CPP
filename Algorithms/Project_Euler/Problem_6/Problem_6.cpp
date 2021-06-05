// Project Euler Problem #6

/*
The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + 3^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is
3025 - 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/


#include "includes.h"
#include "function_library.h"


int main() {
	// Specific solution to Project Euler Problem number 6:
	const int limit = 100;

	std::cout << "The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is: \n";
	std::cout << difference(limit) << "\n";
	
	return 0;
}
