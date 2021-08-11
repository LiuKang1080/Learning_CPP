// Scoped Enumerations in C++

/*
Scoped Enums in C++:
    - Unscoped Enums:

        enum enum_name : enumerator_type { };

    - Enumerators that are qualified, and therefore only visible using the scope resolution operator.
    - This means that if we want to access the enums then we must specify which enumerator the enums belong to.
    
    - In order to specify that an enum is scoped we use the class or struct keyword after the enum keyword
    - General syntax for scoped enums:

        enum class/struct enum_name : enumerator_type { };

    - Why use scoped enums over unscoped?
    
        enum Whale {Blue, Beluga, Gray};
        enum Shark {Greatwhite, Hammerhead, Bull, Blue};

    - is Beluga equal to Hammerhead?

        if (Beluga == Hammerhead) {
            std::cout << "A Beluga whale is equal to Hammerhead shark! \n";
        }

    - This will result in true, and the statement will print, since 2 == 2 behind the scenes.
    - Name clashes can also occur for unscoped enums. Notice the Blue in the Shark enum, when we try to use Blue, the compiler
        can't tell the difference between the 2 blues, and this will result in an error.
    - The use of if and switch statements are exactly indentical to the unscoped enum version.

        enum class Whale {Blue, Beluga, Gray};

        Whale whale = Whale::Beluga;

        switch (whale) {
            case Whale::Blue:
                std::cout << "Blue Whale";
                break;

            case Whale::Beluga:
                std::cout << "Beluga Whale";
                break;

            case Whale::Gray:
                std::cout << "Gray Whale";
                break;
        }
        
    - There is 1 difference between scoped and unscoped in terms of accessing them and using them.
    - For UNSCOPED enums, if we wanted to set int var = Item::Milk for unscoped the compiler will auto access the underlying data
        type and set it. For SCOPED enums this is NOT possible!

        enum class Item {Milk=350, Bread=250, Apple=150};       // underlying data type is int
        
        int milk_code = Item::Milk;
        int total = Item_Milk + Item::Bread;
        std::cout << Item::Milk;

    - ALL 3 statements above will result in an error!
    - This is because Scoped enums are NOT implicitly convertable.
    - Instead we must EXPLICITLY cast the variable to the underlying enum type.
    - We can do:

        int milk_code = int(Item::Milk);                        // milk_code = 350
        OR 
        int milk_code = static_cast<int>(Item::Milk);

        int total = int(Item::Milk) + int(Item::Bread);         // total = 600
        std::cout << underlying_type_t<Item>(Item::Milk);       // displays 350
*/


#include <iostream>


int main() {

    return 0;
}
