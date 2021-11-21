// Nested Recursion

/*
Nested Recursion:
    - An algorithm is considered a Nested Recursion Algorithm when the function call to itself passes in the function as the
        parameter
    - Ex)

        void func(int n) {
            if (...) {
                ...
                func(func(n-1));
                ...
            }
        }

    - The parameter itself IS also a recursive call.
    - func(func(n-1)), until func(n-1) is completly resolved, func() cannot start.
    - Recursion inside recursion.
    - Ex)

        int func(int n) {
            if (n > 100) {
                return n - 10;
            } else {
                return func(func(n+11));
            }
        }

        func(95);

    - What does the Recursive Stack Trace look like?
    - What are the outputs?
*/


#include <iostream>


int func(int n) {
    if (n > 100) {
        std::cout << "In the if statement, n is: " << n << "\n";
        return n - 10;
    } else {
        std::cout << "In the else statement, n is: " << n << "\n";
        return func(func(n+11));
    }
}


int main() {
    // nested function example
    func(95);

    return 0;
}
