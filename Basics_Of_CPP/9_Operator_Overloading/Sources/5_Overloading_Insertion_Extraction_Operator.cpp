// Overloading the Insertion and Extraction Operators in C++

/*
Overloading the Insertion and Extraction Operators:
    - We can overload the Insertion and extraction operators so that they behave like built in functions.

        Mystring larry {"Larry"};
        cout << larry << "\n";          // prints out Larry. The object itself into cout will print out Larry the string

        Player hero {"Hero". 100, 50};
        cout << hero << "\n";           // {name: Hero, health:100, xp:50}

    - Generally it doesn't make sense to implement the insertion / extraction operators as member methods.
        - Left operand must be a user defined class.
        - Not the way we normally use these operators.

        Mystring larry;
        larry << cout;      // this doesn't make sense 

        Player hero;
        hero << cout;       // this doesn't make sense 

    - We need to overload these operators as non-member functions.

Overloading the Stream Insertion Operator ( << )
    
    std::ostream &operator<<(std::ostream &os, const Mystring &obj) {
        os << obj.str;              // if friend function
        // os << obj.get_str()      // if not friend function
        return os;
    }

    - The first parameter is output stream object by reference.
    - The second parameter is a reference to Mystring object whose data we want to insert into the output stream.
    - Return a reference to the ostream so we can keep chain inserting.
    - !!! Do NOT return ostream by value !!!

Overloading Stream Extraction Operator ( >> )
    
    std::istream &operator>>(std::istream &is, Mystring &obj) {
        char *buff = new char[1000];
        is >> buff;
        obj = Mystring {buff};      // if you have copy or move assignment
        delete[] buff;
        return is;
    }

    - The first parameter is a reference to input stream whose type is istream.
    - the second parameter is a reference to the object we want to extract data into. We want modify the object, so no const!

    - Return a refernece to the istream so we can keep chain extracting.
    - Update the object passed in.
*/


#include <iostream>


int main() {

    return 0;
}
