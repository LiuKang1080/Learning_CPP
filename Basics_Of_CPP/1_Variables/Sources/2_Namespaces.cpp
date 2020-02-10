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
    // ex) my_own_namespace::cout 

    // Using the namespace directive: We can use the namespace directive when we don't want to explicitly write out std:: 
    // everytime we need to use functions from the standard library. 
    // General syntax: using namespace [name of the namespace];
    using namespace std;

    // We can now just use cout and cin without calling std:: 
    cout << "Using the namespace directive";

    // We need to pay attention to what using namespace directives are actually doing, It will bring in the ENTIRE namespace.
    // In certain programs we may not want to do that. 

    // Qualified Using Namespace variation:
    /*
    using std::cout;
    using std::cin;
    using std::endl;

    cout << "qualified using namespaces.";
    */
    // Using this variation we can use only what we need. 

    return 0;
}
