// Factorial Recursion

/*
Factorial of N using Recursion:
    - A factorial of a given number is = 1*2*3*4*...*n
    - This is just like the previous example with the sum of natural numbers, except instead of addition it is multiplication.
    - Factorial is denoted with !
    - Both 1! and 0! equal 1
    - fact(n) = 1*2*3*...*(n-1)*n
    - Here everything except n is just the factorial of (n-1)
    - Therefore fact(n) = fact(n-1) * n
    - We can code it recursively:

        int fact(int n) {
            if (n == 0) {
                return 1;
            } else {
                return fact(n-1) * n;
            }
        }

    - We can convert the recursion into a loop:

        int fact(int n) {
            int total = 1;

            for (int i = 1; i <= n; i++) {
                total *= i;
            }

            return total;
        }

    - The Space and Time Compelxity is the same as the example with the Sum of Natural Numbers. 

    - Take a look at the actual code in the if statement, if (n == 0), what happens when n is less than 0?
    - If we were to run the program with n less than 0, we will get an Stack Overflow Error. The program will continue to place
        function calls onto the stack until the stack memory runs out. This is bad code, we need to change the if statment:

        int fact(int n) {
            if (n <= 1) {
                return 1;
            } else {
                return fact(n-1) * n;
            }
        }

    - This is the proper recursion function that we use to properly calculate factorials.
    - Also pay attention to the data types? 100! will NOT fit into an int, using the C++ standard without making our memory unbound
        numbers the highest we can go is long long int.
    - If we try doing the factorial of a large number we start to get weird results, negative numbers, or 0. This is data type
        overflow.
    - We can also use other external libraries like C++ Boost to get larger numbers / results.
*/


#include <iostream>


long long int fact(long long int n) {
    if (n <= 1) {
        return 1;
    } else {
        return fact(n-1) * n;
    }
}

int ifact(int n) {
    int total = 1;

    for (int i = 1; i <= n; i++) {
        total *= i;
    }

    return total;
}


int main() {
    int number = 10;
    int inum = 5;

    std::cout << "Factorial of " << number << " is: " << fact(number) << "\n";
    std::cout << "Factorial of " << inum << " using the loop is: " << ifact(inum) << "\n";

    return 0;
}
