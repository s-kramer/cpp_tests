#include <iostream>
#include <future>
#include <string>
#include <thread>
#include <stdexcept>


void threadedFunction(std::promise<std::string> & outputMessage)
// void threadedFunction(std::promise<std::string> && outputMessage)
{

    try {
        std::string temporarMessage("Hello from the threaded function");
        throw( std::invalid_argument(std::string( "Exception from the future" ) ) );
        // std::cout << (void*)temporarMessage.data() << '\n';
        outputMessage.set_value(temporarMessage);
        // Move here is redundant, the value is moved anyway.
        // outputMessage.set_value( std::move( temporarMessage ) );
    }
    /* Pass the exception to the main thread */
    catch (...) {
        outputMessage.set_exception(std::current_exception());
    }
}

int main()
{
    std::promise<std::string> promise;
    auto future = promise.get_future();

    /* std::promise may be passed by move (which invalidates it for the rest
     * of the code) or by reference (which doesn't invalidate it)*/
    std::thread thread(&threadedFunction, std::ref(promise));
    // std::thread thread(&threadedFunction, std::move(promise));

    thread.join();
    std::string message;

    try {
        /* The future.get() moves the value so we can do it only once. */
        message = future.get();
    }
    catch (std::exception& exception) {
        std::cout << exception.what() << '\n';
    }
    
    std::cout << "Message received from the thread: " << message << '\n';
    // std::cout << (void*)message.data() << '\n';
    return 0;
}
