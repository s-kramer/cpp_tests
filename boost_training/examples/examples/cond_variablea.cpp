#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/date_time.hpp>
boost::condition_variable myCondition;
boost::mutex myMutex;
bool anyWork;
class Worker {
public:
	void run(int workerId) {
		boost::unique_lock<boost::mutex> lock(myMutex);
		boost::posix_time::milliseconds s(100);
		std::cout << "Uruchomienie w±tku: " << workerId << '\n';
		for(int i = 0; i < 3; ++i) { // Petla kilka razy...
			while(!anyWork) {
				myCondition.wait(lock);
				std::cout << workerId << ": obudzony.\n";
			}
			std::cout << workerId << ": wykonanie pracy.\n";
			boost::this_thread::sleep(s);
		}
	}
};
