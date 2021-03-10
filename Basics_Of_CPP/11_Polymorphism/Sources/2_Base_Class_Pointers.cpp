// Base Class Pointers with Polymorphism in C++

/*
Dynamic Polymorphism:
    - For dynamic polymorphism we must have:
        - Inheritance
        - Base class pointers or Base class references
        - Virtual Functions

    - For the examples below we assume that virtual functions are enabled for the methods in all of the classes, and that dynamic
        polymorphism is being used. We will learn about virtual functions later.

    - Using Base class pointers:

    Account *p1 = new Account()
    Account *p2 = new Savings()
    Account *p3 = new Checking()
    Account *p4 = new Trust()

    p1->withdraw(100)       // Account::withdraw()
    p2->withdraw(100)       // Savings::withdraw()
    p3->withdraw(100)       // Checking::withdraw()
    p4->withdraw(100)       // Trust::withdraw()

    - When we call these withdraw methods they will use the specific withdraw methods from those specific classes, due to dynamic
        polymorphism.

    Account *array[] = {p1, p2, p3, p4};
    // an array holding pointers to objects of the type Account, since all of the classes above are Account types objects they
    // can be stored in the array

    for (auto i=0; i<4; ++i) {
        array[i]->withdraw(1000);
    }
    // with the power of dynamic polymorphism we can store as many Account type objects, and use looping techniques to perform
    // actions on the objects

    // remember to delete the pointers when we're done using them!

    - Here the correct withdraw method will be called based on the specific object the pointer is pointing to in that iteration.
    - This is very powerful, it doesn't matter how many elements there are in the array, and it doesn't matter if we replace,
        or create new Account type objects, the for loop doesn't need to be changed if the Account type objects change.
    - We can also use other collections like a vector

    vector<Account *>accounts {p1, p2, p3, p4};

    // range based for loop, looping through the entire accounts vector
    for (auto acc_ptr: accounts) {
        acc_ptr->withdraw(100);
    }

    // delete pointers!

    - If we add another Account class, this will automatically work in the for loop due to dynamic polymorphism.
    - We need to becareful with using raw pointers with vectors, use smart pointers instead! We will cover smart pointers in a
        later section.

    - By enabling Virtual Functions, we can get this type of power, and generalize more of our programming. Rather than worrying
        about which specific method is being called for the specific function, we let the compiler assign them during run-time.

    - We will look at creating virtual functions in the next section.
*/


#include <iostream>


int main() {

    return 0;
}
