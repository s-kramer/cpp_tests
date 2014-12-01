#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

class Seaman {
	public:
		Seaman(const unsigned width, const unsigned sTm = 100) 
			: wayWidth(width), position(width/2), baseSleepTime(sTm) { }
		void run() {
				thrLeft = new std::thread(&Seaman::slope, this, -1);
				thrRight = new std::thread(&Seaman::slope, this, 1);
				thrLeft->join();
				thrRight->join();
		}
	private:
		unsigned position;
		unsigned wayWidth;
		unsigned baseSleepTime;
		std::mutex seamanMutex;
		std::thread * thrLeft;
		std::thread * thrRight;
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
			std::chrono::milliseconds myTime(baseSleepTime-change);
			//boost::posix_time::milliseconds myTime(baseSleepTime+change);
			while(true) {
				seamanMutex.lock();
				position += change;
				showWay();
				if((position < wayWidth ) and (position >0 )) {
					seamanMutex.unlock();
					std::this_thread::sleep_for(myTime);
				} else  {
					break;
				}
			}
			if (std::this_thread::get_id() == thrRight->get_id()) {
				exit(0);
			} else {
				exit(0);
			}
		}
};

int main(int argc, char* argv[]) {
	Seaman* mySeaman = new Seaman(12);
	mySeaman->run();
}
