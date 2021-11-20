// Tail Recursion

/*
Tail Recursion:
    - We've seen these types of recursion algorithms. The previous 2 examples are an example of Tail Recursion.

        void func(int n) {
            if (n > 0) {
                std::cout << n << "\n";
                func(n-1);
            }
        } 

        func(3);

    - Why is this algorithm considered a Tail Recursion algorithm? What does it mean for an algorithm to be a Tail Recursive
        algorithm?
    - We know that a function calling itself is what makes an algorithm recursive, but if the function call is the last
        statement within the function, then that algorithm will be known as a Tail Recursive algorithm.
    - All of the operations that come before the function call are done at CALLING time. The function will NOT be performing
        anything at RETURNING time.
    - Unless we're changing the function AFTER it has completely executed the recursion, then it will all be done at CALLING time.
    - func(n-1) + n: The +n will be added on during RETURNING time.
    - Generally what we mean by Tail Recusion algorithms, is that all NONE of the executions will be performed during RETURNING
        time. All of the executions are perfomed during CALLING time.

    - All loops can be converted into recusion algorithms, and all recursion algorithms can be converted into loops.

        void func(int n) {
            while (n > 0) {
                std::cout << n << "\n";
                n--;
            }
        }

    - The output of the recursion algorithm, and the loop algorithm the output will be the same.
    - Which algorithm is more efficent?
    - Time Complexity: Both of the algorithms is O(n)
    - Space Complexity: From the previous examples we know that the Tail Recursion Algorithm will be O(n+1) ==> O(n).
        What about the loop? What does the stack look like in memory when the loop function gets called? There will be only one
        function call object on the stack. There is only 1 activation record. O(1) Constant Space Complexity.
    
    - The Time Complexity for Tail Recursion Algorithms vs. Loops are the same. For the Space Complexity, the loop takes less
        units of space, therefore it is better to use Loops over Recursion when dealing with Tail Recursion Algorithms.
    
    - Not every loop will be more efficent than a recursion algorithm, we need to look at the Time and Space complexity for loops
        and recursion.
    - Certain compilers during code optimizations will convert the recursion code into loop code, and in certain cases vice-versa.
        It depends on the how the compiler optimizes the code. Not all compilers are equal, just because one compiler does, does
        not mean the next compiler will.
*/


#include <iostream>


int main() {

    return 0;
}
