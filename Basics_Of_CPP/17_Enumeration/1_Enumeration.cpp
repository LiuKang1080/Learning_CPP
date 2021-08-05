// C++ Enumeration

/*
C++ Enumerations, Enumerated Data Types, or Enums:
    - Enumeration = A user defined type that models a set of constant integral values.
        - Ex:

        - Days of the week: (Sun, Mon, Tue, Wed, ... , Sat)
        - Months: (Jan. Feb, Mar, ... , Dec)
        
    - Before Enums, we had unamed numerical constants, called "magic numbers". These constants would be used as conditionals in
        control statements. Often we don't know what these constants / numbers were doing in an algorithm, or where they came
        from.
    - Before Enums, we had many algorithms that were low readability, with hig number of logic errors.
    - The biggest thing Enums did was increase readability!

    - Ex:

        int state;
        std::cin >> state;

        if (state == 0) {
            initiate(3);
        } else if (state == 1) {
            initiate(4);
        } else if (state == 2) {
            initiate(5);
        }

        - What do the states mean?
        - What is the data that is being passed into the functions that are being called? Are they just Numbers?
        - What is the relationship between the states and the fdunction initiate()?

    - With Enums they increase readability, and algorithm correctness.

Enum Synstax:
    - The general syntax for Enumerations:

        enum_key enum_name: enum_type { };

    - Many of the parts of the Enum are optional. We need to closely pay attention to what an enum actually is in C++
    
        - enum_key = Defines the scope of the enumeration. Defines the beginning of the Enumeration. Always starts with enum.
            Can be scoped or unscoped
        - enum_name = Naming is optional for unscoped enumerations.
        - enum_type = Can be omitted and the compiler will try and deduce it. Serves as the underlying data type for the
            individual enumes within the enumerator.
        - { } = Enumerator list. List of enumerator definitions.

Enum Examples:

        enum {Red, Green, Blue}

    - This is the most simple enum we can have, it has no name, and does not have any underlying type specifications for the enums.
    - This contains 3 enums.
    - This has no initializers! This mean that implicit initialization will occur. The compiler will auto assign the first enum
        with the value of 0, and increment by 1 upwards for each next enum within the enumerator list.

        Red = 0
        Green = 1
        Blue = 2

    - We can also do explicit initialization:

        enum {Red=1, Green=2, Blue=3};

    - We can also do BOTH implicit AND explicit initialization:

        enum {Red=1, Green, Blue};

        - The compiler will auto assign the numbers 2 and 3 to Green and Blue. 

Enumerator Types
    - The compiler will choose the smallest width in bits for the enum type that can hold that dat type

        enum {Red=1, Green=2, Blue=3};          // underlying data type = int
        enum {Red=1, Green=2, Blue = -32769}    // underlying data type = long
    
    - We can also explicitly set the data type of the enums:

        enum: long long int {Red, Green, Blue}; // underlying data type = long long

    - If we specify the underlying data type, but the enum data cannot hold that (overflow), the the compiler will throw an error.

Enumerator Names:
    - Enums can be created without a name

        enum {Red, Green, Blue};

        int my_color;

        my_color = Green;       // Valid
        my_color = 4;           // Also valid

    - There is no type safety for this enum!
    - Generally we don't want this, we want the type to be restricted:

        enum Color {Red, Green, Blue};

        Color my_color;

        my_color = Green;       // Valid
        my_color = 4;           // NOT valid

    - This enum provides type safety. This is a named type safe enum.
    - The data type should form the "is a" relationship between it and the enums within the list.
        "Red 'is a' Color"
*/


#include <iostream>


int main() {

    return 0;
}
