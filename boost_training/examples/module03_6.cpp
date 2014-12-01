#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/thread/barrier.hpp>
#include <boost/date_time.hpp>
boost::barrier bariera(2);
void thr(int i) {
	boost::posix_time::seconds mySec(i * 2);
	boost::this_thread::sleep(mySec);
	std::cout << "Tu w±tek z przekazanym parametrem: " << i << "\n";
	bariera.wait();
	std::cout << "Tu w±tek z przekazanym parametrem: " << i
			<<" kontynujê...\n";
}
int main(int argc, char* argv[]) {
	boost::thread thr1(&thr, 1);
	boost::thread thr2(&thr, 2);
	thr1.join();
	thr2.join();
}
