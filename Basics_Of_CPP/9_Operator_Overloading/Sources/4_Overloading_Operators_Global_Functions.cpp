// Overloading Operators using Global Functions in C++

/*
Overloading Operators as Global Functions (also called non-member functions)
    - Since these are Global Functions, we no longer have a "this" pointer reffering to the object on the LHS.
    - Since we need to access the attributes, usually these Global Functions are declared as friends to the class. It's not 
        required since we can still use getters / setters methods.
    
    - Unary Operators:
        - A single object is required in the parameter list
    - Binary Operators
        - We will need to have 2 objects in the parameter list 
    - ex)

        Number operator-(cont Number &obj);
        Number operator++(Number &obj);         // pre-increment
        Number operator++(Number &obj, int);    // post-increment
        bool operator!(cont Number &obj);

        Number n1 {100};
        Number n2 = -n1;        // operator-(n1)
        n2 = ++n1;              // operator++(n1)
        n2 = n1++;              // operator++(n1, int)

Implementing the operator-:
    - Often declared as friend functions in the class declaration

        Mystring operator-(const Mystring &obj) {
            char *buff = new char[std::strlen(obj.str) + 1];
            std::strcpy(buff, obj.str);
            for (size_t i=0; i<std::strlen(buff); i++) {
                buff[i] = std::tolower(buff[i]);
            }

            Mystring temp {buff};
            delete[] buff;
            return temp;
        }

    - the &obj is a Mystring object reference.
    - You cannot have BOTH the member method AND the Global Function, this will result in a compiler error!
    - Binary operators are essentially the same, except with 2 arguments
    - The first argument is the LHS, and the 2nd argument is the RHS object.
    - General Syntax:

        ReturnType operatorOp(const &Type LHS, const &Type RHS);

    - ex)

        Number operator+(const &Number lhs, const &Number rhs);
        Number operator-(const &Number lhs, const &Number rhs);
        Number operator==(const &Number lhs, const &Number rhs);
        Number operator<(const &Number lhs, const &Number rhs);

        Number n1 {100}, n2 {200};      
        Number n3 = n1 + n2;        // operator+(n1, n2)
        n3 = n1 - n2;               // operator-(n1, n2)
        if (n1 == n2) ...           // operator==(n1, n2)

Overloading the == Operator with Global Functions:
    
    bool operator==(const Mystring &lhs, const Mystring &rhs) {
        if (std::strcomp(lhs.str, rhs.str) == 0) {
            return true;
        } else {
            return false;
        }
    }

    - If declared as a friend of Mystring, it can then access private str attributes, otherwise we must use getters / setters
        methods.

Overloading the Binary + Operator (concatenation):

    Mystring larry {"Larry"};
    Mystring stooges {" is one of the 3 stooges"};

    Mystring result = larry + stooges;      // operator+(larry, stooges);
    result = "Moe" + stooges;               // OK, with non-member functions

    - Each of the Global Functions expect 2 arguments, and are called with 2 arguments.
    - These functions accept 2 Mystring types, or 1 Mystring type, BUT NOT 2 string literals (this will result in an error)

    - Implementation of the Binary + Operator:

    Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
        size_t buff_siz = (std::strlen(lhs.str) + std::strlen(rhs.str)) + 1;
        char *buff = new char[buff_size];
        std::strcpy(buff, lhs.str);
        std::strat(buff, rhs.str);
        Mystring temp {buff};
        delete[] buff;
        return temp;
    }

    - Instead of using the "this" pointer, we now use the lhs parameter / argument.
*/


#include <iostream>


int main() {
    
    return 0;
}
