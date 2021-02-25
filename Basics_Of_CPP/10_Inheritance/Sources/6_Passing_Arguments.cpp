// Passing Arguments to Base Class Constructors

/*
Passing Arguemnts to Base Class Constructors:
    - The base part of a derived class must be initialized first
    - How can we control exactly which base class constructor is used during initialization?
    - We can invoke whichever Base class constructor we wish in the initialization list of the Derived class

        class Base {
        public:
            Base();
            Base(int x);
            ...
        };

        Derived::Derived(int x)
            :Base(x), {optional initialization for Derived} {
            // code
        }

    - In this case, we're passing the int x into the Base class when it's invoked.
    - The //code executes AFTER the Base, and Derived sections have BOTH been initialized.
    - If the Base overloaded args constructor is not explicitly called, then the no-args constructor will automatically be called.

    - ex)

        class Base{
            int value;
        
        public:
            Base(): value{0} {      // initializes the variable value to 0
                std::cout << "Base no-args constructor" << "\n";
            }

            Base(int x): value{x} {     // initializes the variable value to x 
                std::cout << "int Base constructor" << "\n";
            }
        };

        class Derived: public Base {
            int doubled_value;

        public:
            Derived(): Base{}, doubled_value{0} {
                std::cout << "Derived no-args constructor" << "\n";
            }

            Derived(int x): Base{x}, doubled_value{x*2} {
                std::cout << "int Derived constructor" << "\n";
            }
        };

    - We can create Base and Derived objects to see how they behave:
    Base object_base;               // Base no-args constructor
    
    Base object_base{100};          // int Base constructor

    Derived object_derived;         // Base no-args constructor
                                    // Derived no-args constructor

    Derived object_derived{100};    // int Base constructor
                                    // int Derived constructor
*/


#include <iostream>


// Base class
class Base{
private:
    int value;

public:
    // no-args constructor
    Base(): value{0} {
        std::cout << "Base no-args constructor" << "\n";
    }

    // int args constructor
    Base(int x): value{x} {
        std::cout << "Base(int) overloaded constructor" << "\n";
    }

    // destructor
    ~Base() {
        std::cout << "Base destructor" << "\n";
    }
};


// Derived class
class Derived: public Base {
private:
    int doubled_value;

public:
    // no-args constructor
    Derived(): Base(), doubled_value{0} {
        std::cout << "Derived no-args constructor" << "\n";
    }

    // int args constructor
    Derived(int x): Base(x), doubled_value{x*2} {
        std::cout << "Derived(int) overloaded constructor" << "\n";
    }

    // destructor
    ~Derived() {
        std::cout << "Derived destructor" << "\n";
    }
};


int main() {
    // create Derived object
    Derived derived_object{1000};

    return 0;
}
