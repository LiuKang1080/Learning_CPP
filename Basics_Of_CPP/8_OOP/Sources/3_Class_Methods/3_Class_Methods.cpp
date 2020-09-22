// Implementing Class Member Methods in C++

/*
Member Methods:
    - Methods in classes are like functions.
    - Member methods have access to member attributes, so we do NOT need to pass in attributes as arguments.
    - We can implement methods inside class declarations (they will be implicitly inline).
        - For small methods it is acceptable to place them inside the class declaration, but for larger and more complex methods
            we can use multple files to define the classes and its methods.
    - In C++ it is common to seperate a class' specification from its implementations.
    - We can use seperate files: .h for the class declaration, and .cpp for the class implementation.
    - Methods can be implemented outside the class declaration (we need to use the scope resolution operator)
        Class_Name::method_name
    - Generally we want to seperate 

Implementing Methods Inside Class Declarations:
    - The syntax is exactly the same as defining C++ functions.
    - We can use public methods to gain access to the attributes that are privatel, allowing us to change the data depening on 
        how the method is implemented.

    - General Syntax: We can set the methods directly within the Class itself.

        class Account {
            private:
            double balance;

            public:
            void set_balance(double bal) {
                balance = bal;
            }

            double get_balance() {
                return balance;
            }
        }; 

Implementing Methods Outside Classes:
    - We can also define class methods outside of the class using the scope resolution operator.
    -Inside the class we define the method prototypes so that the compiler knows the names and parameters of the methods. Allows
        type checking to automatically occur.

    - General syntax:

        class Account {
            private:
            double balance;

            public:
            void set_balance(double bal);
            double get_balance();
        };

        void Account::set_balance(double bal) {
            balance = bal;
        }

        double Account::get_balance() {
            return balance;
        }

Using Seperate Files:
    - As programs get larger we should seperate the class specification from the class implementation. We can do this by using 
        seperate files.

    - In Account.h This file is a header file, and contains the specification of the class.
    - look at { Account.h }

    - Once we have our header file with the proper include guards or #pragma once, we can then write the class implementation.
    - Generally the class implementation is written in its own seperate .cpp file
    - look at { Account.cpp }

    - Now that we have our specification in the .h header file and the implementation in the .cpp file, how can we use the 
        Account class in main.cpp?
    - This file will refer to as the main.cpp file. 

    - We just #include "Account.h" the header file. 
    - It is important that we always include .h header files and never .cpp files 
    - We then write our main.cpp 
    - Both the main.cpp and the Account.cpp are compiled and linked to produce the .exe
*/


#include <iostream>
#include <iomanip>

#include "Account.h"


int main() {
    std::cout << std::fixed << std::setprecision(2);

    // create a new object using the Account class
    Account bob_account;
    bob_account.set_balance(1000.00);

    std::cout << bob_account.get_balance() << "\n";

    return 0;
}
