// Tree Recursion

/*
Tree Recursion:
    - Before we talk about Tree Recursion Algorithms, we must first talk about Linear Recursion Algorithms. Every single
        recursion algorithm we've looked at up until this point is considered to be a Linear Recursion Algorithm.
    - A Linear Recursion Algorithm contains only 1 recursive call statement
    - Ex)

        void func(int n) {
            if (n > 0) {
                ...
                ...
                func(n-1);
                ...
                ...
            }
        }

    - A Tree Recursion Algorithm contains multiple recursive call statements within the function body.
    - Ex)

        void func(int n) {
            if (n > 0) {
                ...
                ...
                func(n-1);
                ...
                ...
                func(n-1);
                ...
                ...
            }
        }

    - What will the stack trace look like for a Tree Recursion Algorithm?

        void func(int n) {
            if (n > 0) {
                std::cout << n << "\n";
                
                func(n-1);
                func(n-1);
            }
        }

        func(3)

    - The stack height is 4.
    - There are a total of 15 function calls within that tree stack trace.
    
Time Complexity of Tree Recursion Algorithms:
    - Given n into the algorithm, what is the time complexity?
    - We take a look at the number of function calls on each level
        - At the first level there is only 1 function call
        - At level 2 there are 2 function calls
        - At level 3 there are 4 function calls
        - At level 4 there are 8 function calls

    - What is the general mathematical algorithm?
    - func(n) when we pass in n, there are n+1 levels, on each level it doubles the number of function calls from the previous
        level, always starting at 1.
    - We can sum up each level:

        1 + 2 + 4 + 8 = 15
        2^0 + 2^1 + 2^2 + 2^3 = 15 

    - This is a Geometric Progression Series, sum of all the terms, starting at 0 to n, of 2^(n+1).
    - The total sum is = [2^(n+1) - 1]
    - The Time Complexity of this is O(2^n).

    - Not EVERY Tree Recursion Algorithm will be 2^(n+1) - 1. This example is that, but not all tree recursion problems will have
        this answer. We need to perform the stack trace to figure out the specific formula.

Space Complexity of Tree Recursion Algorithm:
    - The Space Complexity depends on the height of the stack. How high does the stack become?
    - n + 1 is the Space Complexity for the example.
    - The maximum order for the Space Complexity is O(n).

General Notes:
    - Starting with 3, we decrement the number by 1 as we move down the tree, but every time we move down the tree we need to
        double the number of brances for each node.

                    3
                2       2
              1   1   1   1

    - We start with 1 node, then in the next level down we have 2 nodes.
    - Move from left to right, always go left down the tree first, then move right going down each branch.
    - This will be the output: 3 2 1 1 2 1 1
*/


#include <iostream>


void func(int n) {
    if (n > 0) {
        std::cout << n << "\n";
                
        func(n-1);
        func(n-1);
    }
}


int main() {
    func(3);

    return 0;
}
