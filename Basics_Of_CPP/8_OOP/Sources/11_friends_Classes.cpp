// Friends of a Class in C++

/*
Friends of a Class:
    - Friend:
        - A function or class that has access to private class members, and that function of or class is NOT a member of the 
            class it is accessing.

    - Function:
        - Can be regualr non-member functions.
        - Can be member methods of another class.

    - Class:
        - Another class can have access to private class members.

Big Picture:
    - Friendship must be granted, NOT taken.
        - Declared explicitly in the class that is granting friendship.
        - Declared in the function prototype with the keyword [ friend ]

    - Friendship is not symmetric:
        - Must be explicitly granted
            - A is a friend of B. B is NOT a friend of A 

    - Friendship is not transitive:
        - Must be explicitly granted
            - if A is a friend of B, and B is a friend of C, this does NOT mean that A is a friend of C

    - Friendship is NOT inherited.

Declaring a friend in C++. General syntax:
    - ex)

        class Player {
            friend void display_player(Player &p);
            std::string name;
            int health;
            int xp;
        
        public:
            ...
        };

    - Now the display_player() function has access to everything in the Player class.

        void display_player(Player &p) {
            std::cout << p.name << "\n";
            std::cout << p.health << "\n";
            std::cout << p.xp << "\n";
        }

    - display_player may also change the private data members.

Declare a method in another class as a friend:
    - ex)

        class Player {
            friend void Other_Class::display_player(Player &p);
            std::string name;
            int health;
            int xp;

        public:
            ...
        };

    - the member function of another class:

        class Other_Class {
            ...
        public:
            void display_player(Player &p) {
                std::cout << p.name << "\n";
                std::cout << p.health << "\n";
                std::cout << p.xp << "\n";
            }
        };

    - Even though this function belongs in another class, we can directly access and use the members from the Player class. 

Declare an entire class as a friend:
    - ex)

        class Player {
            friend class Other_Class;
            std::string name;
            int health;
            int xp;

        public:
            ...
        };

    - All of the methods in Other_Class will have access to the player class' private attributes.

    - Friendship can bypass getters / setters function call overhead, and other class methods. Allows direct access to private
        attrributes.
    - Don't abuse friendship! Generally only the minimal amount of friendship should be granted. use friendship where needed.
*/


#include <iostream>


int main() {

    return 0;   
}
