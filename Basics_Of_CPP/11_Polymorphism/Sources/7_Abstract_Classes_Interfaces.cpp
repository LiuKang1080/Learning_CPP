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


// A Generic Printable Interface that prints out any object:
// Printable Interface
class I_Printable {
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);

public:
    virtual void print(std::ostream &os) const = 0;
    virtual ~I_Printable() = default;
    // the I_Printable destructor, we can say = defualt, to tell the compiler to auto generate a simple defualted destructor
};

// implement the friend method
std::ostream &operator<<(std::ostream &os, const I_Printable &obj) {
    obj.print(os);
    return os;
}

// now all of the account types inherits from the I_Printable interface, and they MUST implement the print function
// Account Class
class Account: public I_Printable {
public:
    virtual void withdraw(double amount) {
        std::cout << "Account::withdraw() method is called \n";
    }

    // override the pure virtual function from I_Printable
    virtual void print(std::ostream &os) const override {
        os << "Account Display \n";
    }

    virtual ~Account() {
        std::cout << "Account destructor called \n";
    }
};

// Checking Class
class Checking: public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "Checking::withdraw() method is called \n";
    }

    // override the virtual function from Account, we MUST override this and implement the specific method in this class!
    virtual void print(std::ostream &os) const override {
        os << "Checking Display \n";
    }

    virtual ~Checking() {
        std::cout << "Checking destructor called \n";
    }
};

class Savings: public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "Savings::withdraw() method is called \n";
    }

    // override the virtual function from Account
    virtual void print(std::ostream &os) const override {
        os << "Savings Display \n";
    }

    virtual ~Savings() {
        std::cout << "Savings destructor called \n";
    }
};

class Trust: public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "Trust::withdraw() method is called \n";
    }

    // override the virtual function from Account
    virtual void print(std::ostream &os) const override {
        os << "Trust Display \n";
    }

    virtual ~Trust() {
        std::cout << "Trust destructor called \n";
    }
}; 

// A "Dog" class that wants to be printable
class Dog: public I_Printable {
public:
    virtual void print(std::ostream &os) const override {
        os << "Dog Class Displayed \n";
    }
};

// we can take this 1 step further, we can create a generic C++ function that takes in ANYTHING (as long as it is inherited in 
// some way from I_Printable) and prints it out
void print(const I_Printable &obj) {
    std::cout << obj << "\n";
}


int main() {

    // Account and Checking pointers
    Account *p1 = new Account();
    Account *p2 = new Checking();

    std::cout << *p1 << "\n";
    std::cout << *p2 << "\n";

    // create a dog class
    Dog *dog = new Dog();
    std::cout << *dog << "\n";

    // delete pointers when we're done with them
    delete p1;
    delete p2;
    delete dog;

    return 0;
}
