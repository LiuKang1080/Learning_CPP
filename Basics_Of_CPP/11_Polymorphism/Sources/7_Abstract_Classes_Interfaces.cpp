// Abstract Classes as Interfaces in C++

/*
Abstract Classes as Interfaces:
    - An Abstract Class that has only pure virtual functions.
    - These functions provide a general set of services to the user of the class.
    - Provided as public.
    - Each subclass is free to implement these services as needed.
    - Every service (method) must be implemented
    - The service type information is strictly enforced

    - Unlike Java, C#, and other programming languages C++ does not provide true interfaces
    - We use Abstract Classes and pure virtual functions to achieve it.
    
    - ex) Suppose we want to be able to have Printable support for any object without knowing its implementation at compile time

        std::cout << any_object << "\n";

    - The Printable Interface is a serive that allows the classes that inherit from it to be printed into cout

        class Printable {
            friend ostream &operator<<(ostream &, const Printable &obj);
        
        public:
            virtual void print(ostream &os) const = 0;
            virtual ~Printable() {};
            ...
        }; 

        ostream &operator<<(ostream &os, const Printable &obj) {
            obj.print(os);
            return os;
        }

        - this is the << overloaded function
    
    - For any class to be printable it must be derived from Printable, and it MUST override the pure virtual functions.
    
        class Ay_Class: public Printable {
        public:
            // must override Printable::print() method
            virtual void print(ostream *os) override {
                os << "print() method is called from Any_Class \n";
            }
            ...
        };

        Any_Class *ptr = new Any_Class();
        std::cout << *ptr << "\n";          // *ptr is dereferencing the pointer

        void function1(Any_Class &obj) {
            std::cout << obj << "\n";
        }

        void function2(Printable &obj) {
            std::cout << obj << "\n";
        }

        function1(*ptr);                    // *ptr is dereferencing the pointer    "print() method is called from Any_Class"
        function2(*ptr);                    // *ptr is dereferencing the pointer    "print() method is called from Any_Class"

    - The Shape class from the file [6_Pure_Virtual_Functions.cpp] is also an Interface

        class Shape {
        public:
            virtual void draw() = 0;
            virtual void rotate() = 0;
            virtual ~Shape() {};
            ...
        };

    - In order to be a concrete class we must override the pure virtual functions. (We MUST override draw() and rotate() methods)

        class Circle: public Shape {
        public:
            virtual void draw() override {
                std::cout << "draw() method from the Circle class is called \n";
            }

            virtual void rotate() override {
                std::cout << rotate() method from the Circle class is called \n";
            }

            virtual ~Circle() {
                std::cout << "Circle destructor called \n";
            };
        };  

    - Generally we will see Interfaces Classes be named with a capital I ex) class I_Shape. It makes it easier to know that the
        class is intended to be used as an interface.

        class Circle: public I_Shape {

        };

    - This isn't a requirement, but this can be general coding practices.

        vector<I_Shape *> shapes;
        I_Shape *p1 = new Circle();
        I_Shape *p2 = new Square();

        for (auto const &shape: shapes) {
            shape->draw();
            shape->rotate();
        }

        // delete the pointers when we're done using them
*/


#include <iostream>


int main() {

    return 0;
}
