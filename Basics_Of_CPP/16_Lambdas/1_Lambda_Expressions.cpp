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
*/


#include <iostream>


int main() {

    return 0;
}
