// For Loops in C++

/*
Looping in C++:
    - For Loops: 
        Iterate a specific number of times.
    - Ranged-Based For Loops:
        1 iteration for each element in range or collection.
    - While Loop:
        Iterate while a condition is true, stop when the condition is false, check the condition at the beginning of each 
        iteration. 
    - Do-While Loop:
        iterate while a condition is true, stop when the condition is false, check the condition at the end of each iteration.

For Loops
    - General syntax:

        for (initialization; condition; increment) {
            statement(s);
        }

    - Semi-colons are REQUIRED! The expressions are optional.
    - Condition expression evaluates to a boolean.
    - Initialization is executed once before any iteration occurs. 
    - Condition is checked at the start of each iteration.

    for (int i=1; i<=5; i++) {
        std::cout << i;
    }

    - Here ++i and i++ are the same since the increment happens on its own, and not in another expression.
    - The initialization variable (i) is only visible in the loop.

    - Iterating with arrays:
        int scores = [100, 90, 80];
        
        for (int i=0; i<3; i++) {
            std::cout << scores[i];
        }

        - Remember to pay attention to the bounds of the array!

    - Comma Operator:

    for (int i=1, j=5; i<=5; i++,j++) {
        std::cout << i << " * " << j << " = " << i*j;
    }

    - Since the expressions are optional, but the semi-colons are required we can have syntax like this:
    for (;;) {
        std::cout << "Endless Loop";
    }

    - different steps in increments:
    for (int i=1; i<=10; i+=2) {
        std::cout << i;
    }

    - Counting down:
    for (int i=10; i>0; i--) {
        std::cout << i;
    }

    - For loops with vectors:
        #include <vector>

        std::vector<int> nums = {10, 20, 30, 40};

        for (int i=0; i<nums.size(); i++) {
            std::cout << nums[i]
        }

        - We will get a compiler warning: "Comparison between singed and unsigned integer expressions." Here nums.size() is 
            returning a unsigned integer data type (no vectors of negative size, only positive values), int i is signed, and 
            we're comparing unsigned to signed. We can do: 

        for (unsigned int i=0; i<nums.size(); i++) {
            std::cout << nums[i];
        }
Ranged-Based For Loops:
*/


#include <iostream>


int main() {
    // Sum of all odd numbers between 1 and 15:
    int sum = 0;

    for (int i=1; i<=15; i+=2) {
        sum += i;
    }
    
    std::cout << sum;
    
    return 0;
}
