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
		std::cout << "Uruchomienie wątku: " << workerId << '\n';
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
int main(int argc, char* argv[]) {
	// Tworzenie 3 funkcje wykonujace zadanie.
	Worker w1; Worker w2; Worker w3;	
	anyWork = false; // Jeszcze nie ma pracy do wykonania.
	boost::thread runW1(&Worker::run, &w1, 1);
	boost::thread runW2(&Worker::run, &w2, 2);
	boost::thread runW3(&Worker::run, &w3, 3); 
	boost::posix_time::seconds s(3);
	boost::this_thread::sleep(s);
	// Notyfikacja dla 1 lub wielu funkcji.
	anyWork = true;
	//myCondition.notify_one(); // lub 1 linia nizej...
	myCondition.notify_all();
	boost::this_thread::sleep(s);
	// Pytanie do sali, czego tu brakuje?
	return 0;
}
