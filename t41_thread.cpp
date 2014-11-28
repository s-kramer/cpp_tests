#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <functional>

void printGreeting(int &i)
{
    std::cout << "Hello from thread #" << i << "\n";
}

void createThreads(std::vector<std::thread> &threads)
{
    threads.reserve(20);
    int i = 0;
    for (; i < 10; i++) {
        /* Race here! */
        auto thread = std::thread([=]() {
                /* This pass by value acts ok when invoked with locally-scoped arguments */
                std::cout << "Hello from lambda thread #" << i << "\n";
                });
        threads.push_back( std::move( thread ) );
        /* Pass arguments for threaded function in thread constructor */
        /* Watch out for the lifetime of objects passed to threads by reference. The local objects may be already destroyed leaving dangling handles\references. */
        threads.push_back( std::move ( std::thread (&printGreeting, 
                                                    std::ref(i) ) ) );
    }
    /* Join here to prevent getting i out of scope (to keep the reference passed to the thread valid). */
}

int main()
{
    std::vector<std::thread> threads;

    std::cout << "Before thread\n";
    createThreads(threads);
    std::cout << "After thread\n";
    for_each(std::begin(threads),std::end(threads), [](std::thread& thread) {
            thread.join();
    });
    std::cout << "After joining\n";
    return 0;
}
