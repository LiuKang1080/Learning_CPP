// std::exception Class Hierarchy in C++

/*
std::exception Class Hierarchy:
    - #include <exception> (Not always required)
        - look into the exception header file.
    - C++ provides a class hierarchy of exception classes.
    - std::exception is the base class (ALL other exception classes are derived from it).
    - ALL subclasses implement the what() virtual function.
    - We can create our own user defined exception subclass if we need to.

        virtual const char *what() const noexcept;      // returns an std::string C++ style object

    - ALL of the exception classes we've made ARE std::exception classes due to inheritance.
    - Due to polymorphism we can use our own exception classes where C++ expects an std::exception class.
    - We only need to implement the what() function and it will be bound dynamically at run-time.

    - Deriving from std::exception example:

        class IllegalBalanceException: public std::exception {
        public:
            IllegalBalanceException() noexcept = defualt;
            ~IllegalBalanceException() = defualt;

            virtual const char *what() const noexcept {
                return "Illegal Balance Exception. \n";
            }
        };

noexcept Keyword:
    - tells the C++ compiler that the method will NOT throw an exception, the deconstructor by defualt will NOT throw an
        exception by defualt.
    - If we throw an exception from a method that has noexcept, then the program will terminate. The exception will NOT be
        handled.

        Account::Account(std::string name, double balance)
            : name{name}, balance{balance} {

            if (balance < 0.0) {
                throw IllegalBalanceException();
            }
        }

        try {
            std::uniqu_ptr<Account> bob_account = std::make_unique<Checking_Account>("Bob", -10.00);
            std::cout << "Use Bob's Account \n";
        } catch (const IllegalBalanceException &ex) {
            std::cerr << ex.what() << "\n";             // displays "Illegal Balance Exception."
        }
*/


#include <iostream>


int main() {

    return 0;
}
