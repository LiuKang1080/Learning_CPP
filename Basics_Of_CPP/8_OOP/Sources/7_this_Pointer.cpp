// The 'this' Pointer in C++

/*
'this' pointer:
    - 'this' is a reserved keyword.
    - Contains the address of the object, so it's a pointer to the object.
    - Can only be used in class scope.
    - ALL member access is done via the 'this' pointer 
    - Can be used to by programmer:
        - To access data members and methods.
        - To determine if 2 objects are the same.
        - Can be dereferenced (*this) to yield the current object
        
    - In other programming langauges 'this' is usually called 'self'.

    - ex) set balance Account:

        void Account::set_balance(double bal) {
            balance = bal;              // this->balance is implied (dereference and access the member). The compiler is doing 
        }                                    this behind the scenes                                 

    - We use 'this' to disambiguate identifier use:

        void Account::set_balance(double balance) {
            balance = balance;          // which balance? the parameter?
        }

        void Account::set_balance(double balance) {
            this->balance = balance;    // this is unambiguous
        }

        - this->balance refers to the data member (dereference and then access the member)
        - balance refers to the parameter

    - Sometimes it is usefull to know if 2 objects are the same object
    - ex) 

        int Account::compare_balance(const Account &other) {
            if (this == &other) {
                std::cout << "The same objects" << "\n";
            }            
            ...
        }
        
        // (this == &other) compare this with the address of other. If they're the same, then they are the same object

        jim_account.compare(jim_account);
        // the if statement will be true

    - We use the 'this' pointer when we overload the assignment operator.
*/


#include <iostream>


int main() {

    return 0;
}
