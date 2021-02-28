// Copy, Move, and Assignment Operators with Inheritance in C++

/*
Copy / Move
    - Operators are NOT inherited from the base class.
    - You may not need to provide your own copy and move constructors. The compiler provided versions may work fine.
    - We can explicitly invoke the Base class' versions from the Derived class.

Copy Constructor
    - Can invoke the base constructor explicitly
    - Derived object "other" will be sliced

    Derived::Derived(const Derived &other)
        :Base(other), {Derived initialization list} {
        
        // code
    }
    
    - Inheritance "is-a" relationship, the Derived is a Base object. The compiler will perform slicing and slice off the base
        part, when we pass in / reference with &other.

    class Base {
        int value;
    
    public:
        // same constructors as previous example
        Base(const Base &other): value {other.value} {
            std::cout << "Base copy constructor" << "\n";
        }
    };

    - We technically don't even need this copy constructor at all, the compiler's auto generated one will work fine.
    - now we have the Derived class, derived from the Base class:

    class Derived: public Base {
        int doubled_value;
    
    public:
        // same constructors as before

        Derived(const Derived &other)
            :Base(other), doubled_value {other.doubled_value} {

            std::cout << "Derived copy constructor" << "\n";
        }
    };

    - This is the same for the Move constructor.

Overloaded Assignment (=) Operator:
    
    class Base {
        int value;
    
    public:
        // same constructors as previous example

        Base &operator=(const Base &rhs) {
            if (this != &rhs) {
                value = rhs.value;          // assign
            }

            return *this;
        }
    };

    - Now the Derived class that inherits the overloaded = assignment operator

    class Derived: public Base {
        int doubled_value;

    public:
        // same constructors as previous example

        Derived &operator=(const Derived &rhs) {
            if (this != &rhs) {
                Base::operator=(rhs);                   // assign Base part
                doubled_value = rhs.doubled_value
            }

            return *this;
        }
    };

    - It's very important that we first assign the Base part of the Derived object, and then take care of the Derived part.

Summary:
    - often you do NOT need to provide your own Copy / Move constructors or overloaded assignment = operator.
    - If you do NOT define them in the Derived class, then the compiler will create them and automatically call the Base class'
        version.
    - If you DO provide them, then you must invoke them explicitly yourself.
    - Be careful with raw pointers:
        - Especially if the Base and Derived each have a raw pointer.
        - Provide them with Deep Copy semantics.
*/


#include <iostream>


int main() {

    return 0;
}
