// Stateful Lambda Expressions in C++

/*
Stateful Lambdas:
    - General Syntax:

        [captured_variables] () -> return_type specifiers { };

    - By definition a stateful lambda is a lambda expression that has a non-empty capture list.
    - A non-empty capture list, this defines what information / variables should be captured from the outside scope.
    - Allows the lambda to reach the variables within the outside scope without having to pass them into the lambda. This is done
        by listing the variables we want to capture within the capture list.

    - What happens behind the scenes: When we create a lmabda, the compiler will generate a closure and use that to do the logic
        within the lambda.

        auto L = [] (int x) { std::cout << x; }

        class compiler_generated_name {
        public:
            compiler_generated_name();          // defualt constructor

            void operator() (int x) {
                std::cout << x;
            }
        };

    - The class isn't generated until compile time. The auto keyword must be used for the specifier, and type. When we use
        lambdas, the type hasn't been generated yet, the type is only generated when the lambda is compiled, this is why we use
        the auto keyword.

    - When we assign a lambda to a variable, what we're doing is instantiating an object of the compiler generated closure, by
        making a call to it's constructor.

How Lambdas Store The Capture Variables:

        auto L = [y](int x) { std::cout << x + y; };

        class Compiler_generated_name {
        private:
            int y;

        public:
            Compiler_generated_name(int y)
                : y{y} {

                // constructor with y defualted
            }

            // int y, takes the value from the outside scope and defualt assigns it upon object instantiation

            void operator() (int x) const {
                std::cout << x + y;
            }

            // No member variable of the instantiated object can be modified by this function. Member variable y cannot be
            // changed.
        };

    - By defualt ALL variables captured by value are captured by const value! This means the lambda CANNOT change the variable.
    - This seems restrictive. C++ gives us other ways to modify data when we capture them lambdas.

    1) Defualt capture by const value:

        int x = 100;
        [x]() { std::cout << x; } ();           // displays 100

        - defualt capture by const value

    2) Using the mutable keyword to modify variables captured by value:

        int x = 100;
        [x]() mutable {
            x += 100;
            std::cout << x;             // displays 200
        } ();

        std::cout << x;                 // displays 100

        - There is its own scope within the lambda! 

    3) Capture by reference:

        int x = 100;
        [&x]() { x += 100; } ();        // increase by 100

        std::cout << x;                
        // displays 200. Look at the scope! and pay attention to the scope along with HOW the variable is passed in!

Defualt Captures:
    - Since we can choose how to pass in variables to the capture list, C++ allows us to set a default capture. This way we
        don't need to specifiy manually on every variable.

    - [=]:      Defualt capture by value
    - [&]:      Defualt capture by reference
    - [this]:   Defualt capture this object by reference

    - [=, &x]:      Defualt capture is by value, but capture x by reference
    - [&, y]:       Defualt capture is by reference, but capture y by value
    - [this, z]:    Defualt capture is by this, but capture z by value

    - The default capture mode setting is the FIRST in the capture list!
    - The explicit capture CANNOT be the same as the defualt capture type! We will get a compiler if we do this!

        [&, &x, &y]

        - We set the defualt capture mode to capture by reference, and then we explicitly pass in x and y by reference.
            This will result in a compiler error!
*/


#include <iostream>


void lambda_example() {
    int x = 100;

    // create the lambda, this is a stateful lmabda, captures x
    auto L = [x]() mutable {
        std::cout << "========== \n";
        std::cout << "Captured value x is: " << x << "\n";

        x += 100;
        std::cout << "Within the Lambda, x: ";
        std::cout << x << "\n";
    };

    // call the lambda
    L();
    // print x
    std::cout << "Outside the Lambda, x: " << x << "\n";
    // call the lambda again
    L();
    // print x again
    std::cout << "Outside the Lambda, x: " << x << "\n";

/*
    - Pay attention to when we define the lambda, and when we call it!
    - We define it ONCE, but CALL the lambda twice!

    - We capture x, and since we have the mutable keyword we can change the captured value.
    - The first time we call the lambda, we increase it by 100.
    - We print x outside the lambda, and we get the result we expect, it is 100
    - The second time we call the lambda, we increase x again getting the result 300!
        - The x that is saved in WITHIN the lambda still exists! Remember the closure class that gets created behind the scenes,
            that captured value gets stored within the class, and persists UNTIL we leave the entire function.
*/
}


int main() {
    // call the lambda example function
    lambda_example();

    return 0;
}
