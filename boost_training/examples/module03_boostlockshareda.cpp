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
