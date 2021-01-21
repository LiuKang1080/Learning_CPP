// Header file for the Account class
// Definition of the Account class

#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>


class Account {
public:
    // data members
    double balance;
    std::string name;

    // methods
    void deposit(double amount);
    void withdraw(double amount);

    // constructor - no args constructor
    Account();

    // destructor
    ~Account();
};

#endif 
// _ACCOUNT_H_
