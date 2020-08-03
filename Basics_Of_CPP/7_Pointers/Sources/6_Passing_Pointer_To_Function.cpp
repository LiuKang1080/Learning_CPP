// Passing and Returning Pointers to and from Functions

/*
Passing Pointers to Functions:
    - Pass by reference with pointer parameters.
    - We can use pointers and the dereference operator to achieve pass by reference.
    - The function parameter is a pointer.
    - The actual parameter can be a pointer or an address of a variable.

*/


#include <iostream>


/* Function Prototypes */
void double_data(int *p_int);
// this function accepts a int pointer
// the * is not the dereference operator
// the pointer is passed by reference into the function


int main() {
    /* Pass By Reference | Passing Pointers into functions example */
    int value = 10;

    std::cout << "Value: " << value << "\n";
    double_data(&value);
    std::cout << "Value after double_data is called: " << value << "\n"; 

    std::cout << "========== \n";

    int *p_int = nullptr;
    p_int = &value;

    std::cout << "Value: " << value << "\t p_int: " << *p_int << "\n";
    double_data(p_int);
    std::cout << "Value after double_data: " << value << "\n"; 
    std::cout << "p_int after double_data: " << *p_int << "\n"; 

    return 0;
}


/* Function Definitions */
void double_data(int *p_int) {
    *p_int *= 2;
}
// this function accepts an int pointer
// *p_int the * is now used as the dereference operator
// *= is used as the compound multiplication operator
// do not confuse the different * uses
// accept a pointer called p_int --> derference p_int --> compound multiply by 2 
