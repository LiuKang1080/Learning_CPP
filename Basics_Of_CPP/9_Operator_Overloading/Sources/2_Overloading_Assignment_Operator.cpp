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
*/


#include <iostream>


int main() {

    return 0;
}
