// Project Euler Problem #5

/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/


#include <iostream>
#include <chrono>

#include "includes.h"	
#include "method_1.h"	// brute_force_method functions
#include "method_2.h"


/*
	- Timer class code is from Learncpp website chapter 11.18 - "Timing Your Code"
	- https://www.learncpp.com/cpp-tutorial/timing-your-code/
*/
class Timer {
private:
	// Type aliases to make accessing nested type easier
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;
	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() 
		:m_beg(clock_t::now()) {
		
		// Timer constructor
	}

	void reset() {
		m_beg = clock_t::now();
	}

	double elapsed() const {
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};


int main() {
	// Specific solution to the Project Euler Problem number 5:
	int limit = 20;
	
	std::cout << "Timer started \n";
	Timer t;
	std::cout << "brute_force_method_1 is called. Solution: " << brute_force_method_1() << "\n";
	std::cout << "Time elapsed: " << t.elapsed() << "\n";
	
	std::cout << "Timer started \n";
	t.reset();
	std::cout << "brute_force_method_2 is called. Solution: " << brute_force_method_2(limit) << "\n";
	std::cout << "Time elapsed: " << t.elapsed() << "\n";

	return 0;
}

/*
NOTES:
	- Solution: 232792560
	- brute_force_method_1 time elapsed: 0.23 seconds average over the course of 3 runs.
	- brute_force_method_2 time elapsed: 1.20 seconds average over the course of 3 runs.
	- Run this in Production mode in Visual Studio!
		- Running this (espeically brute_force_method_2) will take ~3 minutes!
*/