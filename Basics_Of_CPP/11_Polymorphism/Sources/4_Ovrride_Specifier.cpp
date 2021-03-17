// The Override Specifier in C++

/*
The Override Specifier:
    - We can override Base class virtual functions
    - The function signature and return MUST be EXACTLY the same!
    - If they are different, then we have redefinition NOT overriding
    - Redefinition is statically bound
    - Overriding is dynamically bound
    - C++11 provides an override specifier to have the compiler ensure overriding.

    class Base {
    public:
        virtual void say_hello() const {
            std::cout << "Base class object \n";
        }

        virtual ~Base() {}
    };

    class Derived: public Base {
    public:
        virtual void say_hello() {                      // notice the const is missing! This is NOT overriding!
            std::cout << "Derived class object \n";
        }

        virtual ~Derived() {}
    };

    Base:
        virtual void say_hello() const;
    
    Derived:
        virtual void say_hello();           // this will be statically bound, not dynamically bound

    Base *p1 = new Base();
    p1->say_hello();            // "Base class object"

    Base *p2 = new Derived();
    p2->say_hello();            // "Base class object"

    - This is not what we expect
    - say_hello method signatures are different
    - so derived redefines say_hello instead of overriding it!

    - We can use the Override Specifier:

    class Derived: public Base {
    public:
        virtual void say_hello() override {             // produces compiler error. Error: marked override, but does not override
            std::cout << "Derived class object \n";     // This error is a soft error telling us that we're missing the const!
        }

        virtual ~Derived() {}
    };

    - by using the override specifier keyword, we ensure that the compiler will check for us and ensure that we will actually
        override the method that we want. 

The Final Specifier:
    - There are 2 contexts regarding the final specifier:

        1) The Class Level:
            - Prevents a class from being derived from.

        2) The Method Level: 
            - Prevents a virtual method from being overridden in a derived class.

    - Geerlly these specifiers are used to for better compiler optimazation.
    - General Syntax:

        class my_class final {
            ... 
        };

        class Derived final: public Base {
            ...
        };

    - In these examples, my_class cannot be derived from, and the Derived class cannot be derived from. We will get a compiler
        error if we try to do so.

    Method Examples:

        class A {
        public:
            virtual void do_something();
        };

        class B: public A {
        public:
            virtual void do_something() final;          // prevents further overridding
        };

        class C: public B {
        public:
            virtual void do_something();                // compiler error: Cannot override due to final specifier from class B
        };
*/


#include <iostream>


int main () {

    return 0;
}
