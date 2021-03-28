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
#include <vector>


// Abstract Base Class
class Shape {
public:
    virtual void draw() = 0;        // pure virtual function
    virtual void rotate() = 0;      // pure virtual function
    virtual ~Shape() {};

    // since the draw() and rotate methods are pure virtual functions, this makes the Shape class an Abstract Class
    // we cannot instantiate objects from this class!
};

// Derived Circle Class (Concrete Class)
class Circle: public Shape {
public:
    virtual void draw() override {
        std::cout << "Calling the draw() method from the Derived Circle Class: Drawing a Circle \n";
    }

    virtual void rotate() override {
        std::cout << "Calling the rotate() method from the Derived Circle Class: Rotating a Circle \n";
    }

    // destructor (needs to be virtual since it is virtual in the base class)
    virtual ~Circle() {
        std::cout << "Destrcutor for the Circle is called \n";
    };
};

// Derived Square Class (Concrete Class)
class Square: public Shape {
public:
    virtual void draw() override {
        std::cout << "Calling the draw() method from the Derived Square Class: Drawing a Square \n";
    }

    virtual void rotate() override {
        std::cout << "Calling the rotate() method from the Derived Square Class: Rotating a Square \n";
    }

    // destructor (needs to be virtual since it is virtual in the base class)
    virtual ~Square() {
        std::cout << "Destructor for the Square is called \n";
    };
};


int main() {

    // we cannot create Shape objects since it is a Abstract Class
    // both of the lines below will result in compiler errors!
    // Shape my_shape;
    // Shape *ptr = new Shape();

    // These methods in the derived class are dynamically bound at run-time
    // all of our derived classes are concrete classes
    Shape *s1 = new Circle();
    Shape *s2 = new Square();

    // create a vector to loop through the shapes, and use their functions
    // what is the data type in the vector? it is a Shape pointer
    std::vector<Shape *> my_shapes {s1, s2};

    // loop through the vector
    for (const auto ptr: my_shapes) {
        ptr->draw();
        ptr->rotate();
    }

    // delete the pointers once we're done using them
    delete s1;
    delete s2;

    return 0;
}
