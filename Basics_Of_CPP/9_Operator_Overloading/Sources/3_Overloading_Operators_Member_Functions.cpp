// Overloading Operators as Member Functions

/*
Overloading Operators as Member Functions:
Unary Operator Overloading:
    - C++ allows unary, and binary operators to be overloaded as well.
    - General Syntax for Unary Operator Overloading

        ReturnType Type::operatorOp();

    ex)

        Number Number::operator-() const;
        Number Number::operator++();        // pre-increment
        Number Number::operator++(int);     // post-increment
        bool Number::operator!() const;

        Number n1 {100};
        Number n2 = -n1;        // n1.operator-()
        n2 = ++n1;              // n1.operator()
        n2 = n1++               // n1.operator++(int)

    - C++ allows overloading operators as member functions or global functions.
        - The defualt return method is returning objects by value.

    - Unary member methods overloading have empty parameter lists, because the object we're working with is reffered to by the 
        this pointer.

    ex) Mystring operator- overloading to make string lowercase

        Mystring larry1 {"LARRY"};
        Mystring larry2;

        larry1.display();       // LARRY
        larry2 = -larry1;       // larry1.operator-()

        larry1.display();       // LARRY
        larry2.display();       // larry

        - Does this make sense? Maybe, this depends on the implementation, and what the design requires.

        Mystring Mystring::operator-() const {
            char *buff = new char[std::strlen(str) + 1];
            std::strcpy(buff, str);

            for (size_t i=0; i<std::strlen(buff); i++) {
                buff[i] = std::tolower(buff[i]);
            }
        }

Binary Operator Overloading (+, -, ==, !=, <, >, etc):
    - Gneral Syntax:

        ReturnType Type::operatorOp(const &Type rhs);

        Number Number::operator+(const &Number rhs) const;
        Number Number::operator-(const &Number rhs) const;
        Number Number::operator==(const &Number rhs) const;
        Number Number::operator<(const &Number rhs) const;

        Number n1 {100}, n2 {200};
        Number n3 = n1 + n2;        // n1.operator+(n2)
        n3 = n1 - n2;               // n1.operator-(n2)
        if (n1 == n2)...            // n1.operator==(n2)

    - Binary operator overloading has a single paramemter in the paramemeter list.

    - Overloading the == operator for the Mystring class:

        bool Mystring::operator==(const Mystring &rhs) const {
            if (std::strcmp(str, rhs.str) == 0) {
                return true;
            } else {
                return false;
            }
        } 

        if (s1 == s2)       // if this is true, then s1 and s2 are Mystring objects

    - Overloading the binary + operator for the Mystring class. This form takes on concatenation:

        Mystring larry {"Larry"};
        Mystring stooges {" is one of the Stooges."};
        Mystring result = larry + stooges;      // larry.operator+(stooges);

        result = "Moe" + stooges;       // ERROR, this will result in an error!

        - The object on the LHS MUST be an object of the class you're using!
        - Implementation of the + overloading method:

        Mystring Mystring::operator+(const Mystring &rhs) const {
            size_t buff_size = (std::strlen(str) + std::strlen(rhs.str)) + 1;
            char *buff = new char[buff_size];

            std::strcpy(buff, str);
            std::strcat(buff, rhs.str);

            Mystring temp(buff);
            delete[] buff;
            return temp;
        }
*/


#include <iostream>


int main() {

    return 0;
}
