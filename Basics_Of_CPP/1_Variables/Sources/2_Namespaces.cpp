// Namespaces in C++
#include <iostream>


int main() {
    // Using namespaces in C++
    
    std::cout << "Hello World" << std::endl;
    // The standard way to print to the console is by using std::cout. std is the namespace that cout uses from iostream. 
    // Namespaces are used to prevent naming conflicts.
    
    // If we have our own function that is called cout C++ cannot tell the difference between the cout function in iostream and our own
    // we use namespaces to tell C++ which function to use.

    // If we were to have our own cout function we would need to use our own namespace
    // ex) shiva::cout 

    // Using the namespace derective

    return 0;
}
