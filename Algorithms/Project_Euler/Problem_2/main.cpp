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
		parameters:
		[limit][int] = The upper limit of the loop.
	*/

	int total_sum = 0;
	int x = 0;
	int y = 1;
	int t = 0;

	for (int i = 1; i <= limit; i++) {
		t = x + y;
		x = y;
		y = t;

		if (y % 2 == 0) {
			total_sum += y;
		}
		
		if (y >= limit) {
			return total_sum;
		}
	}
}


int main() {
	std::cout << "Sum of even Fibonacci numbers up to 4 million: " << fibonacci(4000000) << "\n";
	
	return 0;
}
