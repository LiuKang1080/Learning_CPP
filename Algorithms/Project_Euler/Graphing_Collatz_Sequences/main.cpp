// From Project Euler Problem #14 - Graphing the Collatz Sequence

/*
The Collatz Sequence: 
The following iterative sequence is defined for the set of positive integers:

(if n is even)	: n -> n/2
(if n is odd)	: n -> 3n + 1

Using the rule above and starting with 13, we generate the following sequence:
13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet
(Collatz Problem), it is thought that all starting numbers finish at 1. Given a starting number, we will graph the Collatz
Sequence for that number.
*/


#include "includes.h"
#include "function_library.h"


int main() {
	// Collatz Sequence of 13:
	int collatz_number = 13;
	plot_sequence(collatz_sequence_generator(collatz_number), collatz_number);

	return 0;
}
