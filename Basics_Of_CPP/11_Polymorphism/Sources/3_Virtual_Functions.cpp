// Virtual Functions in C++

/*
Virtual Functions:
    - virtual keyword

    - Redefined functions are bound statically.
    - Overridden functions are bound dynamically.
    - Virtual functions are overridden.
    - Allows us to treat all objects generally as objects of the base class.

    - General syntax for declaring virtual functions:

    1) Declare the function you want to override as virtual in the Base class.
        - Virtual functions are virtual all the way down the hierarchy from this point.
        - Dynamic polymorphism only via Account class pointer or reference 

        class Account {
        public:
            virtual void withdraw(double amount);
            ...
        };

    2) Override the function in the Derived class 
        - Function signature and return type must match EXACTLY!
        - If we do not match the signature exactly, then the compiler will treat it as a redefinition and statically bind it.
        - virtual keyword is not required, but it's best practice to include it for the functions we're overriding.
        - If we do not provide an overridden version, then it is inherited from its Base class.

        class Checking: public Account {
        public:
            virtual void withdraw(double amount);
            ...
        };

        - Virtual functions are dynamically bound, only when we call them via a Base class pointer or reference. Other wise
            they're statically bound.

Virtual Destructors:
    - Whenever we have Virtual Functions, we must have virtual destructors!
    - Problems can happen when we destroy polymoprphic objects.
    - If a derived class is destroyed bhy deleting its storage via the base class pointer and the class a non-virtual destructor,
        then the behavior is undefined in the C++ standard.
    - Derived objects must be destroyed in the correct order starting at the correct destructor

    - Solution / Rule:
        - If a class has virtual functions, ALWAYS provide a public virtual destructor
        - If a Base class destructor is virtual, then all derived class' destructors are also virtual. We don't need to
            explicitly provide the virtual keyword, but it's best practice to add the virtual keyword.

    class Account {
    public:
        virtual void withdraw(double amount);
        virtual ~Account();
        ...
    };

    - ALWAYS provide virtual destructors, if we have virtual functions!

    - Virtual Constructors? They don't exist! They're not allowed in C++, they actually don't make sense either.
*/


#include <iostream>


// Base class and Derived classes WITHOUT virtual destructors
/*
class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "Account::withdraw()" << "\n";
    }
    
    ~Account() {
        std::cout << "Account::destructor()" << "\n";
    }
};

class Checking: public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "Checking::withdraw()" << "\n";
    }
    
    ~Checking() {
        std::cout << "Checking::destructor()" << "\n";
    }
};

class Savings: public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "Savings::withdraw()" << "\n";
    }
    
    ~Savings() {
        std::cout << "Savings::destructor()" << "\n";
    }
};

class Trust: public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "Trust::withdraw()" << "\n";
    }
    
    ~Trust() {
        std::cout << "Trust::destructor()" << "\n";
    }
};
*/

// Base class and Derived classes WITH virtual destructors:
class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "Account::withdraw()" << "\n";
    }
    
    virtual ~Account() {
        std::cout << "Account::destructor()" << "\n";
    }
};

class Checking: public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "Checking::withdraw()" << "\n";
    }
    
    virtual ~Checking() {
        std::cout << "Checking::destructor()" << "\n";
    }
};

class Savings: public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "Savings::withdraw()" << "\n";
    }
    
    virtual ~Savings() {
        std::cout << "Savings::destructor()" << "\n";
    }
};

class Trust: public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "Trust::withdraw()" << "\n";
    }
    
    virtual ~Trust() {
        std::cout << "Trust::destructor()" << "\n";
    }
};


int main() {
    std::cout << "=== Pointers ===" << "\n";
    Account *p1 = new Account();
    Account *p2 = new Checking();
    Account *p3 = new Savings();
    Account *p4 = new Trust();

    p1->withdraw(1000.00);
    p2->withdraw(1000.00);
    p3->withdraw(1000.00);
    p4->withdraw(1000.00);

    std::cout << "=== Delete Pointers ===" << "\n";
    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}

// Notice that if the destructors are not virtual, then only the Account::destructor gets called for ALL of the derived classes
// How can we be sure that the other derived objects are actually deleted on the heap? This is undefined behavior, and different
// compilers may produce different error messages.
// ALWAYS use virtual destructors if we use virtual functions!
