// Header file for the definition of the Savings Account


#ifndef _SAVINGS_ACCOUNT_H_
#define _sAVINGS_ACCOUNT_H_


#include "Account.h"
// we must include the Account.h header file or else the compiler will not know what the Account class is


// Inheritance from the base Account class
class Savings_Account: public Account {
public:
    // since this is a specialized class, derived from the Account base class, this class shoul have its own unique data
    // members and methods
    double interest_rate;

    // no-args constructor
    Savings_Account();
    
    // destructor
    ~Savings_Account();

    // Savings_Account member methods:
    void deposit(double amount);
    void withdraw(double amount);
};


#endif 
// _SAVINGS_ACCOUNT_H_
