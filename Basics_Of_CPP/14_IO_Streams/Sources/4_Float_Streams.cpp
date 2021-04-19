// Floating Point Stream Manipulators in C++

/*
Floating Point Stream Manipulators:
    - The main focus is on the precision of the number that is displayed.
    
    - setpercision = Number of digits displayed
    - fixed = Not fixed to a number of digits after the decimal place.
    - noshowpoint = Trailing zeros are not displayed.
    - noshowpos = No "+" sign displayed for positive numbers

    - These manipulators affect ALL further output to the stream until we turn them off, or the program ends.

setprecision:
    - By defualt C++'s precision is 6 digits, and it WILL round the last number.

        double num = 1234.5678;
        std::cout << num;           // displays 1234.57

    - If C++ cannot display the number, then it will switch to scientific notation and then display with 6 significant digits.

        double num = 123456789.987654321;
        std::cout << num;           // displays 1.23457e+008 (notice the precision is still 6, and it rounded the last digit)

    - Setting the percision:
        std::cout << std::setprecision(n);
        
        std::cout << std::setprecision(9);
        std::cout << num;           // displays 123456780 (notice that rounding still occurs, and there are no trailing zeros)

std::fixed
    - Precision is now handled differently!
    - It will display the precision FROM the decimal point.
    - It will look at the precision starting from the right side of the decimal point.

        std::cout << std::fixed;
        std::cout << num;           // displays precision 6 from the decimal point 123456789.987654

    - std::cout << std::setprecision(n) << std::fixed;
    - Rounding will still occur!

std::scientific
    - Display the number in scientific notation form

        std::cout << std::setprecision(3) << std::scientific;
        std::cout << num;           // displays 1.23e+008 (notice the 3 precision)

    - We can display the 'e' as a capital 'E' by using the uppcase manipulator.
    - The defualt is lower case 'e'.

        std::cout << std::setprecision(3) << std::scientific << std::uppercase;
        std::cout << num;           // displays 1.23E+008

showpos Manipulator:
    - It is the same as before with integers.
    
        std::cout << std::setprecision(3) << std::fixed << std::showpos;
        std::cout << num;           // displays +123456789.998 (note the '+' sign at the front, by defualt it is turned off)

Trailing Zeros | std::showpoint
    
        double num = 12.34;
        std::cout << num;           // displays 12.34

        std::cout << std::showpoint;
        std::cout << num;           // displays 12.3400

    - 12.34 is the defualt. No trailing zeros is the defualt.
    - 12.3400 has trailing zeros up to the precision.

    - Refer to the docs or https://en.cppreference.com/w/ for the other flags and other set/reset flags for the manipulation
        methods.
*/


#include <iostream>
#include <iomanip>


int main() {

    return 0;
}
