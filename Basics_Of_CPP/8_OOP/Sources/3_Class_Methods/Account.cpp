// .cpp File for the Account Class Implementation

/*
Account Class Implementation:
    - Generally the class implementation will have its own seperate .cpp and .h files, especially in larger programs.
    - #include < > vs #include " ": The < > are used to include system header files and the compiler knows where these are
        located. The " " tells the compiler to include header files that are local to the project, the compiler also knows where
        these are.

    - The Class specification is in Account.h. We can write the Class implementation in this file. This will be writting the
        method definitions.

    - Once we have the specification in the .h header file, and the implementation here in the .cpp we can now use both of them
        in the main.cpp file.
*/


#include "Account.h"


// remember that the actual definition here must match the method prototypes (the data types must match). 
// we must use the scope resolution operator to let the compiler know that we are working with the class that is in a different
// scope.
void Account::set_balance(double bal) {
    balance = bal;
}

double Account::get_balance() {
    return balance;
}
