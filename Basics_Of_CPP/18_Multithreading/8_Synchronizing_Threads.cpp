// Synchronizing Concurrent Operations in C++

/*
Synchronizing Threads:
    - Sometimes we need to synchronize the actions that are done on seperate threads.
    - One thread might need to wait for another thread to finish, before it can complete its own task.
    - The C++ Standard allows us to do this by providing [condition variables] and [futures]. There are additional operations for
        futures in the form of [latches] and [barriers].
    
    - Waiting for an event or other conditions:
    - We could have a thread that is waiting for the other thread check to see the status of the other thread, by checking the
        mutex status. When the 2nd thread's task is done it can set the flag, then the 1st thread can now start its process.
    - This is very inefficient since we have the 1st thread constantly checking to see if the flag is there from the 2nd thread.
    - When the mutex is locked by the thread that is waiting, it cannot be locked by any other thread.
    - A second option is is to have the waiting thread sleep for short periods of time between the checks using
        std::this_thread::sleep_for() function.
    - Ex)

        bool flag;
        std::mutex m;

        void wait_for_flag() {
            std::unique_lock<std::mutex> lck(m);

            while (!flag) {
                lck.unlock();
                // unlock the mutex

                std::this_thread::sleep_for(std::chrono::miliseconds(100));
                // sleep for 100 seconds

                lck.lock();
                // relock the mutex
            }
        } 

    - In the loop, the function unlocks the mutex before the sleep, and locks it again afterwards so another thread gets a chance
        to acquire it and set the flag.
    - This option is better than constantly checking but we're still unsure on the length of sleep. It's hard to figure out how
        long to sleep. If we sleep too shot the task might not finish. If we sleep too long certain programs might feel
        unresponsive.
    - The 3rd option is the use the provided functions from the C++ Standard and to wait for the even itself. The most basic
        mechanism for waiting for an event to be triggered by another thread is the condtion variable.
    - A condition variable is associated with an event or condition, and one or more threads can wait for that condition to be
        satisfied. When a thread has determined that the condition is satisfied, it can they notify the other threads waiting on
        the condition variable in order to wake them up so they can start processing.

Waiting For A Condition with Condition Variables:
    - The C++ Standard provides 2 implementations for a condition variable:
        [std::condition_variable] and [std::condition_variable_any]
    - In order to use them we must first #include the <condition_variable> header file.
    - Both of them require working with a mutex, the former is limited working with just std::mutex. The second one can work 
        with anything that meets the minimal criteria for being mutex like.
    - std::condition_variable should be preffered over the _any version, unless the additional flexibility is required.
    - Ex)

        std::mutex mut;
        std::queue<data_chunk> data_queue;
        std::condition_variable data_condition;

        void data_preperation_thread() {
            while (more_data_to_prepare()) {
                data_chunk const data = prepare_data(); {
                    std::lock_guard<std::mutex> lck(mut);
                    data_queue.push(data);
                }

                data_condition.notify_one();
            }
        }

        void data_processing_thread() {
            while (true) {
                std::unique_lock<std::mutex> lck(mut);
                data_condition.wait(lck, []{return !data_queue.empty();});
                data_chunk data=data_queue.front();
                data_queue.pop();
                lck.unlock();
                process(data);

                if (is_last_chunk(data)) {
                    break;
                }
            }
        }

    - Here we have a queue "std::queue<data_chunk> data_queue;" that is used to pass the data between the 2 threads.
    - When the data is ready, the thread preparing the data locks the mutex protecting the queue using std::lock_guard, and
        pushes the data onto the queue.
    - The thread then calls the notify_one() member function on the std::condition_variable instance to notify the waiting
        thread (if there is one) "data_condition.notify_one();".
    - On the other thread, the processing thread, the thread first locks in the mutex. This time with the std::unique_lock rather
        than std::lock_guard, the thread then calls wait() on the std::condition_variable. Passing in the lock object and a
        lambda function that express the condition being waited for "data_condition.wait(lck, []{return !data_queue.empty();});".
    - the wait() checks the condition by calling the supplied lambda function and returns if it's satisfied. When the condition
        variable is notified by a call to notify_one() from the data-preperation thread, the thread wakes from its slumber 
        (unblocks it), requires the lock on the mutex, and checks the condition again. If the thread condition hasn't been
        satisfied, the thread unlocks the mutex and resumes waiting. This is why we use the std::unique_lock rather than std::lock_guard
        Te waiting thread must unlock the mutex while it's waiting, and lock it again afterwards.
*/


#include <iostream>
#include <thread>
#include <condition_variable>


int main() {

    return 0;
}
