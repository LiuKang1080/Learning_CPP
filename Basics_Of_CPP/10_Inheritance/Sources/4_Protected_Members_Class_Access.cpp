// Protected Members and Class Access for the Inherited Class in C++

/*
Protected Members and Class Access:

Protected Class Member Modifier:

    class Base {
    protected:
        // protected Base class members...
    }; 

    - Accessible from the base class itself.
    - Accessible from classes Derived from Base.
    - NOT accessible by objects of base or Derived!

    class Base {
    public:
        // public Base class members 

    protected:
        // protected Base class members

    private:
        // private Base class members
    };

    - Since C++ provides 3 types of access for inheritance, it depends on the type of inheritance provided.

    1) Public Inheritance:

        Base Class:
            public: a
            protected: b 
            private: c

        Access in Derived Class:
            public: a
            protected: b
            c: No Access. c is inherited, but not accessible

        - This is the most common form of inheritance in C++

    2) Protected Inheritance:

        Base Class:
            public: a
            protected: b
            private: c

        Access in Derived Class:
            protected: a 
            protected: b 
            c: No Access. Not accessible from the derived class

    3) Private Inheritance:

        Base Class:
            public: a 
            protected: b
            private: c

        Access in Derived Class:
            private: a 
            private: b 
            c: No Access. Not accessible from the derived class

    - Generally we'll work with Public Inheritance.

    - Remember that the class member methods have full access to everything that is there in that class, regardless of the access
        specifier. The access specifier tells us how the inheritance will behave and what other classes have access to.

*/


#include <iostream>


// Base Class:
class Base {
    // note that friends of the class will have access to all
public:
    int a {0};
    
    void display() {
        std::cout << a << b << c << "\n";
    }
    
protected:
    int b {0};

private:
    int c {0};
};


// Derived Class:
class Derived: public Base {
    // note that friends of Derived have access to only what Derived has access to
    
    // a will be public
    // b will be protected
    // c will not be accessible. c is still inherited!

public:
    void access_base_members() {
        a = 100;        // OK
        b = 200;        // OK. protected in parent, and due to inheritance it is protected in this derived class
        // c = 300;     // Not Accessible!
    }

};


int main() {
    // create an object based on the Base class
    Base base_obj;

    // try accessing the different members
    base_obj.a = 100;   // OK
    // base_obj.b = 200;   // results in a compiler error
    // base_obj.c = 300;   // results in a compiler error

    // create an object based on the Derived class
    Derived derived_obj;

    // try accessing the different members
    derived_obj.a = 1000;       // since a is public in the Derived class, this is OK
    // derived_obj.b = 2000;    // the derived class does NOT have access to protected data, this will result in a compiler error
    // derived_obj.c = 3000;    // c is not accessible from the Derived Class, this will result in a compiler error

    return 0;
}
