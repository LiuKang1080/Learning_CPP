// Indirect Recursion

/*
Indirect Recursion:
    - Indirect Recursion is when there are multiple functions that call each other recursively in a circular fashion.
    - Take a lool at the 2 functions below:

        void func_a(int n) {
            if (n > 0) {
                std::cout << n << "\n";
                func_b(n-1);
            }
        }

        void func_b(int n) {
            if (n > 1) {
                std::cout << n << "\n";
                func_a(n / 2);
                // pay attnetion to the data types, since we're dividing ints, it will floor/round the result.
            }
        }

    - What does the recursion stack trace look like?
    - What are the outputs?
*/


#include <iostream>


// Function Prototypes:
void func_a(int n);
void func_b(int n);


// Function Definitions:
void func_a(int n) {
    if (n > 0) {
        std::cout << n << "\n";
        func_b(n-1);
    }
}

void func_b(int n) {
    if (n > 1) {
        std::cout << n << "\n";
        func_a(n / 2);
    }
}


int main() {
    func_a(20);

    return 0;
}
