#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/date_time.hpp>

class Seaman {
	public:
		Seaman(const unsigned width, const unsigned sTm = 100) 
			: wayWidth(width), position(width/2), baseSleepTime(sTm) { }
		void run() {
				thrLeft = new boost::thread(&Seaman::slope, this, -1);
				thrRight = new boost::thread(&Seaman::slope, this, 1);
				thrLeft->join();
				thrRight->join();
		}
	private:
		unsigned position;
		unsigned wayWidth;
		unsigned baseSleepTime;
		boost::mutex seamanMutex;
		boost::thread * thrLeft;
		boost::thread * thrRight;
		// Wyświetlenie pozycji
		void showWay() const {
			std::cout << "|";
			for (int i = 0; i < position; i++)
				std::cout << "-";
			std::cout << "*";
			for (int i = position; i < wayWidth; i++)
				std::cout << "-";
			std::cout << "|\n";
		}
		// Zmiana pozycji
		void slope(unsigned change) {
			// Jedna bądź druga linia by sprawdzić tendencję...
			boost::posix_time::milliseconds myTime(baseSleepTime-change);
			//boost::posix_time::milliseconds myTime(baseSleepTime+change);
			while(true) {
				seamanMutex.lock();
				position += change;
				showWay();
				if((position < wayWidth ) and (position >0 )) {
					seamanMutex.unlock();
					boost::this_thread::sleep(myTime);
				} else  {
					break;
				}
			}
			if (boost::this_thread::get_id() == thrRight->get_id()) {
				thrLeft->interrupt();
			} else {
				thrRight->interrupt();
			}
		}
};

int main(int argc, char* argv[]) {
	Seaman* mySeaman = new Seaman(12);
	mySeaman->run();
}