// Switch Statements in C++

/*
Switch Statements
    - General syntax:

        switch (integer_control_expression) {
            case expression1: statement1; break;
            case expression2: statement2; break;
            ...
            case expression_n: statement_n; break;
            default: statement_defualt;
        }

    - integer_control_expression must evaluate to an integer type. integer_control_expression will be compared to the expressions
        the expressions must evaluate to an integer as well, and it must be known at compile time (must be constants or literals)

    - break statements are optional, but it is best practice to include them at each case statement.
    - defualt case at the end of the switch statement is optional, but best practice is to include it to deal with 
        defualt / other cases.
    - break keyword is not needed in the defualt case.
    - Once a match occurs ALL following case selections will execute UNTIL a break is reached. Once the break keyword is reached
        the switch statement will be complete, and will move onto the next code statement. 

    - If we are declaring variables, or if we are going to have complex statements for a case then the { } are REQUIRED. It 
        might be better to just use the { } for each of the expressions for each of the cases.

    ex)
        switch (selection) {
            case '1':
                cout << "1 selected.";
                break;
            case '2':
                cout << "2 selected.";
                break;
            case '3':
            case '4':                           // this is equal to an OR statement
                cout << "3 and 4 selected.";
                break;
            default:                            // defualt is optional, best practice is to include it
                cout << "1-4 NOT selected.";
        }

    ex)
        enum Color {
            red, green, blue
        };

        Color screen_color {green};

        switch (screen_color) {
            case red: cout << "red"; break;
            case green: cout << "green"; break;
            case blue: cout << "blue"; break;
            default: cout << "should never execute due to the enum";
        }
*/


#include <iostream>


int main() {

    return 0;
}
