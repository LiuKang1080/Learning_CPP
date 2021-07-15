// Project Euler Problem #14

/*
The following iterative sequence is defined for the set of positive integers:

(if n is even)	: n -> n/2
(if n is odd)	: n -> 3n + 1

Using the rule above and starting with 13, we generate the following sequence:
13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet
(Collatz Problem), it is thought that all starting numbers finish at 1. Which starting number, under one million, produces the
longest chain? NOTE: Once the chain starts the terms are allowed to go above one million.
*/


#include "includes.h"
#include "function_library.h"


int main() {
	// Specific solution to Project Euler Problem number 14:
	int upper_limit = 1000000;

	std::cout << "The Upper Limit is: " << upper_limit << "\n";
	std::cout << "The largest number that produces the longest Collatz Sequence within this range is: ";
	std::cout << longest_collatz_chain(upper_limit);

	return 0;
}
