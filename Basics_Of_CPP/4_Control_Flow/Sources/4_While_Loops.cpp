// While Loops in C++

/*
While Loops:
    - General Syntax:

        while (expression) {
            statement(s);
        }

    - expression is evaluated to a boolean value before the iteration happens.
    - If expression is evaluated to false before the looping starts, then the loop will never run.

    ex)
    int i = 0;
    while (i <= 5) {
        std::cout << i << "\n";
        i++;                        // Here the i++ is important, if it is not here then the loop will become an infinite loop
    }

    ex) Even numbers while loop:
    int i = 0;
    while (i <= 10) {
        if (i % 2 == 0) {
            std::cout << i << "\n";
        }
        i++;                        // i++ is required to prevent an infinite loop
    }
*/


#include <iostream>


int main() {

    return 0;
}
