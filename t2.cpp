#include <iostream>
#include <thread>
#include <chrono>


void sleepFor(int sec)
{
    std::this_thread::sleep_for (std::chrono::seconds (sec));
    std::cout << sec << " pause ended\n";
}

void foo(int sleepTime)
{
    std::this_thread::sleep_for(std::chrono::seconds(sleepTime));
    std::cout << "Hello from thread with sleep time: " << sleepTime << " seconds\n";
}

int main()
{
    std::cout << "Program starting...\n";
    std::thread welcomeMessageThread (foo, 2);
    welcomeMessageThread.join();

    std::thread t1 (sleepFor, 3);
    std::thread t2 (sleepFor, 3);
    std::thread t3 (sleepFor, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
