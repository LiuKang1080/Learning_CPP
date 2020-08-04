// References in C++

/*
References:
    - References: An alias for a variable.
    - Must be initialized to a variable when declared.
    - Cannot be initialized to NULL.
    - Once initialized it cannot be made to refer to a different variable.
    - Very useful as function parameters.
    
    - Helpful to think about references as const pointers that is automatically dereferenced.

    - References are different than pointers.
    - When we use a reference, we're actually using the variable that it refers to.
    - References are often used in range based for loops.

        std::vector<std::string> stooges = {"Larry", "Moe", "Curly"};

        for (auto str: stooges) {
            str = "Funny";                  // changes each element to "Funny"?
        }

        for (auto str: stooges) {
            std::cout << str << "\n";       // We get out Larry, Moe, Curly
        }

    - This example does NOT use references, it is standard range based for loops.
    - Notice the output. Nothing changed the output, even though we assinged "Funny" to each of the elements.
    - Here str is a copy for each of the vector elements as we loop through them. We're setting the copy str to "Funny", and
        we're never changing the actual elements in the vector.

        for (auto &str: stooges) {
            str = "Funny";                  // reference, this now changes the actual elements within the vector
        }

        for (auto str: stooges) {
            std::cout << str << "\n";       // Funny, Funny, Funny
        }

    - str is now a reference to each of the C++ string objects in the vector.

const Modifier With References:
    - Adding a const modifier to the reference

        for (auto const &str: stooges) {
            str = "Funny";                  // This results in a compiler error. The const makes the reference read only
        }

    - It makes sense to use const when we're not modifying any data. Using it in the print for loops works.

        for (auto const &str: stooges) {
            std::cout << str << "\n";
        }

    - By using references we're not incurring the cost of copying each vector element in each loop iteration.
    - Unless we have a specific reason to copy elements in a range based for loop, then we should use a reference variable to
        make the code more efficient.
    - If we're not going to modify the data then we should use the const modifier.
    - From now on for simple range based for loops we will use references.
*/


#include <iostream>
#include <vector>
#include <string>


int main() {
    /* Range based for loop example without references */
    std::vector<std::string> stooges = {"Larry", "Moe", "Curly"};
    std::cout << "Range based for loop without references: \n";

    for (auto str: stooges) {
        str = "Funny";
    }

    for (auto str: stooges) {
        std::cout << str << ", ";
    }

    std::cout << "\n==========\n";
    /* Range based for loop example with references */
    std::cout << "Range based for loop with references: \n";

    for (auto &str: stooges) {
        str = "Funny";
    }

    for (auto const &str: stooges) {
        std::cout << str << ", ";
    }

    return 0;
}
