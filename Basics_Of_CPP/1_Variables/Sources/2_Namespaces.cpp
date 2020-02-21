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


    /* Standard Input Output using cin and cout

        * cout = Standard output, the default is the console / terminal
        * cin = Standard input, the default is from the keyboard

        * << = insertion operator, output streams
            - inseration operators do NOT automatically add line breaks, we need to add them in manually 
            - ex) << endl;  or  << "\n";

        * >> = extraction operator, input streams
            - cin and >>: this can also be chained like <<. This can potentially fail if the entered data cannot be interpreted
            - the data could be an undertermined value.

            - data entered from the keyboard will only be processed after enter is pressed.
            - cin extraction ignores whitespaces: spaces, tabs, and newlines are considered termination characters,
              but if there is whitespace before and after the data the compiler will ignore the whitespace and only take in the data.
            - cin >> var_x; cin first writes the data from the keyboard into a buffer and then reads the buffer to store into the variable var_x.

            :
            int x;
            int y;
            double z;

            cout << "Enter a number";
            cin >> x;
            cout << "Enter another number";
            cin >> y;
            cout << "You entered " << x << " and " << y;
            
            // If we entered "100 200" during the first cin the buffer will hold BOTH the numbers cin >> x will take the first number, and 
            // cin >> y will take the second number from the buffer. The whitespace after the 100 terminates the first cin for x, when the 
            // second cin is executed the compiler will read the buffer from where it left off and store the second number in the variable y.

            :
            cout << "Enter a number";
            cin >> x;
            cout << "Enter a double";
            cin >> z;

            // If we only enter 10.5, x will be 10 and z will 0.5. 1 and 0 are numbers but when the decimal point is reached >> will stop reading
            // the buffer and take 10 and assign it to the variable x, for z the buffer will continue at the decimal and continue to read it until 
            // it is done. z = 0.5

            :
            // If we enter the string "Hello" the compiler will try to assign it to the variable x, and z but will fail to do so since x is an integer
            // and z is a double. we will get unexpected results.
    */

    // Standard coding practices is to #include <iostream> and explicilty use the std:: scope resolution operatror for cout and cin.

    return 0;
}
