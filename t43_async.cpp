#include <iostream>
#include <thread>
#include <string>
#include <future>
#include <chrono>

std::string getMessage()
{
    std::string message("Hello from the future");
    // throw( std::invalid_argument( "Exception from task" ) );
    return message;
}

void printMessage(void)
{
    std::cout << "Starting the task from the thread\n";
    std::this_thread::sleep_for( std::chrono::seconds( 4 ) );
    std::cout << "Closing the task from the thread\n";
}

int main()
{
    auto future = std::async(&getMessage);
    std::cout << "Hello from the main thread\n";
    try {
        auto threadedMessage = future.get();
        std::cout << threadedMessage << '\n';
    }
    catch (std::exception& exception) {
        std::cout << exception.what() << '\n';
    }

    /* future::get() must be invoked on an async return value to make sure
     * that async was called, alternatively, use std::launch::async flag.
     */
    // auto anotherFuture = std::async(std::launch::async, &printMessage);
    auto anotherFuture = std::async(&printMessage);
    std::cout << "Exiting from the main function\n";
    anotherFuture.get();
    
    return 0;
}
