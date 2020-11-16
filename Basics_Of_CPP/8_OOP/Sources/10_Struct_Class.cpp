// Structs vs. Classes

/*
Struct vs. Classes:
    - In addition to defining a class, we can also define a struct. The struct comes from the C programming language.
    - Essentially the struct is the same as a class except:
        - struct members are public by default.
        - class members are private by defualt. 

    - ex)

        class Person {
            std::string name;
            std::string get_name();
        };

        Person p;
        p.name = "Shiva";                       // compiler error - private member access
        std::cout << p.get_name() << "\n";      // compiler error - private method access

    - General syntax for defining a struct:

        struct Person {
            std::string name;
            std::string get_name();             // Why if the name is already public?
        };

        Person p;
        p.name = "Shiva";                       // ok - public member access
        std::cout << p.get_name();              // ok - public access

    - When to use structs vs classes?
        
        - Structs:
            - Use struct for passive objects with public access.
            - Don't declare methods in structs.

        - Classes:
            - Use classes for active objects with private access.
            - Use classes when we want to implement getters / setters.
            - Implement member methods as needed.
*/


#include <iostream>


int main() {

    return 0;
}
