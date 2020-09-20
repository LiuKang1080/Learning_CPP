// Declaring Classes and Creating Objects in C++

/*
Declaring Classes
    - General Syntax:

        class Class_Name {
            // declaration(s);
        };

    - General programming practice is to capitalize class names.

    - ex)

        class Player {
            // attributes
            std::string name;
            int health;
            int xp;

            // methods
            void talk(std::string text);
            bool is_dead();
        };
    
    - we've created the class, now we can create objects of the type Player:

        Player bob;
        Player alice;

        Player *enemy = new Player();       // allocate memory for the enemy object
        delete enemy;                       // delete enemy to free up memory

    - We can create pointers to objects. Pointer to a player object, create dynamically on the heap. Once we're done using the
        object we can delete it to free up the space.

    - Once we have objects we can use them like any other variable in C++. ex)

        class Account {
            // attributes
            std::string name;
            double balance;

            // methods
            bool withdraw(double amount);
            bool deposit(double amount);
        };

        Account bob_account;
        Account alice_account;
        Account *mary_account = new Account();

        Account jim_account;
        Account andy_account;

        Account accounts[] {jim_account, andy_account};     // an array of objects of the data type Account
        std::vector<Account> accounts1 {jim_account);       // a vector of objects of the data type Account 
        accounts1.push_back(andy_account);

    - Generally when we create classes we want to declare them outside of the main() function. The general programming standard
        is to define the classes in seperate files.

    - Remember that if we do not explicitly gives values to the attributes in classes, they will contain garabe data until we 
        provide data to them.
*/


#include <iostream>


int main() {

    return 0;
}
