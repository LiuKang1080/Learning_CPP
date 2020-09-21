// Declaring Classes and Creating Objects in C++

/*
Declaring Classes:
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

Accessing Class Members:
    - We can access class attributes and methods. Some class members will not be available for us to access.
    - We need an object to access the instance variable. It doesn't make sense to access a class directly without doing so 
        through the object.
    
    - There are 2 ways to access Class members:
        1) The . operator
        2) The arrow operator (member of pointer operator)
    
    1) The dot operator:

        Account bob_account;
        std::cout << bob_account.balance << "\n"; 
        bob_account.deposit(100.00);

    2) The arrow operator (member of pointer operator)
    - If we have a pointer to an object we need to manually use the . operator or the arrow operator.

        Account *jim_account = new Account();
        std::cout << (*jim_account).balance << "\n";
        (*jim_account).deposit(100.00);

        // *jim_account is NOT an Account object, it is a pointer pointing to an Account object, which is dynamically allocated
            on the heap.
        // (*jim_account).deposit(100.00) We must use the () to dereference the pointer first since the . operator has higher
            precedence. Dereference the pointer first, and then access the attribute with the . operator.

        OR 

        Account *jim_account = new Account();
        std::cout << jim_account->balance << "\n";
        jim_account -> deposit(100.00);

    - The spacing does not matter between the ->
    - -> dereferences the thing on the left, and then access the attribute provided on the right. The attribute must be an
        attribute of the class or we will get a compiler error. 

    - By default all of the attributes and methods of a class are private by defualt. By defualt we do not have access to them.

Member Access Modifiers:
    - C++ provides 3 member access modifiers:
        1) Public - Accessible everywhere
        2) Private - Accessible only by members or friends of the class
        3) Protected - Used in inheritance

    - General Syntax:
        - In the body of the class we can specify the access the modifier followed by a colon : 
        - All members after we declare the access modifier will have that access modifier. It will continue to have that modifier
            until we have another access modifier or until the definition of the class is done.
        - If no access modifier is specified, then by defualt all members of the class will have private member access.
        - Generally we use a combination of private and public modifiers:

        class Player {
        private:
            std::string name;
            int health;
            int xp;
        
        public:
            void talk(std::string text);
            bool is_dead();
        };

    - We will get a compiler error when we try to access private member of a class.
    - Why do we need to make some members private while others public? We want to control the access to certain data within
        methods by making them private.
*/


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


class Account {
    // attributes
    private:
    std::string name;
    double balance = 0.00;

    // methods
    public:
    void display_balance() {
        std::cout << "Displaying current balance: " << balance << "\n";
    }

    void withdraw(double amount) {
        double original_balance = balance;

        if ((balance -= amount) >= 0.00) {
            std::cout << "Withdrew: " << amount << " Balance is now: " << balance << "\n";
        } else {
            std::cout << "Could not withdraw the amount provided: " << amount << " Instead you withdrew: " << original_balance << "\n";
            balance = 0.00;
        }
    }

    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposited: " << amount << " Total current balance is now: " << balance << "\n";
    }
};


int main() {

    std::cout << std::fixed << std::setprecision(2);

    Account *jim_account = new Account(); 
    jim_account->display_balance();
    jim_account -> display_balance();

    jim_account->deposit(500.00);
    jim_account->withdraw(100.00);
    jim_account->withdraw(999.99);
    jim_account->display_balance();

    return 0;
}
