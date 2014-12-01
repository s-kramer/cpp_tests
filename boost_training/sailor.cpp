#include <iostream>
#include <boost/date_time.hpp>
#include <boost/thread.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/atomic.hpp>

class Sailor
{
public:
    explicit Sailor (void) : MAX_WIDTH(20),  position(10)
    {
        // m.lock();
        tLeft.reset(new boost::thread(&Sailor::moveLeft, this));
        tRight.reset(new boost::thread(&Sailor::moveRight, this));
    }

    void displayPosition(void)
    {
        temporar_position = position.load();
        for (unsigned i = 0; i < temporar_position; i++) 
        {
            std::cout << " ";
        }
        std::cout << "*" << std::endl;
    }

    void startSailor(void)
    {
        // m.unlock();
        tLeft->join();
        tRight->join();
    }

    void moveLeft(void)
    {
        while(1)
        {
            {
                // boost::lock_guard<boost::mutex> l(m);
                temporar_position = position.fetch_add(-1);
            }

            if (position == 0) 
            {
                tRight->interrupt();
                return;
            }

            displayPosition();
            boost::this_thread::sleep(boost::posix_time::milliseconds(90));
        }
    }

    void moveRight(void)
    {
        while(1)
        {
            {
                // boost::lock_guard<boost::mutex> l(m);
                // temporar_position = ++position;
                temporar_position = position.fetch_add(1);
            }

            if (temporar_position == MAX_WIDTH) 
            {
                tLeft->interrupt();
                return;
            }
            displayPosition();
            boost::this_thread::sleep(boost::posix_time::milliseconds(100));
        }
    }

private:
    const unsigned int MAX_WIDTH;
    boost::shared_ptr<boost::thread> tLeft, tRight;
    // boost::mutex m;
    // unsigned position;
    // boost::atomic_int position;
    boost::atomic<int> position;
    unsigned temporar_position;
};

int main()
{
    Sailor s;
    s.startSailor();
    return 0;
}
