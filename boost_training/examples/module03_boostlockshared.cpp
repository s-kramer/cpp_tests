#include <iostream>
#include <boost/thread.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <boost/date_time.hpp>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
std::vector<std::string> myVector;
boost::shared_mutex myMutex;
void czytelnik(int mytime, const char * c ) {
	boost::posix_time::milliseconds myTime(mytime);
	std::ostream_iterator<std::string> it(std::cout, c);
	for(int i = 0; i < 20; ++i) {
		boost::this_thread::sleep(myTime);
		myMutex.lock_shared();
		copy(myVector.begin(), myVector.end(), it);
		std::cout << '\n';
		myMutex.unlock_shared();
	}
}
void pisarz(int mytime, const char * name) {
	boost::posix_time::milliseconds myTime(mytime);
	for(int i = 0; i < 5; ++i) {
		boost::this_thread::sleep(myTime);
		myMutex.lock();
		boost::this_thread::sleep(myTime);
		myVector.push_back(name);
		myMutex.unlock();
	}
}
int main(int argc, char* argv[]) {
	boost::thread cz1(&czytelnik, 600, "*");
	boost::thread cz2(&czytelnik, 450, "+");
	boost::thread p1(&pisarz, 1000, " dane1 ");
	boost::thread p2(&pisarz, 1500, " dane2 ");
	cz1.join(); cz2.join(); p1.join(); p2.join();
	return 0;
}
