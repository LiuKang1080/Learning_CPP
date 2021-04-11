// Throwing and Handling Multiple Exceptions from functions in C++

/*
Handling Multiple Exceptions:
    - Throwing multiple exceptions from a function.
    - What if a function fails in multiple ways.
        - gallons = 0?
        - miles or gallons is negative?

        double calculate_mpg(int miles, int gallons) {
            return static_cast<double>(miles) / gallons;
        }

    - We can throw different types of exceptions for each condition.

        double calculate_mpg(int miles, int gallons) {
            if (gallons == 0) {
                throw 0;
            }
            if (miles<0 || gallons<0) {
                throw std::string {"Negative value error \n"};
            }

            return static_cast<double>(miles) / gallons;
        }

    - now for the try-catch block:

        double miles_per_gallon {};
        try {
            miles_per_gallon = calculate_mpg(miles, gallon);
            std::cout << miles_per_gallon << "\n";
        } catch (int &ex) {
            std::cerr << "Cannot divide by 0 \n";
        } catch (std::string &ex) {
            std::cerr << ex << "\n";
        }

    - Since the calculate_mpg() function can throw an int or a std::string we need to catch BOTH of the exception types.
    - 2 catch handlers, one for each of the exception type.
    - If we do NOT handle one of the exceptions, then C++ will terminate the function, procede up the call stack looking for
        the proper catch handler until it finds it or the program terminates.

Catch ALL Handler:
    - This catch handler will fire no matter the exception data type that is thrown.

        catch (...) {
            std::cerr << "Unknown Error \n";
        }
*/


#include <iostream>


double calculate_mpg(int miles, int gallons) {
    if (gallons == 0) {
        throw 0;
    } 
    if (miles<0 || gallons<0) {
        std::cout << "Either Miles or Gallons is less than 0. \n";
        throw std::string {"Negative Value Error. \n"};
    }

    return static_cast<double>(miles) / gallons;
}


int main() {
    int miles = -15;
    int gallons = 10;
    double miles_per_gallon {};

    try {
        miles_per_gallon = calculate_mpg(miles, gallons);
        std::cout << "Result MPG: " << miles_per_gallon << "\n";
    } catch (int &ex) {
        std::cerr << "Gallons = 0: Cannot Divide by 0 \n";
    
    // } catch (...) {
    //     std::cerr << "Unknown error \n";
    // }
    // if we use a catch all handler we lose access to the reference variable (&ex), and instead we use a generic error message

    } catch (std::string &ex) {
        std::cerr << ex << "\n";
    }

    return 0;
}
