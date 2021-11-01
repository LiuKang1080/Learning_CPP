// Sharing Data Between Threads In C++

/*
Sharing Data Between Threads:
    - Concurrency allows us to share data between threads, but there are rules we must follow when sharing data between threads.
    - We need to pay attention to which thread can access data and when. How are the threads going to communicate between the
        other threads?
    - Incorrect use of sharing data can be devestating; resulting in crashing programs, undefined behavior, and untrackable bugs

    - The main problem between sharing data is due to the consequence of modifying data. If shared data is read-only, then there
        is no problem, but if the threads can modify the data then there is potential for trouble.
    
    - Race Conditions = In concurrency, a race condition is anything where the outcome depends on the relative ordering of
        execution of operations on 2 or more threads. The threads race to perform their respective operations.
    - Ex) 2 threads are adding items to a queue for processing, it generally doesn't matter in the order of which items gets added
        first, provided that the invariants are maintained.
    - Data Races in the C++ Standard means that concurrent modifications to a single object. Data Races cause Undefined Behavior!
    - Problematic Race Conditions = Typically occurs when completing operations requires modifications on 2 or more distinct
        pieces of data. This event must be modified in seperate intructions, and another thread could potentially access data
        structures when only 1 of them has been completed.
    - Race conditions are often hard to find and duplicate because the window of opportunity is very small. Since race conditions
        are generally time sensitive, they OFTEN dissappear entirely when the application is run under a debugger!

Avoiding Problematic Race Conditions:
    - There are several ways to deal with race conditions.
    - The simplest one is to wrap data structures with a protection mechanism to ensure that the thread performing a modification
        can see the intermediate states where the invariants are borken. From the point of view of other threads the
        modifications either haven't started or have completed.
    - Another option is to modify the design of your data structure so that the modifications are done in such a way which preserves
        the invariants. This is known as [lock-free programming].
    - Another way is to handle the updates to the data structures as transactions. The data modifications and reads are stored in
        a transaction log and then committed in a single step. If it cannot commit the transaction, then it is restarted. This
        is known as [Software Transactional Memory (STM)]. There is no direct support in C++, and is currently being researched.
    - The most basic mechanism for protecting shared data in the C++ Standard is the [MUTEX].
*/


#include <iostream>
#include <thread>


int main() {

    return 0;
}
