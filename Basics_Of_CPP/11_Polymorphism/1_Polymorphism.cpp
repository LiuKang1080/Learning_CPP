// Polymorphism in C++

/*
Polymorphism:
    - Using polymorphism & Inheritance provides us wuth the power to create reusable and flexable programs.
    - What is Polymorphism?
        - There are several types of Polymorphism in C++:
        - Compile-time / Run-time
        - Early binding / Late binding
        - Static binding / Dynamic binding

    - Runtime Polymorphism:
        - Being able to assign different meanings to the same function at run-time.
        - Allows us to program more abstractly.
        - We let C++ figure out which function to call at run-time.
        
        - Run-time Polymorphism is NOT the defualt in C++, it is achieved via:
            - Inheritance
            - Base class pointers and references
            - Virtual functions

        - The defualt type of binding in C++ is Static Binding.

    - A non-Polymorphic example - static binding:

        Account a;
        a.withdraw(100);            // Account::withdraw()

        Savings b;
        b.withdraw(100);            // Savings::withdraw()

        checking c;
        c.withdraw(100);            // Checking::withdraw()

        Trust d;
        d.withdraw(100);            // Trust::withdraw()

        Account *p - new Trust();
        p->withdraw(100);           // Account::withdraw(), it should be Trust::withdraw()

        - This is static binding, the compiler doesn't care that the Trust object is heap, or that it is inherited, it only cares
            that the object pointer p is pointing to is an Account type object, so it will call the Account::withdraw method. 
            This syntax on line 38 works since a Trust object "is-a" Account object.

    - Another static binding example:

        void display_account(const Account &acc) {
            acc.display();

            // will always use Account::display() regardless of what object is passed in, since they're all inherited from the
            // Account class object
        }

        Account a;
        display_account(a);     // ok

        Savings b;
        display_account(b);     // not what we expect

        Checking c;
        display_account(c);     // not what we expect

        Trust d;
        display_account(d);     // not what we expect

        - Since all of the objects ARE Account objects from inheritance, they all can be passed into the function, and since
            it's static binding the compiler will only see that they're all Account objects, and bind the 
            Account::display_account() function for the call.

    - Run-Time / Dynamic Polymorphism:

        Account *p = new Trust();
        p->withdraw(100);               // Trust::withdraw()

        - Here this time the withdraw method is a virtual method, this is the new change. We've opted into run-time polymorphism.
        - Virtual functions tells the compiler to not bind during compile-time, instead to deffer the binding of the function
            to run-time. At run-time a check will occur to see exactly what the pointer p is pointing to, and then that object's
            will be binded and then called.

    - Second example with new virtual function:

        virtual function void display_account(const Account &acc) {
            // will always use the display_account method depending on the object's type at RUN-TIME!
        }
*/


#include <iostream>


int main() {

    return 0;
}
