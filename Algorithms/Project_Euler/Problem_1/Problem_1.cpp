// Project Euler - Problem #1

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
*/


#include <iostream>


int multiple(const int &limit) {
	/*
		- loop through all of the numbers between 1 and the limit provided
		- check to see if the number is divisible by 3 or 5. If it is divisible, then add that number to the total
		
		parameters:	[int][limit] = The upper limit of the loop.
		return:		[int]][total_sum] 
	*/


	int total_sum = 0;

	for (int i = 0; i < limit; ++i) {
		if ((i %3 == 0) || (i %5 == 0)) {
			total_sum += i;
		}
	}

	return total_sum;
}


int main() {
	// Specific solution to the Project Euler problem number 1:
	int limit = 1000;
	
	std::cout << "The sum of all the multiples of 3 and 5 below 1000 is: ";
	std::cout << multiple(limit) << "\n";

	return 0;
}
