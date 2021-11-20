// Time Complexity of Recursion Algorithms

/*
Recursion Time Complexity:
    - Generally when we talk about Time Complexity for algorithms, we always defualt to generic base units of time. We generally
        say that this algorithm takes 1 unit of time, we DO NOT explicitly say the number of seconds that it took to complete the
        algorithm. By taking this apporach, we get rid of the difference between CPU speed, RAM speeds, Operating Systems, and any
        other physical differences (It runs faster on one machine compared to another machine).  
    - We generally say that each statement take 1 unit of time. We then combine all of the statements within the program to get
        the result of the time complexity.
    - Ex) 

        void func(int n) {                  // this function is based on n, order of magnitude is T(n)
            if (n > 0) {                    // 1 time unit
                std::cout << n << "\n";     // 1 time unit

                // recursion call
                func(n-1);                  // what is the time unit? It is NOT 1, since we're calling the function again, T(n-1)
            }
        }

    - What is the total units of time after everything has executed? T(n) = T(n-1) + 2, when n = 0.
    - When n = 0, it takes 1 unit of time, since we're checking the first if statement.
    - For constants, we can assume that n = k, we reduce T(n-1) + 2 into T(n-1) + 1. We substitute T(n-1) = T(n-2) + 1
        T(n) = T(n-2) + 1 + 1 ==> T(n) = T(n-2) + 2, what is n-2? we substitue again getting T(n) = T(n-3) + 3. Assume that n = k
        getting: T(n) = T(n-k) + k. This is order of O(n) for the time complexity.

    - To get the Time Complexity of a certain recursion algorithm we need to perform the Stack Tracing on that recursion algorithm. 
*/


#include <iostream>


int main() {

    return 0;
}
