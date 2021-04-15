// User Defined Exception Classes in C++

/*
User Defined Exceptions:
    - C++ allows for us to create exception classes and throw instances of these classes.
    
    - Best practice:
        - Throw an object, not a primitive type.
        - Throw an object by value.
        - Catch an exception by reference (or const reference)

    - MPG example:

        class DivideByZeroException {};
        class NegativeValueException {};

    - When we throw an exception, we can create an object of one of these class types and throw it.
    - We can also have constructors and destructors for these classes

        double calculate_mpg(int miles, int gallons) {
            if (gallons == 0) {
                throw DivideByZeroException();              // thrown by value
            }

            if (miles<0 || gallons<0) {
                throw NegativeValueException();             // thrown by value
            }

            return static_cast<double>(miles) / gallons;
        }

    - try-catch block

        try {
            miles_per_gallon = calculate_mpg(miles, gallons);
            std::cout << miles_per_gallon << "\n";
        } catch (const DivideByZeroException &ex) {
            std::cerr << "Cannot divide by zero \n";
        } catch (const NegativeValueException &ex) {
            std::cerr << "Negative Values: Either Miles or Gallons is a negative value \n";
        }

    - We create BOTH catch handlers since the calculate_mpg() function can throw 2 exceptions.
    - If an exception is thrown one of these catch handlers will handle it.
    - We're catching by const reference. If we have provided attributes of methods in the exception classes then we would access
        them here with the reference.
*/


#include <iostream>


// Exception classes:
class DivideByZeroException {
public:
    /*
        - remember that can have C++ create a default constructor and destructor for us:

        DivideByZeroException() = default;
        ~DivideByZeroException() = default;
    */

    // constructor
    DivideByZeroException() {
        std::cout << "Divide by zero constructor called. \n";
        std::cout << "Divide By Zero Exception: Gallons = 0. Cannot divide by zero. \n";
    }

    // destructor
    ~DivideByZeroException() {
        std::cout << "Divide by zero destructor called. \n";
    }
};

class NegativeValueException {
public:
    /*
        - remember that can have C++ create a default constructor and destructor for us:

        NegativeValueException() = default;
        ~NegativeValueException() = default;
    */

    // constructor
    NegativeValueException() {
        std::cout << "Negative value exception constructor called. \n";
        std::cout << "Negative Value Exception: Either Miles or Gallons is a negative value. \n";
    }

    //destructor
    ~NegativeValueException() {
        std::cout << "Negative value exception destructor called. \n";
    }
};

// Functions:
double calculate_mpg(int miles, int gallons) {
    if (gallons == 0) {
        throw DivideByZeroException();
    }
    if (miles<0 || gallons<0) {
        throw NegativeValueException();
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
    } catch (const DivideByZeroException &ex) {
        std::cerr << "Divide by zero exception caught. \n";
    } catch (const NegativeValueException &ex) {
        std::cerr << "Negative value exception caught. \n";
    }

    return 0;
}
