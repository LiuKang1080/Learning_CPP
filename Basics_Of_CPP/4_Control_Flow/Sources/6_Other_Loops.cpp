// Continue, Break, and nested Loops in C++

/*
Continue:
    - No further statements in the body of the loop are executed.
    - Control immediately goes directly to the beginning of the loop for the next iteration.

Break:
    - No further statements in the body of the loop are executed.
    - Loop is immediately terminated.
    - Control immediately goes to the statement following the loop construct.

ex)

    #include <vector>

    std::vector<int> values {1, 2, -1, 3, -1, -99, 7, 8, 10};

    for (auto val: values) {
        if (val == -99) {
            break;
        } else if (val == -1) {
            continue;
        } else {
            std::cout << val;
        }
    }

Infinite Loops:
    - Condition expression always evaluates to true.
    - Usually unintented / programmer error.
    - Sometimes infinite loops are what we need (event-driven programs, OS).
    - Use break to control the infinite loop

    - Infinite For Loop:
        for (;;) {
            std::cout << "Printing Forever";
        }

    - Infinite While Loop:
        while (true) {
            std::cout << "Printing Forever";
        }

    - Infinite Do-While Loop:
        do {
            std::cout << "Printing Forever";
        } while (true);

    ex) while (true) {
        char again{};
        std::cout << "Do you want to loop again? (Y/N): ";
        std::cin >> again;

        if (again=='N' || again=='n') {
            std::cout << "Good bye!";
            break;
        }
    }

Nested Loops:
    - Loop within another loop.
    - Can be as many levels deep as the program needs.
    - Generally used for multi-dimensional data structures (vectors / arrays).
    - Outer Loops vs. Inner Loops
    - Inner loops loop faster

    ex)
        for (int outer=1; outer<=2; outer++) {
            for (int inner=1; inner<=3; inner++) {
                std::cout << outer << ", " << inner << "\n";
            }
        }

    - Multiplication Table:

    for (int i=1; i<=10; i++) {
        for (int j=1; j<=10; j++) {
            std::cout << i << "*" << j << " = " << i*j << "\n";
        }
    }
*/


#include <iostream>


int main() {

    return 0;
}
