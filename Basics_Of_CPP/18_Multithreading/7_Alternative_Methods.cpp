// Alternative Methods to Protect Shared Data in C++

/*
Alternative Ways to Protect Shared Data:
    - There are other ways than just mutexes in protecting shared data.
    - One case is that data needs protection from concurrency only when it is being initialized, but not after that it is no
        longer required.
    - Using a mutex just for initialization is not worth it due to the hit performance.
    - Ex)

        std::shared_ptr<some_resource> resource_ptr;
        
        void foo() {
            if (!resource_ptr) {
                resource_ptr.reset(new some_resource);
            }

            resource_ptr->do_something();
        }

    - If this was multithreaded then the line "resource_ptr.reset(new some_resource);" needs to be protected since it is the
        common critical shared data.
    - If we were to just throw mutex into this code, then our code would look like this:

        std::shared_ptr<some_resource> resource_ptr;
        std::mutex resource_MUTEX;

        void foo() {
            std::unique_lock<std::mutex> lck(resource_MUTEX);
            // all threads are serialized here

            if (!resource_ptr) {
                resource_ptr.reset(new some_resource);
                // only the initialization needs protection
            }

            lck.unlock();
            resource_ptr->do_something();
        }

    - This is common enough that other programmers have tried to write this code better. First we check the pointer to see if
        it's NULL, if it is NULL then we lock it. We then check the pointer again once it's locked, this is what is known as
        [double-checking locks]
    
        void undefined_behavior_with_double_checked_locking() {
            if (!resource_ptr) {
                std::lock_guard<std::mutex> lck(resource_MUTEX);
                if (!resource_ptr) {
                    resource_ptr.reset(new some_resource);
                }
            }

            resource_ptr->do_something();
        }

    - This has potential for bad race conditions because the first "if (!resource_ptr)" is read outside the lock, it is not
        synchronized with the write done by other threads inside the lock. This is undefined behavior.
    - The C++ Standard adds the std::once_flag, and std::call_once methods to handle these situations.
    - Every thread can use std::call_once safe with the knowledge that the pointer will have been initialized by some other thread
        by the time std::call_once returns.
    - Here is what our code looks like now with the new std::call_once() and std::once_flag():

        std::shared_ptr<some_resource> resource_ptr;
        std::once_flag resource_flag;

        void init_resource() {
            resource_ptr.reset(new some_resource);
        }

        void foo() {
            std::call_once(resource_flag, init_resource);
            // initialization is called exactly once
            
            resource_ptr->do_something();
        }

    - Here the std::once_flag() and data being initialized are namespace-scope objects.
    - std::flag_once() initializes like std::mutex, it CANNOT be copied or moved.
*/


#include <iostream>
#include <thread>
#include <mutex>


int main() {

    return 0;
}
