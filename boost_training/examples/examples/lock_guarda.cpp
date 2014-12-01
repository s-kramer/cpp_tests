#include <iostream>
#include <boost/thread.hpp>
#include <boost/thread/locks.hpp>
boost::mutex myMutex;
void thr() {
	boost::lock_guard<boost::mutex> lock(myMutex);
	std::cout << "W±tek po przejeciu blokady.\n";
	std::cout << "Koniec w±tku.\n";
}
int main(int argc, char* argv[]) {
	myMutex.lock();
	// Tworzenie watkow ktore zatrzymaja sie 
	// na blokadzie
	std::cout << "Start programu.\n";
	boost::thread t1(&thr);
	boost::thread t2(&thr);
	// Zdjecie blokady, watki ruszaja
	myMutex.unlock();
	t1.join(); t2.join();	
	std::cout << "Koniec programu.\n";
	return 0;
}
