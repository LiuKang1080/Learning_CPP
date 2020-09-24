// Constructors and Destructors in C++

/*
Constructors and Destructors:
Constructors:
    - Special member methods within classes.
    - Invoked during the object creation. Used during the initilization of an object.
    - Has the same name as the class.
    - No return type is specified.
    - Can be overloaded.

    - ex) 

        class Player {
        private:
            std::string name;
            int health;
            int xp;

        public:
            // constructors
            Player();
            Player(std::string name);
            Player(std::string name, int health, int xp);
        };

        class Account {
        private:
            std::string name;
            double balance;

        public:
            // constructors
            Account();
            Account(std::string name, double balance);
            Account(std::string name);
            Account(double balance);
        };

Destructors:
    - A special member method.
    - Same name as the class. Preceeded with a tilde ( ~ ).
    - Invoked automatically when the object is destroyed.
    - No return type, and no parameters.
    - Only 1 destructor is allowed per class. The destructor cannot be overloaded.
    - Useful to release memory and other resources.

    - ex) 

        - In the Player class:

        public:
            Player();
            Player(std::string name);
            Player(std::string name, int health, int xp);

            // destructor
            ~Player();
        };

        - In the Account class

        public:
            Account();
            Account(std::string name, double balance);
            Account(std::string name);
            Account(double balance);

            // destructor
            ~Account();
        };

    - When objects go out of scope their destructors will automatically be called.
    - Whatever code is written within the destructor will be executed before the object is destroyed.

        Player *enemy = new Player("Enemy", 1000, 0);   // the class is created with the string, int, int constructor called.
        delete enemy;                                   // the destructor is called.

    - If no constructor or destructor is provided, then C++ will automatically provide its own defualt constructor and destructor.
*/


#include <iostream>


int main() {

    return 0;
}
