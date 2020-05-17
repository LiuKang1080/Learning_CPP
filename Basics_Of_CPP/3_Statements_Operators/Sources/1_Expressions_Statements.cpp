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

    Increment / Decrement Operators:
        - ++ and -- increment and decrement by 1.
        - We can use these operators on ints, floating point numbers, and pointers.
        
        - prefix: ++num
        - postfix: num++

        - DO NOT overuse these operators. NEVER use these operators multiple times in the same statement, we can end up with
            undefined behavior.

        - ++num = increment num by 1 before using num
            counter = counter + 1; 
            result = counter;
            print result;

        - num++ = increment num by 1 after using num 
            result = counter;
            counter = counter + 1;
            print result;

    Mixed Data Type Expressions:
        - Operands are 2 different data types. C++ will try to convert one of the operands (Coercion). C++ will try to, if it 
            cannot then the compiler will throw an error.
        - C++ data type conversions: higher vs lower = based on the size of the data type of the values
            (Higher) long double, double, float, unsigned long, long, unsigned int, int (Lower)
        - short and char are automatically converted to ints 

        - Type Coercion = Conversion of one operand to another data type
        - Premotion = Conversion to a higher type. ex) 2 * 2.5  // the 2 will be premoted to 2.0 and then calculated  
        - Demotion = Conversion to a lower type ex) int num;    num = 100.25    // here only 100 will remain since it's an int
            We need to pay attention to these types of conversions since we will lose percision!

    Explicit Data Conversion (Type Casting):
        - General Syntax: static_cast<data type to be casted to>Variable;
        - This is explicit data type conversion.

        OLD vs NEW
        average = (double)total / count;    // This is old style C++ casting, we want to use the new static_cast<> casting
            - (conversion) just assumes that the variable can and will change data types, compiler assumes it can perform the 
                cast. New casting <> checks to see if the variable can be casted to the new data type. 
*/


#include <iostream>


int main() {

    return 0;
}
