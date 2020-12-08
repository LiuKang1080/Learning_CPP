// Overloading the Assignment Operator in C++

/*
Overloading the Assignment Operator (Copy Assignment Operator)
    - C++ provides a defualt assignment operator used for assigning one object to another.
    
        Mystring s1 {"Bob"};
        Mystring s2 = s1;       
        // this is not assignment! This is the same as Mystring s2 {s1}; This is actually initialization since s2 hasn't been
            created yet.

        s2 = s1;
        // This is assignment, since s2 has already been created in the previous statement

    - Defualt copy is member wise copy.
    - If we have a raw pointer data member, we must perform deep copying.
    - Do not confuse assignment with initialization. Initialization is done by constructors when we create new objects.
    - We need to overload the copy assignment operator:
    - General Syntax:

        Type &Type::operator=(const Type &rhs);        

        Mystring &Mystring::operator=(const Mystring &rhs);

    - operator=     the keyword operator and then the operator we wish to overload.
    - with the assignment operator overloading we can write s2 = s1; Behind the scenes the compiler will generate code that takes
        the form s2.operator=(s1); 

    - Overloading the copy assignment operator (deep copy):

        Mystring &Mystring::operator=(const Mystring &rhs) {
            if (this == &rhs) {
                return *this;
            }

            delete[] str;
            str = new char[std::strlen(rhs.str + 1)];
            std::strcpy(str, rhs.str);

            return *this;
        }

    - Remember that the object on the LHS of an assignment statement is refered to by the "this" pointer, and the object on the
        RHS is being passed into by the method.
    - When we do the copy, the "this" pointer (LHS) will be overwritten, we need to deallocate anything that the LHS points to 
        on the heap, then allocate new space on the LHS for the RHS' object's data, then we fully copy the data over to the LHS
        from the RHS.

    - Let's break down what the above function is doing:

    Step 1: Check to see if we're doing a self assignment

        if (this == &rhs) {     // p1 = p1;
            return *this;       // return current object
        }

        - We can check to see if p1 = p1 by checking the address of the LHS, which is in the "this" pointer, and comparing it
            to the address of the RHS object. If they're the same, then dereference and return the LHS object.
        
    Step 2: Deallocate storage

        delete[] str;

        - If we don't have self assignment, then we need to deallocate storage for this string since its pointing to a string
            on the heap. We need to decallocate otherwise when we copy over the new data over, we will orphan this section of 
            memory and this will lead memory leaks.

    Step 3: Allocate new storage

        str = new char[std::strlen(rhs.str) + 1];

        - Now the LHS object is ready to be assigned from the data of the RHS object, but we haven't yet allocated storage on
            the heap for the deep copy. We need to allocate storage, the size of the string of the RHS object + 1 (We need the
            +1 for the NULL Terminator)

    Step 4: Perform the copy

        std::strcpy(str, rhs.str);

        - Now we can perform the copy. We can perform the copy by copying 1 character at a time until we reach the NULL Terminator
            OR we can use the std::strcpy() function which performs the complete copy for us.

    Step 5: Return the LHS object

        return *this;

        - Now we can return the LHS object after the copying is done. Return the current object by reference to allow chain
            assignment.

        s1 = s2 = s3;

Overloading the Assignment Operator (Move)
    - Generally the Overloading of the Assignment Operator (Move) declaration will be the header file, and the actual definition
        will be in the .cpp file (NOT main.cpp!)
    - We can choose to overload the move assignment operator, C++ will use the copy assignment operator if necessary,

        Mystring s1;
        s1 = Mystring {"bob"};      // Move assignment

    - If we have a raw pointer, we should overload the assignment operator for efficiency.
    - The copy assignment operator works with L-Value references, the Move Operator that we will overload works with R-Value 
        references (think temporary, un-named objects).

    - Overload the Move Assignment Operator: The declaration is very similar to the Copy Assignment

        Type &Type::operator=(Type &&rhs);

        // tell the compiler that the right side object is an r-value reference. cannot be const, since we will by modifying that
        object when we move the data

        Mystring &Mystring::operator=(Mystring &&rhs);

        s1 = Mystring("Joe");       // Move operator= called
        s1 = "Bob";                 // Move operator= called

    - Full definition:

        Mystring &Mystring::operator=(Mystring &&rhs) {
            if (this == &rhs) {     // self assignment
                return *rhs;        // return current object
            }

            delete[] str;           // deallocate current storage
            str = rhs.str;          // steal the pointer

            rhs.str = nullptr;      // NULL out the rhs object
            return *this;           // return the current object
        }

    - We are not deep copying the data, we're stealing the pointer and then NULL-ing out the rhs pointer.

    - Steps for Overloading the Move Assignment Operator:
    - Step 1: Check for self assignment:

        if (this == &rhs) {
            return *this;       // return the current object
        } 

        - If we self assign, then we will just return the LHS and we're done.

    - Step 2: deallocate storage for this->str

        delete[] str;

        - If we're not self assigning, then we decallocate the storage that is pointed to by the LHS object since we're overriding
            this, and we do not want a memory leak. Now the LHS object is ready, so now we can move the pointer over.

    - Step 3: Steal the Pointer from the RHS object and assign it to this->str

        str = rhs.str;
        
        - Copy of a pointer variable, we're not doing a deep copy here.

    - Step 4: NULL out the RHS pointer

        rhs.str = nullptr;

        - This step is critical!

    - Step 5: Return the current object by reference to allow chain assignment

        return *this;
*/


#include <iostream>


int main() {

    return 0;
}
