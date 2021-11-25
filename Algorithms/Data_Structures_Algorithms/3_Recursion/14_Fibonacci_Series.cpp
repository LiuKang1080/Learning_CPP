// Fibonacci Series using Recursion

/*
Fibonacci Series with Recursion:
    - The Fibonacci Series is 0, 1, 1, 2, 3, 5, 8, 13, ...
    - The next term in the series is produced by the addition of the previous last 2 terms.
    - We have n number of terms, and fib(n) as the result of that term.
    - When n = 0, then fib(0) = 0.
    - When n = 1, then fib(1) = 1.
    - We have the general patter when n > 1: fib(n-2) + fib(n-1)
    - We can code the fibonacci series as a recursive function like so:

        int fibonacci(int n) {
            if (n <= 1) {
                return n;
            } else {
                return fibonacci(n-2) + fibonacci(n-1);
            }
        }

    - We can also write the series iteratively:

        int fibonacci(int n) {
            int sum = 1;
            int var1 = 0;
            int var2 = 1;

            if (n <= 1) {
                return n;
            }

            for (int i = 2; i <= n; i++) {
                sum = var1 + var2;
                var1 = var2;
                var2 = sum;
            }

            return sum;
        }

    - What is the Time Complexity of this series?
    - The Time Complexity of the iterative version is O(n).
    - The Time Complexity of the recursive version is O(2^n) approx.
    
    - Is there a way to reduce the time complexity?
    - Yes we can, notice that if we call fib(5), fib(3), fib(2), and fib(1) get called multiple times.
    - Let us take an array of length n, and initialize the array with -1.
    - As we are moving down the stack trace, every time we find a new result of fib(n), we will replace the -1 with the result
        at that nth index.
    - When fib(1) gets called multiple times, rather than making that call, we check to see if the result is already in the
        array, if the result is already there then we just return the result, if not then we call the fib() function to get
        the result.
    - When we get the result of the sum we replace the -1 at that nth location in the array with the result, and then continue
        back up the stack trace tree.
    - The Time Complexity of this version is O(n+1) ==> this is on the order of O(n).
    
Memoiziation:    
    - By storing the results into an array, we can cut down on the number of function calls, and reduce the time complexity of
        the algorithm.
    - This process is what is known as [Memoization]. Storing the results tp prevent extra function calls.
    - Our code for the recursive version of fibonacci needs to be modified to include the memoization.

        // create the global array
        int arr[10];
        
        // loop through the array and set all elements to -1
        for (int i = 0; i < 10; i++) {
            arr[i] = -1;
        }

        int fibonacci(int n) {
            if (n <= 1) {
                arr[n] = n;
                return n;
            } else {
                if (arr[n-2] == -1) {
                    arr[n-2] = fibonacci(n-2);
                }
                
                if (arr[n-1] == -1) {
                    arr[n-1] = fibonacci(n-1);
                    arr[n] = arr[n-2] + arr[n-1];
                }

                return arr[n-2] + arr[n-1];
            }
        }
*/


#include <iostream>
#include <array>


// global array:
int arr[10];


int fibonacci(int n) {
    if (n <= 1) {
        arr[n] = n;
        return n;
    } else {
        if (arr[n-2] == -1) {
            arr[n-2] = fibonacci(n-2);
        }
                
        if (arr[n-1] == -1) {
            arr[n-1] = fibonacci(n-1);
            arr[n] = arr[n-2] + arr[n-1];
        }

        return arr[n-2] + arr[n-1];
    }
}


int main() {
    int term = 5;

    // initialize all of the elements of the array to -1
    for (int i = 0; i < 10; i++) {
        arr[i] = -1;
    }

    std::cout << "The " << term << " term in the fiboncacci series is: " << fibonacci(term) << "\n";

    return 0;
}
