// Head Recursion

/*
Head Recursion:
    - Head Recursion Algorithms are the opposite of Tail Recursion Algorithms. Generally If the recursion function call is the 
        first thing that happens, then it is considered to be a Head Recursion Algorithm.
    -  We've seen this example before:

        void func(int n) {
            if (n > 0) {
                func(n-1);
                
                // rest of the code block | rest of the statements
                ...
                ...
                ...
                std::cout << n << "\n";
            }
        }

    - All of the statements are done during RETURNING time, or processed after the recursion is complete.
    - If there are statements before the recursion call, then that recursion algorithm is not considered a Head Recursion Algorithm.
    - There is no processing during the calling phase.
    
    - Once again all recursion algorithms can be converted into a loop, and vice-versa.
    - Remember what the output was for the recursion call in the previous files. The output was 1,2,3. If we just take n-- and
        put it into the while loop the output will be wrong! We need to modify the loop in order to get the result.

        void func(int n) {
            int i = 1;

            while (i <= n) {
                std::cout << i << "\n";
                i++;
            }
        }

    - We CANNOT just do the following, the output will be WRONG!

        void func(int n) {
            while (n > 0) {
                n--;
                std::cout << n << "\n";
            }
        }

    - Generally Head Recursion Algorithms are not easily converted into loops, like Tail Recursion Algorithms, but they can be
        converted with some modifications.
*/


#include <iostream>


int main() {

    return 0;
}
