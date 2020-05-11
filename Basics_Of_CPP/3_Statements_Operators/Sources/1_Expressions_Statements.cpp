// Expressions, Statements, and Operators in C++

/*
Expressions:
    - Basic building block of a program.
    - Sequence of operators and operands that specifies a computation.
    - Comnputes values from a number of operands.

Statements:
    - Complete line of code that performs some action.
    - Statements usually are terminated with a semi-colon.
    - Statements usually contain expressions.
        - null statement (;), compounds, selections, declarations, jumps, and try blocks.

Operators:
    - Unary, Binary, and Ternary operators are supported in C++.
        - Unary = one operand
        - Binary = two operands [+, -, *, /]
        - Ternary = 3 operands
    
    - Most of the operators we will use are Binary operators.

    Assignment Operator:
        - Right hand Side (RHS) is evaluated first and then stored into the Left Hand Side (LHS)
        - The data type of RHS must be compatable with LHS 
        - The LHS must be assignable

        int num1 {10};
        int num2 {20};  
        // this is not assignment, this is initialization of the 2 variables
        // generally we will use the assignment operator to change the value of the already initialized variable

    Arithmetic Operators:
        - +, -, *, /, and % 
        - here the % is modulo, the remainder.
        - +, -, *, and / are overloaded operators, they will work on different data types. The % operator will only work on ints.
        - Be careful with ints and the division operator, 10/20 will not result in 0.5  if 10 and 20 are both assigned to int
            variables. We must use floats or doubles to preserve the decimal places.

        - Order of operations for arithmetic operators in C++ follows the PEMDAS rule. 
*/


#include <iostream>


int main() {

    return 0;
}
