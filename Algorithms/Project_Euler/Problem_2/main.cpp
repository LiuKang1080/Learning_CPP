// Project Euler - Problem #2

/*
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/


#include <iostream>


// fibonacci sum function
int fibonacci(int limit) {
	/*
		parameters:	[int][limit] = The upper limit of the loop.
		return:		[int][total_sum]
	*/

	int total_sum = 0;
	int x = 0;
	int y = 1;
	int temp = 0;

	for (int i = 1; i <= limit; i++) {
		temp = x + y;
		x = y;
		y = temp;

		if (y % 2 == 0) {
			total_sum += y;
		}
		
		if (y >= limit) {
			break;
		}
	}

	return total_sum;
}


int main() {
	// Specific solution to the Project Euler problem number 2:
	int limit = 4000000;
	std::cout << "Sum of even Fibonacci numbers up to " << limit << ": " << fibonacci(limit) << "\n";
	
	return 0;
}
