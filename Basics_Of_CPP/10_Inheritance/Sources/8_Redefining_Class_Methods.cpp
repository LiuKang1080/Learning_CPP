// Redefining Base Class Methods

/*
Redefining Base Class Methods:
    - Base class member functions are available to the Derived class. A Derived class can directly invoke Base class methods.
    - Derived class can override or redefine Base class methods.
    - Very powerful in the context of Polymorphism.

    ex) An Account class, with a deposit method. We also have a Savings_Account, it needs its own deposit method, but the
        behavior is different. We can override the Base class deposit method.

    class Account {
    public:
        void deposit(double amount) {
            balance += amount;
        }
    };

    class Savings_Account: public Account {
    public:
        void deposit(double amount) {       // redefine Base class method
            amount += some_interest;
            Account::deposit(amount);       // invoke call Base class method
        }
    };

    - It's important that we don't actually call and try to do the deposit in the Savings_Account method, Instead let the account
        class do what it knows how to do.

Static Binding:
    - Binding in which method to use is done at compile time.
        - Defualt binding for C++ is static.
        - Derived class objects will use Derived::deposit
        - But, we can explicitly invoke Base::deposit from Derived::deposit
        - This is ok, but limited. A much more powerful approach is dynamic binding.

    - This just means that the compiler determines which method to call, based on what it sees at compile time.
    - ex) If b is declared as a Base object, and we call b.deposit, then the compiler will call the base class' deposit method.
        If d is a Derived object, and d.deposit is called, then the Derived class' deposit method will be called.
    - There are times when we want the binding to take place at run-time.

Static Binding Method Calls:
    
    Base b;
    b.deposit(1000.0);              // Base::deposit

    Derived d;
    d.deposit(1000.0);              // Derived::deposit

    Base *ptr = new Derived();      // this is valid since Derived "is-a" Base
    ptr->deposit(1000.0);           // Base::deposit ???
                                    // it calls the Base method, since the compiler sees that ptr is pointer pointing to a Base
                                        class object

    - Remember that C++ uses Static Binding by default.
*/


#include <iostream>


int main() {

    return 0;
}
