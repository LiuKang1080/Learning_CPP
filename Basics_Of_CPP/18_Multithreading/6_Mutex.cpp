// Solving Data Races in C++ Using Mutex

/*
Protecting Shared Data With Mutexs:
    - What if we can tell all the threads except one to wait until the thread is done modifying the data?
    - We can use Synchronization Primitive called a Mutual Exclusion (mutex).
    - Before accessing a shared data structure, we LOCK the mutex associated with the data, and then when we're done accessing the
        data we UNLOCK the mutex.
    - Mutexes isn't the ultimate tool, we can still run into deadlocks, and protect the data too much or too little.
    
    - We start by constructing a mutex instance with std::mutex, we then call lock() to lock the mutex, and then call unlock()
        when we're done with the mutex.
    - It is BAD practice to call lock() on every memeber function on every code path, because we need to remember unlocking it
        for each instance we call lock(). Instead the C++ standard provides the std::lock_guard class template.
    - std::lock_guard implements RAII principles for the mutex, it locks it on construction, and unlocks it on destruction.
    
    - In order to use std::mutex and std::lock_guard, we must first #include the <mutex> header file.
    - Ex) Lock a list that is accessed by multiple threads using std::mutex, and std::lock_guard  

        #include <iostream>
        #include <thread>
        #include <mutex>
        #include <list>
        #include <algorithm>

        std::list some_list;
        std::mutex some_mutex;

        void add_to_list(int new_value) {
            atd::lock_guard<std::mutex> guard(some_mutex);
            some_list.push_back(new_value);
        }

        bool list_contains(int value_to_find) {
            std::lock_guard<std::mutex> guard(some_mutex);
            return std::find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
        }

    - Here we a single global variable called some_list.
    - some_list is protected with a corresponding global instance of std::mutex called some_mutex.
    - The use of std::lock_guard<std::mutex> in add_to_list() and list_contains() means that the access in the functions are
        mutually exclusive. list_contains() will never see the list partway through modification by add_to_list().
    
    - In C++17 std::lock_guard<std::mutex> guard(some_mutex); can be reduced to std::lock_guard guard(some_mutex);
    - C++17 also contains std::scoped_lock so we can write the above as: std::scoped_lock guard(some_mutex);

    - Generally global variables are not a good idea, and instead we group the mutex with the protected data together in a class.
    - Therefore add_to_list() and list_contains() functions would be member functions of a class.
    - The data and mutex will be private members.
    
    - Any code that has access to pointers and references that access the protected data can now access the potentially modify
        the data WITHOUT locking the mutex. We need to ensure that the mutex is locked BEFORE there is any access to the
        protected data, and that there are no backdoors.
    - We cannot just put std::lock_guard<std::mutex> on every member function. Any pointer or reference can make the protection
        worthless.
    - It's also important to check that member functions don't pass pointers or references into other functions, especially
        functions that we do not own!
*/


#include <iostream>
#include <thread>
#include <mutex>
#include <functional>


void increment_account(std::mutex &account_MUTEX, int &account_value, int amount) {
    // lock this function for the threads:
    std::lock_guard<std::mutex> guard(account_MUTEX);
    std::cout << "The account value is: " << account_value << "\n";
    std::cout << "Amount being added in: " << amount << "\n";
    account_value += amount;
    std::cout << "The account value is now: " << account_value << "\n";
    std::cout << "======= \n";
}


int main() {
    int account_value = 100;
    std::mutex account_value_MUTEX;
    /*
        - We create a "global" variable account_value, and the mutex that will protect it.
        - We will pass in the mutex, the account_value, and the amount we want to add to the account into the increment_account
            function.
        - We then create 2 threads that will run that function, but because we're using mutexes, only 1 thread will modify the
            variable account_value at any given time. The other threads must wait until the current thread is done changing the
            data.
        - We MUST pass the mutex by wrapping it in std::ref(), and passing it by reference!
    */

    // create 2 threads that will add to the account
    std::thread t1(increment_account, std::ref(account_value_MUTEX), std::ref(account_value), 25);
    std::thread t2(increment_account, std::ref(account_value_MUTEX), std::ref(account_value), 50);

    t1.join();
    t2.join();

    return 0;
}
