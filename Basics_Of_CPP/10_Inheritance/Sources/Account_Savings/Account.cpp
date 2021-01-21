// Account.cpp, implementation of the Account class


#include <iostream>

#include "Account.h"


// Account no-args constructor. Contaians the initialization list
Account::Account() 
    :balance{0.00}, name{"My_Account"}{

}

// Account destructor
Account::~Account() {

}

// Account member method implementation:
void Account::deposit(double amount) {
    std::cout << "Account deposit called. Amount deposited: " << amount << "\n";
}

void Account::withdraw(double amount) {
    std::cout << "Account withdraw called. Amount withdrew: " << amount << "\n";
}
