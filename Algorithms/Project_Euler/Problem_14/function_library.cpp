// Function Library / Function Definitions

/*
Given a number, the Collatz Sequence always ends at a 1.
	- If the number is even	: n -> n/2
	- If the number is odd	: n -> 3n + 1

Ex) Starting with 13: 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
	We can see that this sequence contains 10 terms

Which starting number under one million, produces the longest chain?
NOTE: Once the chain starts the terms are allowed to go above one million.
*/


#include "includes.h"
#include "function_library.h"


int longest_collatz_chain(const int &upper_limit) {
	/*
		Parameters:	[int][upper_limit] = The upper limit. For Project Euler Problem #14 the upper_limit is 1 million.
					[int][range] = The range of numbers starting from the upper_limit, and moving downwards.
		Return:		[int][largest_number] = This will return the number that produces the longest collatz chain.
	
		- Start at the limit and decrement, rather than starting at 1 and incrementing upwards.
		- We set the range to 100 first, and see the average size of the collatz sequence, if the sequence is increasing as we
			decrement, then we will increase the range.
		- Return the number that produces the longest collatz sequence.
		- If the number is even : n -> n/2
		- If the number is odd	: n -> 3n + 1
	*/

	// create varaibles:
	int current_num = upper_limit;
	// test the upper 25% range of numbers
	int lower_limit = upper_limit - (upper_limit / 4);
	std::vector<int> collatz_sequence{};
	
	int largest_number = 0;
	int sequence_size = 0;

	// use a for loop to decrement from the upper_limit to the lower_limit
	for (current_num; current_num >= lower_limit; --current_num) {
		// clear the vector for the current iteration of the collatz sequence
		collatz_sequence.clear();
		// set the current_num as the temp varialbe so we can set the size after the while loop
		long long int temp =  current_num;

		// add the first number in the sequence
		collatz_sequence.push_back(temp);

		// use a while loop to generate the collatz sequence:
		while (temp > 1) {
			// check to see if current_num is even or not:
			if (temp %2 == 0) {
				temp = temp / 2;
				collatz_sequence.push_back(temp);
			} else {
				temp = (3 * temp) + 1;
				collatz_sequence.push_back(temp);
			}
		}

		// check to see if the size of the sequence is larger than the current sequence size, if it is then update the current size to
		// the new size. We will also update the value of largest number, since this number produced the longest sequence chain.
		if (collatz_sequence.size() > sequence_size) {
			sequence_size = collatz_sequence.size();
			largest_number = current_num;
		}
	}

	// return the number that produces the largest collatz sequence. Return largest_number.
	return largest_number;
}


// Algorithm that creates the Collatz Sequence given a starting number 
std::vector<int> collatz_sequence_generator(unsigned long long int num) {
	/*
		Parameters:	[int][num] - The starting point of the Collatz Sequence.
		Return:		[std::vector<int>][collatz_sequence] - The full vector that contains the Collatz Sequence.

		- If the number is even : n -> n/2
		- If the number is odd	: n -> 3n + 1
	*/

	// create varaibles:
	std::vector<int> collatz_sequence {};

	// add the first number into the sequence
	collatz_sequence.push_back(num);

	// use a while loop to create the Collatz Sequence:
	while (num > 1) {
		// check to see if current_num is even or not:
		if (num % 2 == 0) {
			num = num / 2;
			collatz_sequence.push_back(num);
		} else {
			num = (3 * num) + 1;
			collatz_sequence.push_back(num);
		}
	}

	return collatz_sequence;
}


// print the contents of a vector
void print_collatz_sequence(const std::vector<int> &collatz_sequence) {
	/*
		Parameters:	[std::vector<int>][collatz_sequence] - A vector that contains the Collatz Sequence.
		Return:		[void]
	*/

	// print the size of the vector
	std::cout << "This Sequence contains " << collatz_sequence.size() << " terms. \n";

	std::cout << "(";
	// use a for loop that prints all of the elements in the collatz_sequence vector:
	for (auto i: collatz_sequence) {
		std::cout << i << ", ";
	}
	std::cout << ") \n";
}
