// If-Else statements in C++

/*
If Statements:
    - General Syntax:

        if (expression) {
            statement; 
        }

    - Here the { } are not required if we only have one statement. It is required when we have more than 1 statement in the block
        Generally it is good programming practice to have the braces regardless of the number of the statements.
    - statement will only execute if the expression within the parenthesis evaluates to true. If expression does not evaluate to 
        true then the entire if statement will be skipped.

    - We can mansually create code blocks by putting code within { }. Code within the brackets have their own local scope.

If-Else Statements:
    - General Syntax:

        if (expression) {
            statement1;
        } else {
            statement2;
        }

    - If the expression is true, then it will execute statement1. If expression is false then it will execute statement2.

If-Else-If Statements:
    - General Syntax:

        if (expression1) {
            statement1;
        } else if (expression2) {
            statement2;
        } else {
            statement3;
        }

Nested If Statements:
    - We can nest If / Else-If statements within other If / Else-If statements
    - General syntax:

        if (expression1) {
            if (expression2) {
                statement1;
            } else {
                statement2;
            }
        }

    - Notice how we 2 if statements and only 1 else statement, This is known as the dangaling else problem. Which if does this 
        else belong to? In C++ the else belongs to the closest if statement
    
    - It is very important for proper indentation for code redability. The C++ compiler does not care about the indentation or
        the spacing. Proper indentation and spacing matters for redability / code maintainability.
*/


#include <iostream>


int main() {
    
    return 0;
}
