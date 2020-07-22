// Pointer Basics in C++

/*
Pointers:
    - A Pointer is a variable whose value is a memory address.
    - The address can be to a variable or a function.
    - To use the data that the pointer is pointing to, we must know its data type. 
        - If x is a variable of type int with a value of 10, A pointer pointing to it must of the type int.

    - Why use pointers? 
        - Why not just call the variables or functions directly? We can not always do this. ex) Inside functions pointers can
            can be used to access data that is defined outside of the function. Those variables may not always be in scope, so
            we cannot access them directly by name.
        - Pointers can be used to operate on arrays efficiently.
        - We can dynamically allocate memory on the heap or free store.
            - This memory doesn't have a variable name.
            - The only way to access this memory is through a pointer.
        - With OOP pointers are how polymorphism works.
        - With pointers we can access specific memory addresses.
            - Useful in embedded and systems applications.

Declaring Pointers:
    - General Syntax:

        variable_type *pointer_name;

    ex) 

        int *int_ptr;
        double* double_ptr;
        char *char_ptr;

        - We read this right to left. int_ptr is a pointer pointing to an int data type.
        - the * can be to the left or the right side, the compiler does not care. Pick a convention and stick with it.

    - These pointers in the example are un-initialized, they are pointing to garbage data.
    - In C++ ALWAYS initialize pointers before using them!

    - nullptr (The NULL pointer) introduced in C++11. Initializing pointer variables to 'point nowhere'.
    - General Syntax:
    
        variable_type *pointer_name {nullptr};

    - If you do not initialize a pointer to point to a variable or a function, then we should ALWAYS initialize it to nullptr
        to 'make it null'.

Accessing Pointer Addesses / Storing Addresses in Pointers:
    - The Address Of Operator: & 
        - Variables are stored in unique addresses in memory.
        - & is a unary operator, evaluates to the address of its operand.
        - The operand cannot be a constant or an expression that evaluates to temp values.

        int num = 10;
        std::cout << num << "\n";
        std::cout << &num << "\n";      // this is given as a hexadecimal value

    - Addresses of pointer variables, we use the & operator.
    - sizeof() operator on pointers:
        - Don't confuse the size of a pointer and the size of what it is pointing to.
        - ALL pointers in a program are the same size regardless of what it is pointing to.
        
    - Pointers in C++ are typed pointers. The compiler will make sure that the address stored in a pointer variable is of the 
        correct type.

        int score = 10;
        double high_temp = 100.00;

        int *p_score = nullptr;         // ok
        p_score = &score;               // ok
        p_score = &high_temp            // compiler error. An int pointer trying to point to a double data type.

Void Pointer:
    - The void pointer, generally is not used in C++. They are more used in C.
*/


#include <iostream>


int main() {

    // uninitialized pointer
    int *p;
    std::cout << "Value of pointer: " << p << "\n";         // garbage
    std::cout << "Address of pointer: " << &p << "\n";      // address of the pointer

    // set pointer to NULL
    p = nullptr;                
    std::cout << "Value of pointer after setting to NULL: " << p << "\n";   // 0

    return 0;
}
