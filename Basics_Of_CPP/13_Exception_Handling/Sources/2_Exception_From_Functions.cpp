// Throwing Exceptions from Functions

/*
Throwing Exceptions from Functions:

        double calculate_avg(int sum, int total) {
            return static_cast<double>(sum) / total;
        }

    - What do we return when total is 0?
    - We need to throw an exception so we can deal with the division by 0

        double calculate_avg(int sum, int total) {
            if (total == 0) {
                throw 0;
            }

            return static_cast<double>(sum) / total;
        }

    - The catch handler isn't in this function, how does C++ catch the exception?
    - The catch handler must be on the same stack that called this function, C++ will unwind the stack looking for the catch

        double average {};
        int sum;
        int total;

        try {
            average = calculate_avg(sum, total);
            std::cout << average << "\n";
        } catch (int &ex) {
            std::cerr << "Cannot divide by zero \n";
        }

    - Line 29 is the line that might throw an exception, so we put the function call within the try block, the function itself
        has the throw keyword, that throws an int.
    - The catch is looking for a thrown exception of the data type int. When an int exception is thrown it will catch it.

    - The best practice is: Throw by value, Catch by reference.

    - If we throw an exception without catching it from a function, we will get the result:
        "terminate called after throwing an instance of 'int'"
*/


#include <iostream>


double calculate_mpg(int miles, int gallons) {
    std::cout << "Miles entered: " << miles << "\n";
    std::cout << "Gallons entered: " << gallons << "\n";
    
    if (gallons == 0) {
        throw 0;
    }

    return static_cast<double>(miles) / gallons;
}


int main() {
    // miles per gallon example, exceptions from functions
    int miles = 15;
    int gallons = 0;
    double miles_per_gallon {};

    // use a try-catch block to catch the exception thrown from the function
    try {
        miles_per_gallon = calculate_mpg(miles, gallons);
        std::cout << "Miles per gallon result: " << miles_per_gallon << "\n";
    } catch (int &ex) {
        std::cerr << "Gallons is equal to 0, cannot divide by zero \n";
    }

    return 0;
}
