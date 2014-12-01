#include <iostream>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>
class Watek {
	private:
		char znak;
		boost::posix_time::milliseconds sleep;
	public:
		Watek( char _znak, unsigned int _sleep)
		: znak(_znak), sleep(_sleep) { }
		void operator()() {
			for (int i = 0; i < 100; i++) {
				std::cout << znak << std::flush;
				boost::this_thread::sleep(sleep);
			}
		}
};
int main(int argc, char* argv[]) {
	Watek w1('-', 15);
	Watek w2('*', 20);
	boost::thread sW1(w1);
	boost::thread sW2(w2);
	sW1.join();
	sW2.join();
}
