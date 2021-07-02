// Lambda Expressions in C++

/*
C++ Lambdas:
    - C++11 and onwards. Lambdas got updated in C++14 and C++17.
    - Why do we have / need lambdas? Before a programmer would write many short functions that control algorithms. These short
        functions would encapsulate small classes to produce function objects. Many times the classes and functions are far
        removed from where they are used, leading to more code modification, maintainence, and testing issues.
    - Another big reason why lambdas were introduced is because sometimes the compiler cannot effectively inline functions for
        efficiency.

    ex)

        class Multiplier {
        private:
            int num {};

        public:
            Multiplier(int n)
                : num {n} {

                // constructor with defualt arguments
            }

            int operator() (int n) const {
                return num * n;
            }
        };

        std::vector<int> vec1 {1, 2, 3, 4};
        Multiplier mult {10};

        std::transform(vec1.begin(), vec1.end(), vec1.begin(), mult);
        // vec1 now contains {10, 20, 30, 40}
        // mult takes in a number from the constructor, and performs the operator() function due to std::transform being called

    - We can also create an unnamed multiplier object instead of creating mult, like so:

        std::transform(vec1.begin(), vec1.end(), vec1.begin(), Multiplier(10));

    - This is the same as behavior as before. Why can't we just do this? Creating classes, and the method functions can become
        very tedious.

What About Function Objects / Functors?

        template <typename T>
        struct Displays {
            void operator() (const T &data) {       // overloaded the () operator to display data, templated version
                std::cout << data << " ";
            }
        };

        Displayer<int> d1;
        Displayer<std::string> d2;

        d1(100);                        // d1.operator(100)     // displays 100
        d2("Bob");                      // d2.operator("Bob")   // displays Bob

    - These are objects, but are being used as functions, it's why it's called function objects.
    
        std::vector<int> vec1 {1, 2, 3, 4, 5};
        std::vector<std::string> vec2 {"Bob", "Alice"};

        std::for_each(vec1.begin(), vec1.end(), Displayer<int>());
        OR
        std::for_each(vec1.begin(), vec1.end(), d1);
        std::for_each(vec2.begin(), vec2.end(), d2);

Lambda Expression Example:
    - We can take the same example as above, but this time we can use lambda expressions:

        std::vector<int> vec1 {1, 2, 3, 4, 5};
        std::vector<std::string> vec2 {"Bob", "Alice"};

        std::for_each(vec1.begin(), vec1.end(), [](int x){std::cout << x << " "});
        std::for_each(vec2.begin(), vec2.end(), [](int x){std::cout << x << " "});

    - We don't need the template class or the function objects. The behavior is the same, but it is inline directly into the
        for_each() function.
    - The compiler can efficently optimize with lambdas, increasing speed.

Lambda Syntax:
    - General Syntax:

        [] () ->return_type specifiers {};

        - [] = Capture List: This is the capture list, this defines the start of the lambda. Allows us to capture the context or
            the closure the lambda expression executes. We will look at this when we cover Stateful Lambda Expressions. Capture
            lists tells what elements to capture, and we can specify if it will be by value or by reference.

        - () = Parameter List: Comma seperated list of parameters. This is like the parameter list in functions.

        - ->return_type = Like function return types, this tells us the data type of the return from the lambda expression. This
            is optional. The return type can be omitted, and if it is the compiler will try and deduce what the return type is 
            automatically.

        - specifiers = Optional specifiers, there are 2 specifiers: mutable, and constexpr. We will look at mutable later on, and
            will cover constexpr later.

        - {} = Body. This is where our code goes!

Example:
    - Simple lambda expression:

        [](){ std::cout << "Hello World"; };

    - How can we use this lambda? We can do: 
    
        [](){ std::cout << "Hello World"; } (); 

    - Notice the extra () at the end. This is the function call operator, this will instantiate a function object using the
        overloaded function call operator. Typically we don't see lambdas written this way with the () at the end.

Ex)

        [](int x) { std::cout << x; };

        [](int x, int y) { std::cout << x + y; };

    - We can also assign lmabdas to variables:

        auto L = []() { std::cout << "Hellow World"; };
        L();        // displays Hello World

        auto L = [](int x) { std::cout << x; };
        L(10);      // displays 10
        L(100);     // displays 100

Returning Values From Lambdas:
    
        auto L = [](int x, int y) ->int { return x + y; };

    - Here the ->int is optional, we can have:

        auto L = [](int x, int y) { return x + y; };
        std::cout << L(2, 3);       // displays 5
        std::cout << L(10, 20);     // displays 30

    - All of the above examples above are ALL stateless lambda expressions. They ALL have empty capture lists. We will look at
        capture lists, and stateful lmabda expressions next.
*/


#include <iostream>


int main() {

    return 0;
}
