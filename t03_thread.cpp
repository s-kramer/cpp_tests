// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread


class T3_thread
{
    public:
        T3_thread (int i):
            _i ( i)
        {}
        virtual ~T3_thread ()
        {}

        static void print(int i)
        {
            std::cout << i << '\n';
        }

        void print_public()
        {
            this->print_private();
        }
    private: //-thread function must be public

        void print_private ()
        {
            std::cout << "private " << this->_i << '\n';
        }

    private:
        int _i;
};

void bar(int x)
{
    std::this_thread::sleep_for (std::chrono::seconds (x));
    std::cout << "Done sleeping for " << x << " seconds\n";
}

void foo()
{
    bar(3);
}

void foobar (T3_thread* t3_thread)
{
    t3_thread->print_public();
}

int main() 
{

    T3_thread t3_thread(53);

    std::thread first (foo);     // spawn new thread that calls foo()
    first.join();                // pauses until first finishes

    std::thread second (bar,5);  // spawn new thread that calls bar(0)
    std::thread third (T3_thread::print, 53);
    std::thread fourth (foobar, &t3_thread);

    std::cout << "main, foo and bar now execute concurrently...\n";

    // synchronize threads:
    second.join();               // pauses until second finishes
    third.join();

    std::cout << "foo and bar completed.\n";

    return 0;
}
