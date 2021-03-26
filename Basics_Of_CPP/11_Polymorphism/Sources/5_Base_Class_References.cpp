// Base Class References in C++

/*
Base Class References:
    - We can also use Base Class references with dynamic polymorphism. This is the other side to dynamic polymorphism, the other
        being Base Class pointer for dynamic polymorphism.
    - Useful when we pass objects to functions that expect a Base class reference.
    - Still under the section of inheritance / polymorphism.

    - ex) 

        Account a;
        Account &ref = a;
        ref.withdraw(100);      // Account::withdraw

        Trust t;
        Account &ref_1 = t;
        ref_1.withdraw(100);    // Trust::withdraw

    - these 2 lines: ref.withdraw(100) and ref_1.withdraw(100) are both dynamically bound, they call their own specific withdraw
        method.

    - ex)

        void do_withdraw(Account &account, double amount) {
            account.withdraw(amount);
        }

        Account a;
        do_withdraw(a, 100);    // Account::withdraw

        Trust t;
        do_withdraw(t, 100);    // Trust::withdraw

    - Here the line account.withdraw(amount) in the function on line 25 is dynamically bound.
*/


#include <iostream>


int main() {

    return 0;
}
