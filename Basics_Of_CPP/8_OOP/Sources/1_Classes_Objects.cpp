// Object Oriented Programming in C++
// Classes and Objects in C++

/*
Object Oriented Programming
    - Focus on classes (that model the real-world entities).
    - Higher levels of abstraction.
    
    - Encapsulation:
        - Objects that contain data AND operations that work on that data (abstract data types).
        - Information hiding
            - Specific logic can be hidden. 
            - Users of the class don't need to know the implementation. 
            - Another layer of abstraction.

    - Reusability:
        - Easier to reuse classes in other applications.
        - Easier to test for bugs. Testing on classes rather than whole programs from procedural programming.

    - Inheritance:
        - Can create new classes from existing classes.
        - Polymorphic Classes.

    - When Not To Use OOP:
        - OOP is not for every problem / program.
        - OOP does not fix bad code.
        - Not all problems can be decomposed into classes or objects.
        - C++ programs that contain OOP classes / objects will generally be larger in size, slower to run, and are more complex.
        - Small programs / easy programs: OOP might not be the best method of development, and procedural programming might be
            better.

Classes And Objects:
    - Classes:
        - Blueprint from which objects are created.
        - User definied data types.
        - Has attributes (data)
        - Has methods (functions)
        - Can hide the attributes and methods.
        - Provides a public interface.

    Objects:
        - Created from classes.
        - Represents a specific instance of a class.
        - We can create as many objects we want.
        - Each object has its own identity
        - Each object can use the methods definied in the class.

            int high_score;             // int is a primitive data type, it is NOT a class. It can thought of a class, and the
            int low_score;              // scores are instances of the class int

            Account bob_account;        // class and object 
            Account alice_account;

            std::vector<int> scores;    // class and object
            std::string name;

Declaring a Class and Creating Objects:
    - General syntax:

        class Class_Name {
            declaration(s);
        };

    - Best programming practice is to capitalize the class name.
    - Do not forget the trailing semi-colon ; after the braces { }.

        class Player {
            // attributes
            std::string name;
            int health;
            int xp;

            // methods
            void talk(std::string text);
            bool is_dead();
        };

    - Creating objects

        Player bob;
        Player alice;

        Player *enemy = new Player();   // allocate memory 
        delete enemy;                   // delete to free up memory

    - Create pointers to objects. Pointer to Player object, create it dynamically on the heap, then delete it after it's used.
    - Once we have objects we can use them like any other variable in C++.
*/


#include <iostream>


int main() {
    
    return 0;
}
