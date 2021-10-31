// Identifying Threads In C++

/*
Identifying Threads:
    - Thread identifiers are of the data type std::thread::id
    - We can obtain the associated std::thread object by calling the get_id() member function. If it does not have an associated
        thread then it returns a default-constructed std::thread::id object which indicates "not any thread".
    - We can also obtain the identifier for the current thread by calling std::thread::get_id(). This is also definied in the
        header file <thread>.
    - Objects of the data type std::thread::id can be freely copied and compared. If 2 objects of this data type are the same,
        then it means that they represent the same thread or are holding the "not any thread" value.
    - std::thread::id offers a complete set of comparison operators, this allows them to be used as keys in containers, sorted,
        or compared in any other way.
    - They behave like we expect them to behave during comparisons: If a < b, and b < c, then a < c.
    - The STL also provides std::hash<std::thread::id> so that values of the data type std::thread::id can be used as key in
        associated containers.
    
    - Instances of std::thread::id are often used to check whether a thread needs to perform some operation:
    - Ex) Threads dividing work. The initial thread is launched, and then the other threads might need to perform the work in a
        different way in the middle of an algorithm. Now it can call std::thread::get_id() before launching the other threads,
        and the core part of the algorithm which is common to all of the threads could check its own thread ID against the
        stored value.

        std::thread::id master_thread;
        void some_core_part_of_algorithm() {
            if (std::this_thread::get_id() == master_thread) {
                do_master_thread_work();
            }

            do_common_work();
        }
    
    - Since modern threading is built into the C++ standard it makes it easy to print the ID values of the current thread:

        std::cout << std::this_thread::get_id() << "\n";
*/


#include <iostream>
#include <thread>
#include <functional>


void func(const int &num) {
    std::cout << "========== \n";
    std::cout << "Thread func is called. \n"; 
    
    std::thread::id this_thread = std::this_thread::get_id();
    std::cout << "The current thread ID is: " << this_thread << "\n";
    std::cout << "It will perform the square of " << num << ": " << num * num << "\n"; 
}


int main() {
    std::cout << "main function called. \n";
    // set up variables:
    int num = 5;
    std::cout << "Value of num is: " << num << "\n";

    // create threads:
    std::thread t1(func, std::ref(num));
    std::thread t2(func, std::ref(num));
    t1.join();
    t2.join();

    std::cout << "End of main function. Value of num: " << num << "\n";

    return 0;
}
