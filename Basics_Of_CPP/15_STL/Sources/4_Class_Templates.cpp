// Class Templates in C++

/*
Class Templates:
    - Similar to function templates, but at the class level.
    - Allows for plugging in any data type.
    - The compiler generates the appropriate class from the remplate blueprint
    - Allows for a generic class, but this includes generic constructors, destructors, methods, and attributes.
    - Class templates can become very complex. Combining templates with inheritance, polymorphism, operator overloading, and
        other OOP concepts can lead to very complex code.
    
    - ex) A class that holds an int and a string for a name:

        class Item {
        private:
            std::string name;
            int value;

        public:
            // constructor
            Item(std::string name, int value)
            : name{name}, value{value} {
                // code for the constructor
            }

            std::string get_name() const {
                return name;
            }

            int get_value() const {
                return value;
            }
        };

    - What happens if we want a value as an int, float, double, or a char? We want the Item class to hold any type of data in
        addition to the string.
    - We can't overload the class names.
    - We also don't want to use dynamic programming.
    
    - We want to turn this class into a class template.
    - We start by substituting the int with T.
    - We now tell the compiler that T is part of the template.
    - We add the template keyword BEFORE the class definition.

        template <typename T>
        class Item {
        private:
            std::string name;
            T value;

        public:
            // constructor
            Item(std::string name, T value)
            : name{name}, value{value} {
                // code for the constructor
            }

            std::string get_name() const {
                return name;
            }

            T get_value() const {
                return value;
            }
        };

    - Now we can create those class objects. The compiler will take care of the data types.

        Item<int> item1 {"Bob", 1};
        Item<double> item2 {"Alice", 100.00};
        Item<std::string> item3 {"Mark", "Boss"};

        std::vector<Item<int>> vec1;

    - Like with function templates, we can have multiple template parameters and their data types can be different.

        template <typename T1, typename T2>
        struct My_Pair {
            T1 first;
            T2 second;
        };

        My_Pair<std::string, int> p1 {"Frank", 100};
        My_Pair<int, double> p2 {125, 75.25};
        std::vector<My_Pair<int double>> vec2;

std::pair
    - Pairs are a very common data structure, it is already implemented in the STL for us.
    - In order to use std::pair we must #include <utility> the utility header file.

        std::pair<std::string, int> p1 {"Frank", 100};
        std::cout << p1.first;      // Frank
        std::cout << p1.second;     // 100

    - Pair is limited to only 2 elements. C++ also has the Tuple class. The Tuple is not limited to 2 items, it can have multiple
        elements of any data type.
*/


#include <iostream>


int main() {

    return 0;
}
