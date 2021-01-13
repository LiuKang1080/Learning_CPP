// Inheritance in C++

/*
Inheritance in C++:
    - Theoretically it can be easy to understand, but in C++ it can be very complex.
    - Think "reusability" for classes.
    - In general terms it is: Deriving classes from existing classes.
    - There are 3 types of class inheritance
    - 3 major keywords: private, public, and protected (protected is used in the context of classes).

    - Some things to keep note of: Constructors & Destructors (order of constructor & destructor calls), Protected Members and
        Class Access. 

What is Inheritance?
    - In OOP, inheritance allows one to create a class from existing classes.
    - The new class contains the data and behaviors of the existing class.
    - Allows for the reuse of classes.
    - Allows us to focus on the common attributes among a set of classes.
    - Allows new classes to modify behaviors of existing classes to make it unique - without actually modifying the original class.

    - Generally we want to inherit from classes that make sense. Ex) You don't want to inherit from a Planet class if we're a 
        Player classl. We should inherit from a player-like class. They should be related together in some way.

    - Ex) Accounts example:
        Account:
            - Balance, Deposits, Withdraw
        Savings Account:
            - Balance, Deposits, Withdraw, Interest Rate
        Checking Account:
            - Balance, Deposits, Withdraw, Minimum Balance, Per check Fee
        Trust Account:
            - Balance, Deposits, Withdraw, Interest Rate

    - Without inheritance, we would need to implement these members and methods specifically the Balance, Deposits, and Withdraw
        methods. This is code duplication.

    - With inheritance, we can create new classes, the data and certain methods automatically be generated from the old class.

Terminology:
    - Inheritance: Process of creating new classes from existing classes.
        - Reuse mechanism.
    
    - Single Inheritance: A new class is created from another "single" class.
    
    - Multiple Inheritance: A new class is created from 2 or more other classes.
    
    - Base Class (Parent Class, Super Class): The class being extended or inherited from. 

    - Derived Class (Child Class, Sub Class): The class being created from the base class. Will inherit attributes and operations
        from the parent class.
    
    - We can use UML (Unified Modeling Language) class diagrams to visually see the structure / hierarchy of the classes.

    - "Is-A" Relationship:
        - public inheritance
        - derived classes are sub-types of thier base class (Circle "is a" Shape). Here Circle and Shape are both classes, and
            Circle is inheriting from the Shape class.
        - Can use a derived class object whenever we use a base class object.

    - Generalization:
        - Combining similar classes into a single, more gneral class based on common attributes.

    - Specialization:
        - Creating new classes from existing classes proving more specialized attributes or operations.

    - Inheritance / Class Hierarchies:
        - Organization of our inheritance relationships.
        - We use the UML class diagrams.

    - Inheritance is transitive: ex) Arrow upwards means inheriting from:

            A
        ↑       ↑ 
        B       C
                ↑ 
                D
                ↑ 
                E

    - Class Relationships:
        - E is a D
        - E is a C
        - E is a A
        - B is a A
        - B is NOT a C

    ex) 

                    Person 
            ↑                       ↑ 
        Employee                Student
    ↑       ↑       ↑ 
Faculty   Staff  Administrator 

    - The "is - a" relationship is NOT bi-directional. ex) A Person is not necessarily an Employee, because they could be a 
        student.

    - UML class diagrams like the one above can be very helpful.
*/


#include <iostream>


int main() {

    return 0;
}
