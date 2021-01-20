// Inheritance vs. Composition in C++

/*
Inheritance vs. Composition
    - Both allow reuse of existing classes.

    Public Inheritance:
        - "is-a" relationship
            - Employee "is-a" person
            - Checking Account "is-a" Account
            - Circle "is-a" Shape
        
    Composition Inheritance:
        - "has-a" relationship
            - Person "has-a" Account
            - Player "has-a" Special Attack
            - Circle "has-a" Location

    - If a "is-a" relationship doesn't make sense, we can then use composition. Remember "is-a" and "has-a" relationships.
    - Look at the ULM models, class diagrams to choose and design the class inheritance.

    - ex) base example of Composition, We've been writing a form of composition for the basic classes we've been using:

        class Person {
        private:
            std::string name;       // "has-a" name
            Account account;        // "has-a" account
        }; 
*/


#include <iostream>


int main() {

    return 0;
}
