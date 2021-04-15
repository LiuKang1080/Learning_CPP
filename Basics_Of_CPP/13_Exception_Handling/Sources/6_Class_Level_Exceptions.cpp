// Class Level Exceptions in C++

/*
Class Level Exceptions:
    - Exceptions can also be thrown from classes.
    
    - Throwing from class methods:
        - These work as the same way as they do for regular functions.

    - Throwing from constructors:
        - Constructors may fail (failed to allocate the desired memory on the heap)
        - Constructors do NOT return any values, so if we fail on the constructor, we can throw an exception instead.
        - We throw an exception in the constructor if we cannot initialize an object.

    - Throwing from destructors:
        - DO NOT THROW FROM A DESTRUCTOR!!!
        - A destructor is marked as no except by default, it does NOT throw any exceptions.
        - The reason is if a destructor is called because of an exception and then that destructor throws an exception, then the
            catch block will never be reached!
        - The best practice is: DO NOT throw in a destructor.

    - Throwing from a class - Account Example:

        Account::Account(std::string name, double balance)
            :name{name}, balance{balance} {

            if (balance < 0.0) {
                throw IllegalBalanceException();
            }
        }

        try {
            // create an checking account for bob on the heap with a unique pointer
            std::unique_ptr<Account> bob_account = std::make_unique<Checking_Account>("Bob", -10.0)     // this will throw an error!
        
            // use bob's account
        } catch (const IllegalBalanceException &ex) {
            std::cerr << "Cannot initialize account: Negative balance provided. \n";
        }
*/


#include <iostream>


int main() {

    return 0;
}
