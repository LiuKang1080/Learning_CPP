// Multithreading and Concurrency in C++

/*
Concurrency in C++:
    - C++11 finally and officialy supported multithreading and concurrecy.
    
    - What is concurrency?
        - 2 or more seperate activities happening at the same time. A single system performing multiple independent activities in
            parallel, rather than sequentially.

    - Task Switching = By doing a bit of 1 task, but then switching between the tasks several times per second. By doing 1 task
        and then a bit of another, it appears that the tasks happening concurrently.

    - Concurrency Vs. Parallelism:
        - They both have overlapping meanings with respect to multithreading code.
        - There are a lot of similarities, but there are some very small differences. Where parallelism is much more performance
            orientated.
        - People talk about parallelism when the primary concern is taking advantage of the available hardware to increase
            performance of bulk data processing.
        - People talk about concurrency when the primary concern is seperation of concerns or responsibilities.

    - Why use concurrency?
        - There are 2 main reasons. 1) Seperation of concerns. 2) Performance

        1) Seperation of Concerns:
            - Grouping related bits of code together and keeping unrelated bits of code apart.
        
        2) Concurency for Performance:
            - There are 2 ways to use concurency for performance

            1) Divide the task into parts and run each in parallel.

            2) Use the available parallelism to solve bigger problems rather than processing 1 file at a time, process 2 files or
                more. This is called data parallelism. Performing the same operation on multiple sets of data concurrently.

When to NOT Use Concurrency?
    - The only reason not to use concurrency is when the benefit isn't worth the cost.
    - There is also a direct intellectual cost to writing and maintaining multithreading code.
    - The performance gain may not be as large as expected.
    - Threads are a limited resource. If we have too many threads running at once, the OS will protentially slow down, and
        become unresponsive.
    - Each thread can exhaust the available memory or address space for processes. Each thread requires a seperate stack
        space. 32 bit processors have a limit of 4GB. With 1MB per stack on average, this allows us 4,096 threads total,
        without any space for code, static data, or heap data.
    - Even though 64 bit processors have a higher limit compared to 32 bit, the resource is not infinite, they still have limited
        resources.

The 1st Concurrent "Hello World" Program:
    - We know how to do a standard Hello World:

        #include <iostream>
        
        int main() {
            std::cout << "Hello World! \n";

            return 0;
        }

    - The concurrent / multithreading Hello World:

        #include <iostream>
        #include <thread>

        void hello() {
            std::cout << "Hello Concurrent World! \n";
        }

        int main() {
            std::thread t(hello);
            t.join();

            return 0;
        }

    - In order to use multithreading features, we need to #include the <thread> header file.
    - We moved std::cout into its own seperate function.
    - EVERY thread requires an initial function. For the initial thread in an application this is main(). For every other thread
        it must be specified in the constructor of the std::thread object. In this example it is t. For this thread hello() is
        the initial function.
    - The initial thread starts at main(), the new thread starts at hello().
    - After this new thread has been launched, the initial thread continues execution if it didn't wait for the new thread to
        finish. It will continue to the end of main() and end the program possibly before the new thread had a chance to run, this
        is why we call join(). This causes the calling thread in main() to wait for the thread associated with the std::thread
        object, in this case t.
*/


#include <iostream>
#include <thread>


void hello() {
    // new thread print
    std::cout << "Hello Concurrent World! \n";
}


int main() {
    std::thread t(hello);

    // main thread print
    std::cout << "Hello World! \n";

    t.join();

    return 0;
}
