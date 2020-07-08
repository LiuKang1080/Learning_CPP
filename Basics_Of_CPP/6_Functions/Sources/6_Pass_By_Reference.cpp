// Pass by reference in C++

/*
Pass By Reference:
    - Sometimes we want to be able to change the data value of the parameters we pass into functions. In order to achieve this we
        can use pass by reference.
    - We need the address of the actual parameter. We can use reference parameters to tell the compiler to pass in a reference
        to the actual parameter.
    - The formal parameter will now be an alias for the actual parameter.
    - No copy of the data is made.

    - In a previous example we passed in a vector into a function that prints the contents of the vector. Before it was passed
        into the function with pass by value. This creates a copy of the vector, this takes up more time and memory. Passing
        by reference allows us to save the memory overhead while still allowing the same functionality.
    - We need to pay attention to how parameters are being passed in, and we need to decide on how to pass in parameters.
    
    - We can pass in parameters as pass by reference by adding the & (address of operator) in front of the varible.
    
    - Print vector contents example)

        void print_vector(std::vector<int> &v) {
            for (auto num: v) {
                std::cout << num << "\n";
            }
        } 

        int main() {
            std::vector<int> data = {1, 2, 3, 4, 5};
            print_vector(data);

            return 0;
        }

    - We use the actual data structure itself, no copies of the data is made that is passed into the parameter.
    - We need to be careful about what we're doing to the variables that are passed by reference. We could change the data 
        accidently.
    - We can use the const keyword to tell the compiler to not allow any changes to the data that is passed in.

        void print_vector(const std::vector<int> &v) {
            v.at(0) = 200;                                  // This results in a error!

            for (auto num: v) {
                std::cout << num << "\n";
            }
        } 
*/


#include <iostream>


// Function prototypes:
void scale_number(int &num);
void swap_numbers(int &a, int &b);


int main() {
    // scale number example:
    int number = 1000;
    std::cout << "number variable before scale function is called: " << number << "\n";
    scale_number(number);
    std::cout << "number variable after scale function is called: " << number << "\n";

    // swap numbers example:
    int x = 25;
    int y = 50;
    std::cout << "Values before swap function is called: " << x << ", " << y << "\n";
    swap_numbers(x, y);
    std::cout << "Values after swap function is called: " << x << ", " << y << "\n";

    return 0;
}


// Function definitions:
void scale_number(int &num) {
    if (num > 100) {
        num = 100;
    }
}

void swap_numbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
