#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/date_time.hpp>
boost::mutex countMutex;
int counter = 100;
void count(int increment) {
	std::cout << "Wejscie w watek\n" << std::flush;
	boost::posix_time::milliseconds mySleep(1);
	for (int i = 0; i < 100; ++i) {
		boost::mutex::scoped_lock lock(countMutex);
		boost::this_thread::sleep(mySleep);
		counter += increment;
		std::cout << "Zmiana licznika na: " << counter << "\n";
	}
	std::cout << "Koniec watku\n" << std::flush;
}
int main(int argc, char* argv[]) {
	boost::thread thrd1(&count, 1);
	boost::thread thrd2(&count, -1);
	thrd1.join(); thrd2.join();
	return 0;
}
