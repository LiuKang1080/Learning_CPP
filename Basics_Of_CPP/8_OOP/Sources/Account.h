// Header File for the Account Class Specification

/*
#Include Guards
    - We need to pay attention to see if this header file will be included in multiple .cpp files. If it is #included in more
        than one place then the compiler will throw errors letting us know that class declarations with the same name occur.
    - If the .h header file is only included once within the entire project then we do not need include guards. The file will
        just contain the class specification

    ex) 
        class Account {
            private:
            double balance;

            public:
            void set_balance(double bal);       // Method prototypes
            double get_balance();
        }; 

    - If this header file will be #included in multiple locations then we need to include guards.
    - Include guards ensures that the compiler only includes the header file only once no matter how many times it is included.
    - We include the guard wrap around the entire class definition.

#pragma once
    - Many compilers support the #pragma once compiler directive. The effect of #pragma once is the exact same as the include
        guard written out manually.
    - Not all compilers support the #pragma once directive (espeically older compilers).
    - #pragma once does not need a trailing #endif directive.
    - ex)

        #pragma once

        class Account {
            private:
            double balance;

            public:
            void set_balance(double bal);
            double get_balance();
        };
*/


#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
// ifndef stands for if not defined
// generally the file name / class name is in all caps, and has preceding _ and trailing _. This must be unique
// the include guards wrap around the class specification
class Account {
    private:
    double balance;

    public:
    void set_balance(double bal);
    double get_balance();
};

// for each #if there must be a closing #endif
#endif
