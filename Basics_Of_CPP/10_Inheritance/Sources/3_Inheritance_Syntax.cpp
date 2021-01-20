// Inheritance Syntax in C++

/*
General Syntax of Inheritance in C++:
    
    class Base {
        // Base class members...
    };

    class Derived: access-specifier Base {
        // Derived class members...
    };

    - The access specifiers can be public, private, and protected.
    - If we do not provide an access modifier, then by defualt private inheritance is used.

    Public:
        - Most common.
        - Establishes "is-a" relationship between the Derived and Base classes.

    Private and Protected:
        - Establishes "derived class 'has-a' base class" relationship.
        - Generally used to implement one class in terms of another.
        - "is implemented in terms of" relationship.
        - Different from composition, they are not the same!

    - Most languages use public inheritance, and a majority of the time in C++, it will also be public inheritance.

    ex)

        class Account {
            // Account class members...
        };
        // We assume that the Account class is already existing, and has its own member data and methods

        // deriving a savings account from the base account class
        class Savings_Account {
            // Savings_Account class members...
        };

    - Savings_Account "is-a" Account.
    - Now after creating classes, we can create objects, and use them.

    - Account class:

        Account account {};
        Account *p_account = new Account();

        account.deposit(1000.00);
        p_account->withdraw(200.00);

        delete p_account;

    - Savings Account:

        Savings_Account sav_account {};
        Savings_Account *p_sav_account = new Savings_Account();

        sav_account.deposit(1000.00);
        p_sav_account->withdraw(500.00);

        delete p_save_account;

    - Inheritance as an idea can be very simple, but the detail implementation can get complex, especially in C++.
*/


#include <iostream>


int main() {

    return 0;
}
