// Operator Overloading in C++

/*
Operator Overloading:
    - C++ allows overloading of most operators to work with our user defined classes. Intended to make code more readable, and
        writable.
    
    - What is Operator Overloading?
        - Traditional operators like +, -, *, / can be used with user defined types.
        - Allows user defined types to behave similar to built-in types.

    - The assignment operator ( = ) is overloaded for us automatically by the compiler. Has defualt operator overloading. We must
        explicitly define the other operators for overloading.

    - What operators can be overloaded?
        - Scope Resolution Operator     ::
        - Conditional Operator          :?
        - Pointer to member operator    .*
        - Dot Operator                  .
        - Sizeof Operator               sizeof

    - Just because an operator can be overloaded doesn't mean it should. We should only do it when it makes sense.

Basic Rules of Operator Overloading:
    - Precedence and Associativity cannot be changed.
    - 'arity' cannot be changed. (ex cannot make the division operator a unary operator).
    - Cannot overload operators for primitive data types (ex int, double, float etc).
    - Cannot create new operators 
    - [], (), ->, and the assignment operator ( = ) MUST be declared as member methods.
    - Other operators can be declared as member methods or as global functions.

    - We will be working with a Mystring class, and overloading the operators in the clas:

        =====
        Mystring.h
        =====

        #ifndef _MYSTRING_H_
        #define _MYSTRING_H_

        class Mystring {
        private:
            char *str;

        public:
            Mystring();                         // no args constructor
            Mystring(const char *str);          // C-style string / literal constructor
            Mystring(const Mystring &source);   // copy constructor
            ~Mystring();                        // destructor

            void display() const;               // display method
            int get_length() const;             // getter method: gets length of string
            const char *get_str() const;        // getter method: gets string
        };

        #endif  // _MYSTRING_H_

        =====
        Mystring.cpp
        =====

        #include <iostream>
        #include <cstring>

        #include "Mystring.h"


        // no args constructor
        Mystring::Mystring() 
            : str {nullptr} {
            
            str = new char[1];
            *str = "\0";
        }

        // overloaded constructor
        Mystring::Mystring(const char *s)
            : str {nullptr} {
            
            if (s == nullptr) {
                str = new char[1];
                *str = "\0";
            } else {
                str = new char[std::strlen(s) + 1];
                std::strcpy(str, s);
            }
        }

        // copy constructor
        Mystring::Mystring(const Mystring &source)
            : str{nullptr} {

            str = new char[std::strlen(source.str) + 1];
            std::strcpy(str, source.str);
        }

        // destructor
        Mystring::~Mystring() {
            delete [] str;
        }

        // display method
        void Mystring::display() const {
            std::cout << str << "\n";
        }

        // length getter method
        int Mystring::get_length() const {
            return std::strlen(str);
        }

        // string getter method
        const char *Mystring::get_str() const {
            return str;
        }
*/


#include <iostream>


int main() {

    return 0;
}
