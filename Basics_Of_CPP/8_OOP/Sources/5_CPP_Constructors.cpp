// Advanced Topics of the C++ Constructor

/*
Default Constructor
    - Does not take any arguments. Also called the no-args constructor.
    - If we do not provide a defualt constructor, then C++ will generate a defualt constructor that does nothing.
    - The defualt constructor is called when you initialize a new object with no arguments.
    
    - ex) 

        public: 
            Account() {
                name = "None";
                balance = 0.00;
            }

    - Now we can make a constructor that takes in arguments:

        public:
            Account(std::string name_val, double bal) {
                name = name_val;
                balance = bal;
            }

    - Once a constructor is defined for the class, C++ will NOT generate a defualt constructor. If we need to use a defualt
        constructor then we need to manually define the defualt constructor along with the other constructors. 
*/


#include <iostream>


int main() {

    return 0;
}
