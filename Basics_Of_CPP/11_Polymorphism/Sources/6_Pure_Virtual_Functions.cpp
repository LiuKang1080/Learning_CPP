// Pure Virtual Functions and Abstract Classes in C++

/*
Pure Virtual Functions and Abstract Classes
Abstract Classes:
    - Cannot instantiate objects.
    - These classes are used as Base classes in inheritance hierarchies.
    - Often referred to as Abstract base Classes.

Concrete Classes:
    - Used to instantiate objects from.
    - All of their fuinctions are defined
        ex) Checking Account, Savings Account

Abstract Base Classes:
    - Too generic to create objects from (but serves as a parent to be derived from)
        - Shape, Employee, Account, Player
        - Serves as a parent to a derived class that have instantiated objects
        
    - Abstract base classes contain at least 1 pure virtual function.

Pure Virtual Functions:
    - pure virtual functions are used to make a class abstract.
    - Specified with a " = 0 " in its declaration.
    
        virtual void my_function() = 0;     // this is a pure virtual function

    - Typically pure virtual functions do NOT have any implementations.
    - If a pure virtual function exists within a class, then that class will become an abstract class, and cannot be instantiated
        from.

    - Derived classes MUST override the base class' pure virtual functions:
        - If the derived class does NOT override then the derived class will also be an Abstract class!
        - Abstract classes cannot be instantiated from. We cannot make objects from these type of classes regardless if they're
            base classes or derived classes.
        - We MUST override the Base Class Pure Virtual Functions in the derived class so that we can get a concrete class to
            instantiate objects from.

        virtual void draw() = 0;        // Shape
        virtual void defend() = 0;      // Player

        - The draw() method in the Shape class makes the Shape class an Abstract class since it is a pure virtual function. This
            also forces ALL derived classes to override and implement the draw() method if they want to be concrete classes.

        - For the Shape and Player example: Will we ever have a Shape object? (No) What does it even to make a Shape object?
            (We can make specific shapes like circles and squares, but making a SHAPE itself doesn't make sense) 

    Shape example)

        class Shape {
        private:
            // attributes common to all shapes
        
        public:
            virtual void draw() = 0;        // pure virtual function
            virtual void rotate() = 0;      // pure virtual function
            virtual ~Shape();
            ...
        };

    - If we define the draw() and rotate() methods as pure virtual functionsm, then ALL derived classes MUST override these
        2 methods or they will also be Abstract classes.
    - It makes no sense to actually implement the draw() and rotate() methods since we can't instantiate objects directly
        from this class.
        
        class Circle: public Shape {
        private:
            // attributes that are common to all circles
            
        public:
            virtual void draw() override {
                // code to draw a circle
            }

            virtual void rotate() override {
                // code to rotate a circle
            }

            virtual ~Circle();

            ...
        };

    - Now the Circle class is a concrete class.

Summary:
    - Abstract Classes:
        - Cannot be instantiated from directly
        
            Shape my_shape;                 // Error
            Shape *ptr = new Shape()        // Error

    - We can use pointers and references to dynamically refer to concrete classes derived from them:
        
        Shape *ptr = new Circle();
        ptr->draw();
        ptr->rotate();

    - ptr is a pointer to a Shape, we then create a Circle object on the Heap and point to it from ptr.
    - With the override virtual functions Circle::draw() and Circle::rotate() methods will be called. It doesn't make sense that
        the draw() and rotate methods from the Shape base class are called since we're FORCED to override them. The Circle class 
        would be an Abstract class and we can't make any objects from Abstract classes.
*/


#include <iostream>


int main() {

    return 0;
}
