#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <vector>
#include <algorithm>
#include <mutex>

/*
 * class Lock
 * {
 * public:
 *     explicit Lock (std::mutex& mutex) : mutex_(mutex) { mutex_.lock(); };
 *     ~Lock () { mutex_.unlock(); };
 * private:
 *     std::mutex& mutex_;
 * };
 */

std::mutex printMutex;

class GenerateAsyncs
{
public:
    explicit GenerateAsyncs () {};
    std::future<void> operator()() 
    {
        return std::async(std::launch::async, []
        {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::lock_guard<std::mutex> lockGuard(printMutex);
            std::cout << std::this_thread::get_id() << '\n';
        });
    };
};

int main()
{
    std::cout << "Main thread id: \n" << std::this_thread::get_id() << '\n';

    std::vector<std::future<void>> futures;
    // futures.resize(10); // 1
    futures.reserve(10); // 2

    // std::generate_n(begin(futures), 10, GenerateAsyncs()); // 1
    std::generate_n(std::back_inserter(futures), 10, GenerateAsyncs()); // 2

    // std::generate_n(begin(futures), 10, []
    // {
        // return std::async(std::launch::async, [] 
        // {
        // std::cout << std::this_thread::get_id() << '\n';
        // });
    // });

    /*
     * for (int i = 0; i < 10; i++) {
     *     auto future = std::async(std::launch::async, []
     *     // auto future = std::async([]
     *     {
     *         // std::this_thread::sleep_for(std::chrono::seconds(2));
     *         std::cout << std::this_thread::get_id() << "\n";
     *     });
     *     // Future has no  copy constructor 
     *     futures.push_back(std::move(future));
     * }
     */

    // for_each(begin(futures), end(futures), [](const std::future<void>& future)
    // {
        /* Without wait() or get() the deferred asyncs scheduled in series 
         * on a single CPU won't be executed.
         */
        // future.wait();
    // });

    for(auto& future : futures) future.wait();

    std::cout << '\n';
    return 0;
}
