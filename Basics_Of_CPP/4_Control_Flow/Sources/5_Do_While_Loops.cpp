// Do While Loops in C++

/*
Do-While Loops:
    - General syntax:

        do {
            statement(s);
        } while (expression);

    - The semi-colon is required at the end.
    - The expression condition check happens at the end (post test loop).
    - The loop will run at least once guaranteed.

    ex) Area calculation with multiple calculations
        
        char selection{};
        
        do {
            double width = 0.00;
            double height = 0.00;
            std::cout << "Enter the width and height seperated by a space: ";
            std::cin >> width >> height;
            
            double area = width * height;
            std::cout << "The area is: " << area << "\n";

            std::cout << "Calculate another? (Y/N): ";
            std::cin >> selection;
        } while (selection=='Y' || selection=='y');
*/


#include <iostream>


int main() {

    return 0;
}
