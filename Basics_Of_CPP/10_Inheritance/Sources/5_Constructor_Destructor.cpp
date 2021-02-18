// Constructors and Destructors for Inheritance In C++

/*
Constructors and Destructors:
    - Derived class inherits data from Base class.
    - The Base class of the Derived class MUST be initialized BEFORE the derived class is initialized.
    - When a Derived object is created:
        - Base class constructor executes and then...
        - Derived class constructor executes

Constructors and Class Initialization:
    
    class Base {
    public:
        // no args constructor
        Base() {
            std::cout << "Base constructor" << "\n";
        }
    };

    class Derived: public Base {
    public:
        // no args constructor
        Derived() {
            std::cout << "Derived constructor" << "\n"
        }
    };

    - now we create base and derived class objects to see how the constructors are called.

    Base base_object;           // "Base constructor"

    Derived derived_object;     // "Base Constructor"
                                // "Derived constructor"

    - For the derived_object, both of the constructors get called, notice the order that they get called in. Base gets called
        first, and then the derived constructor gets called.

Destructors:
    - Class destructors are invoked in the reverse order as constructors.
    - The derived part of the Derived class MUST be destroyed BEFORE the Base class destructor is invoked.
    - When a Derived object is destroyed:
        - Derived class destructor executes and then...
        - Base class destructor executes.

        - Each destructor should free resources allowed in its own constructors

    class Base {
    public:
        //constructor
        Base() {
            std::cout << "Base constructor" << "\n";
        }

        // destructor
        ~Base() {
            std::cout << "Base destructor" << "\n";
        }
    };

    class Derived: public Base {
    public:
        // constructor
        Derived() {
            std::cout << "Derived constructor" << "\n";
        }

        // destructor
        ~Derived() {
            std::cout << "Derived destructor" << "\n";
        }
    };

    - now we can create Base and Derived objects to see what the constructor and destrucor outputs

    Base base_object;           // "Base constructor"
                                // "Base destructor"

    Derived derived_object      // "Base constructor"
                                // "Derived constructor"
                                // "Derived destructor"
                                // "Base destructor"

    - A Derived class does NOT inherit:
        - A Base class constructor
        - Base class destructor
        - Base class overloaded assignment operators
        - Base class friend functions

    - However, the base class constructors, destructors, and overloaded assignment operators can invoke the base_class versions.
    - C++11 allows explicit inheritance of base "non-special" constructors with:
        - using Base::Base anywhere in the derived class declaration. Here using is the keyword
            - By using this allows up to explicit inheritance of base class constructors.
        - Lots of rules involved, often better to define the constructors yourself.
*/


#include <iostream>


int main() {

    return 0;
}
