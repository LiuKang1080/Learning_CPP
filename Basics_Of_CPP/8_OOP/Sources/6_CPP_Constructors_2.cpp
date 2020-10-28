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
*/


#include <iostream>


int main() {

    return 0;
}
