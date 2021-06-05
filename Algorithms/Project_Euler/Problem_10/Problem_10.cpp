// Project Euler Problem #10

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/


#include "includes.h"
#include "function_library.h"


int main() {
	// Specific Solution to the Project Euler Problem number 10:
	const int limit = 2000000;

	std::cout << "The sum of all the primes below " << limit << " is: ";
	std::cout << prime_sum(limit) << "\n";

	return 0;
}
