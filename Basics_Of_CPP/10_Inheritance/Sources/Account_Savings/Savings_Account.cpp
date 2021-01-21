// Implementation of the Savings_Account 


#include <iostream>

#include "Savings_Account.h"


// implementation of the constructor. initilaization of the data members for this specific class
Savings_Account::Savings_Account() 
    : interest_rate{2.5} {

}

// implementation of the destructor
Savings_Account::~Savings_Account() {

}

// implementation of the Savings_Account member methods:
void Savings_Account::deposit(double amount) {
    std::cout << "Savings_Account deposit called. Amount deposited: " << amount << "\n";
}

void Savings_Account::withdraw(double amount) {
    std::cout << "Savings_Account withdraw called. Amount withdrew: " << amount << "\n";
}
