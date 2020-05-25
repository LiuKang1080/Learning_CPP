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
#include <cstdlib>
// use rand() for random number generation
#include <iomanip>


int main() {
    // guess the random number

    // general syntax for random number generation: (std::rand() % max_number) + min_number 
    // ex) int random_value = (std::rand() % 30) + 15;
    // this will generate a number between the minimum of 15 and the maximum of 30

    // generating values between 0 and 1:
    // for (int i = 0; i < 10; i++) {
    //     std::cout << (float)std::rand() / RAND_MAX << " ";
    // }

    // initialize variables, random number
    int my_int = 3;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << static_cast<double>(my_int);
    



    return 0;
}
