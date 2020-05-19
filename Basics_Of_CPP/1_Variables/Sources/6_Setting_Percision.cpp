// Setting decimal place percision in C++

/*
    Setting Percision in C++. We need to include the <iomanip> header file, std::fixed and std::setpercision is located in this 
    header file. We need to stream fixed and setpercision to the standard output and the percision will remain at the provided 
    number until the program ends.

    General syntax: 
    #include <iomanip>
    std::cout << std::fixed << std::setpercision(number_of_decimal_places)
*/


#include <iostream>
#include <iomanip>


int main() {

    std::cout << std::fixed << std::setprecision(7);

    double x = 52.5343;
    double y = 29.6982;
    double result = x / y;

    std::cout << "Result is: " << result;
    
    return 0;
}
