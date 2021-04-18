// Boolean Stream Manipulation in C++

/*
Formatting Boolean Types:

Manipulation Version:
    - The defualt display setting for boolean values is 1 and 0. 1 = true, 0 = false.
    - Sometimes we want to display the string versions: true and false instead of 1 and 0 for the outputs.

        std::cout << (1 == 1);      // displays 1
        std::cout << (1 == 2);      // displays 0

    - We can switch to the strings true and false for the output.
    - we MUST include the <iomanip> header file. #include <iomanip>

        std::cout << std::boolalpha;
    
    - This tells the compiler that ALL further couts to format all boolean outputs to use the string version.
    
        std::cout << (1 == 1);      // displays true
        std::cout << (1 == 2);      // displays false

    - Once we set the formatting type, ALL further boolean outputs will be affected!
    - These methods and manipulations are ONLY for displaying purposes, they only affect the streams!
    
Method Version:
    - Use the setf() method for the formatting:

        std::cout.setf(std::ios::boolalpha);
        std::cout.setf(std::ios::noboolalpha);

    - We can reset the setting back to the default setting:

        std::cout << std::resetiosflags(std::ios::boolalpha);
*/


#include <iostream>
#include <iomanip>


int main() {

    // defualt boolean values:
    std::cout << (1 == 1) << "\n";
    std::cout << (1 == 2) << "\n";

    // change the boolean output to the string version:
    // from here on out ALL boolean values for the output will be in the string version, until we change it back to normal
    std::cout << std::boolalpha;
    std::cout << (1 == 1) << "\n";
    std::cout << (1 == 2) << "\n";

    // to change it back to normal:
    std::cout << std::noboolalpha;
    std::cout << (1 == 1) << "\n";
    std::cout << (1 == 2) << "\n";
    
    return 0;
}
