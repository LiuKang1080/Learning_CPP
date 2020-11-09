// Advanced Topics of the C++ Constructors

/*
Copy Constrcutors:
Shallow Copying with the Copy Constructor:
    - We need to be careful when data members within the class contain a pointer.
    - Constructor allocates storage dynamically and initializes the pointer.
    - Destructor releases the memory allocated by the constructor
    - What happens in the defualt copy constructor? When the copy goes out of scope?

    - Each member is copied from the source object.
    - The pointer is only copied, NOT what is points to! (This is Shallow Copying)
    
    - Problem: When we release the storage in the destructor, the other object still refers to the released storage.
    
    - ex)

        class Shallow {
        private:
            int *data;

        public:
            Shallow(int d);                     // constructor
            Shallow(const Shallow &source);     // copy constructor

            ~Shallow();                         // destructor 
        };  

    - Implementation of the copy constructor:

        Shallow::Shallow(int d) {
            data = new int;                     // allocate storage
            *data = d;              
        }

    - Implementation of the destructor:

        Shallow::~Shallow() {
            delete data;            // free storage
            std::cout << "destructor called" << "\n";
        }

    - Implementation of the copy constructor:

        Shallow::Shallow(const Shallow &source)
            : data{source.data} {
            
            std::cout << "copy constructor - shallow copying" << "\n"; 
        }  

    - Shallow copying: Only the pointer is copied. Not what it is pointing to! The problem is the source and the newly created 
        object BOTH point to the same data location!

    - Sample main(): Look for UB, and crashes!

        int main() {

            Shallow obj1 {100};                 // int of 100 is allocated onto the heap
            display_shallow(obj1);              // copy of obj1 will be created inside this function. When the function is done 
            // obj1's data has been released!       the copy of obj1 will be destroyed. The original obj1 now still points to the
                                                    same location which is invalid storage since the copy deleted it.

            obj1.set_data_value(1000)           // this might result in a crash, or an error
            Shallow obj2 {obj1};

            std::cout << "Hello" << "\n";

            return 0;
        }

Deep Copying with the Copy Constructor:
    - Creates a copy of the pointed to data. 
    - Each copy will have a pointer to unique storage on the heap.
    - We use Deep copying when we have a raw pointer as a class data member.
    - Instead of copying the pointer, we copy the data that the pointer is pointing to.
    - We usually need to allocate storage first and then perform the copy.

    - ex) Deep:

        class Deep {
        private:
            int *data;                      // pointer

        public:
            Deep(int d);                    // constructor
            Deep(const Deep &source);       // copy constructor
            ~Deep()                         // destructor
        }

    - Implementing the Deep Constructor using Shallow copy:

        Deep::Deep(int d) {
            data = new int;                 // allocate storage on the heap
            *data = d;
        }

    - Destructor implementation:

        Deep::~Deep() {
            delete data;                    // free storage
            std::cout << "Destructor called " << "\n";
        }

    - Implementation the Deep Constructor using Deep copy:

        Deep::Deep(const Deep &source) {
            data = new int;                 // allocate storage
            *data = *source.data;
            std::cout << "Copy constructor - Deep Copying" << "\n";
        }

    - Deep copying creates new storage and copy values.

Deep Copying Constructor - Delegating Constructor:
    
    Deep::Deep(const Deep &source) 
        : Deep {*source.data} {
        std::cout << "Copy Constructor - Deep" << "\n";
    }

    - Delegate to deep(int) and pass in the int(*source.data) source is pointing to.

    - ex)

    void display_deep(Deep s) {
        std::cout << s.get_data_value() << "\n";
    }

    - When s goes out of scope the destructor is called and releases data, this is no longer a problem since the storage being
        released is unique to s.

    - Sample main:

        int main() {
            Deep obj1 {100};
            display_deep(obj1);

            obj1.set_data_value(1000);
            Deep obj2 {obj1};
        }

    - This code will run without crashing.

Move Constructors and Move Semantics:
    - Introduced in C++11
    - In order to understand move semantics, we need to be familiar with L-Values and R-Values.
        - Remember that if an object is addressable then it is a L-Value.
        - R-Values are everything else.
    - In move semantics, R-Values refer to the temporary objects that are created by the compiler, and the objects returned from
        methods.
    - ex) 

        int total {0};
        total = 100 + 200;

        - 100 and 200 are evaluated, and 300 is stored in an unnamed temp value. 300 is then stored in the variable total. temp
            is then discarded.
        - 300 is not addressable, it's an R-Value, then assigned to the L-Value total
        - The same thing happens to objects as well in regards to classes.

    - When to use Move Constructors / Move Semantics?
        - Sometimes copy constructors are called many times automatically due to the copy semantics in C++.
        - Copy constructors during Deep Copying can have significant performance bottlenecks.
        - C++ 11 introduced Move Semantics and the Move Constructor. Move Constructor move an object rather than copying it.
        - It's optional, but recommended when we have raw pointers. Remember that if we have a raw pointer, then we must 
            implement Deep Copying which can be expensive.
        - Copy elision: C++ may optimize copying away completly (RVO - Return Value Optimization)

    - R-Value References:
        - Used in Moving Semantics and Perfect Forwarding.
        - Move Semantics is all about R-Value references.
        - Used by the move constructor and move assignment operator to efficiently move an object rather than copying it.
    
    - R-Value Reference Operator ( && )

    - ex) l_values:

        int x {100};
        int &l_ref = x;         // l-value reference, l_ref is a reference to x
        l_ref = 10              // change x to 10

        int &&r_ref = 200;      // r-value ref, 200 is not addressable, so it's an r-value 
        r_ref = 300;            // change r_ref to 300

        int &&x_ref = x;        // this will result in a compiler error since x is addressable

    ex) r_values:

        int x {100};            
        int &l_ref = x;         // l-value reference
        l_ref = 10;             // change x to 10

        int &&r_ref = 200;      // r-value reference
                                // remember that this is a reference to the actual variable, it is refering to a temp variable

        r_ref = 300;            // change r_ref to 300
        int && x_ref = x        // compiler Error
                                // trying to assign an l-value to an r-value reference

    - l-value reference parameters in functions:

        int x {100};            // x is an l-value
        
        void func(int &num);    // A
                                // wants an l-value as an arugment (single &) 

        func(x);                // calls A: x is an l-value
        func(200);              // Error: 200 is an r-value 

        Error: Cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'

    - r-value reference parameters in functions:

        int x {100};            // x is an r-value

        void func(int &&num);   // B
                                // wants an r-value as an argument (double &&)
        
        func(200);              // calls B: 200 is an r-value
        func(x);                // Error: x is an l-value 

        Error: Cannot bind rvalue reference of type 'int&&' to an lvalue of type 'int'

    - Both l and r values function signitures:
        overloaded functions:
        void func(int &num);    // A
        void func(int &&num);   // B 

        func(x);                // calls A
        func(200);              // calls B

Creating the Move Constructor
    - Move Class:

        class Move {
        private:
            int *data;          // raw pointer

        public:
            void set_data_value(int d) {
                *data = d;
            }

            void get_data_value() {
                return *data;
            }

            Move(int d);                // constructor
            Move(const Move &source);   // copy constructor

            ~Move();                    // destructor    

        };

    - Implementing the copy constructor (deep copy):

        Move::Move(const Move &source) {
            data = new int;
            *data = *source.data;       // allocates storage and copies 
        }

    - inefficient copying 

        std::vector<Move> vec;
        vec.push_back(Move{10});
        vec.push_back(Move{20});

        // Move{10} and Move{20} are creating temporary objects, they're unnamed, they will be r-values 
        // this is inefficient, due to the copy constructor being called several times. It is better to implement the 
            move constructor

    - Implementing the Move constructor:
        - Instead of making a deep copy, the move constructor will 'move' the resource.
        - Simply copies the address of the resource from source to the current object.
        - NULLs out the pointer in the source pointer.
        - Very efficient.

        - General syntax:

        Type::Type(Type &&source);  // no const qualifier for the parameter source. There can't be a const, we need to modify
                                        it in order to null out the pointer

        Player::Player(Player &&source);
        Move::Move(Move &&source);

    - Implementing the Move Constructor in the Move class (Line 233)

        Move::Move(Move &&source)
            : data {source.data} {
            
            source.data = nullptr;
        }

    - We add this move construcor to Line 250
    - The Move Constructor will 'steal' the data, and then NULL out the source pointer.
*/


#include <iostream>


int main() {

    return 0;
}
