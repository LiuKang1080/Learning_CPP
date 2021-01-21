// main.cpp for Account and Savings_Account


#include <iostream>

#include "Account.h"
#include "Savings_Account.h"


int main() {
    std::cout << "=== Account === \n";

    // create an object based on the Account class
    Account acc {};
    std::cout << "Account obj created" << "\n";

    // use the Account class member methods
    acc.deposit(1000.00);
    acc.withdraw(500.00);

    // create an Account object using a pointer
    Account *p_acc {nullptr};
    p_acc = new Account();

    // use the Account member methods
    p_acc->deposit(2000.00);
    p_acc->withdraw(500.00);

    // delete p_acc off of the heap
    delete p_acc;

    std::cout << "=== Savings Account === \n";
    
    // create an object based on the Savings_Account
    Savings_Account sav_acc {};
    /*
    When this gets created, it will inherit all of the data members from the base class: In this case it will inherit the
    name, and the initial balance of 0.00. The specific attribute of interest_rate is also created in the Savings_Account
    since it has it's own unique data members. During initialization, all data members that can be inherited will be, and
    then the unique data members will be initialized. Savings_Account has access to the 2 functions in the Account class, the 
    deposit, and the withdraw methods of the Account class. It also has its own unique deposit and withdraw methods. The
    detail of accessing the 2 Account methods depend on the access modifiers. 
    */
    
    // use the Savings_Account member methods
    sav_acc.deposit(1000.00);
    sav_acc.withdraw(100.00);

    // create a Savings_Account object with a pointer
    Savings_Account *p_sav_acc {nullptr};
    p_sav_acc = new Savings_Account();

    // use the Savings_Account member methods
    p_sav_acc->deposit(200.00);
    p_sav_acc->withdraw(50.00);

    // delete the data off of the heap
    delete p_sav_acc;

    return 0;
}
