// What happens to Static Variables during recursion?

/*
Static Variables During Recursion:
    - What happens to static variables during recursion? Take a look at the example below:

        int func(int n) {
            if (n > 0) {
                return func(n-1) + n;
            }

            return 0;
        }

        int main() {
            int x = 5;
            std::cout << func(x) << "\n";

            return 0;
        }

    - What does the stack trace look like?
    - We start at the first function call, x and n are 5. There are 2 components to the stack trace, the function calls, and the
        number to add (+ n), func(5) ==> func(4) + __ ==> func(3) + __ ==> func(2) + __ ==> func(1) + __ ==> func(0) = 0. Those
        are the function calls, so now we have to get n on each step. We work backwards from the return calls:
        func(0) + 1 = 1 ==> func(2) = func(1) + 2 = 3 ==> func(2) + 3 = 6 ==> func(3) + 4 = 10 ==> func(4) + 5 = 15.
        So func(5) = 15
    - We can use print statements to see how they change when the functions are called during recursion.
    
Static Variables:
    - What happens if we use static variables?
    - Remember that static variables get created only once!

        int func(int n) {
            static int x = 0;

            if (n > 0) {
                x++;
                return func(n-1) + x;
            }

            return 0;
        }

        int main() {
            int a = 5;
            std::cout << func(x) << "\n";

            return 0;
        }
 
    - What does the stack trace look like? func(5) ==> func(4) + __ [we don't get x now even though it's a static variable, we
        get x in the returning time, the function calls happen first!] ==> func(3) + __ ==> func(2) + __ ==> func(1) + __ ==>
        func(0). Now what was x? x has been incrementing by 1 all this time, x is 5 when func(0) is resolved. func(0) = 0, so we
        add 5 to it, and move back up the stack trace. func(1) = 5, + 5 = 10, func(2) [10] + 5 = 15 ==> func(3) + 5 = 20 ==> 
        func(4) + 5 = 25 ==> func(5) = 25.

    - Draw the Stack Trace Tree for recursion. Knowing what the stack looks like visually is helpful. We can also keep track of
        local and static/global variables.
*/


#include <iostream>


int func(int n) {
    if (n > 0) {
        std::cout << "n is currently: " << n << "\n";
        // static int x = 0;
        // std::cout << "x is currently: " << x << "\n";

        return func(n-1) + n;
        // return func(n-1) + x;
    }

    // base case of recursion
    return 0;
}


int main() {
    int a = 5;
    std::cout << "Final result: " << func(a) << "\n";

    return 0;
}
