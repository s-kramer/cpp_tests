#include <iostream>
#include <string>
#include <boost/thread.hpp>
class MyThread {
	private:
		std::string name;
	public:
		MyThread(std::string _name)
		: name(_name) {}
		void go(int w) {
			std::cout << "Zg³asza siê obiekt " << name
				<< " bêdê produkowa³: " << w << std::endl;
			for(int i = 0; i < 100; i++) {
				std::cout << w << std::flush;
			}
		}
};
int main(int argc, char* argv[]) {
	MyThread t1("obiekt1"); MyThread t2("obiekt2");
	boost::thread runThread1(&MyThread::go, &t1, 1);
	boost::thread runThread2(&MyThread::go, &t2, 2);
	runThread1.join(); runThread2.join();
	return 0;
}
