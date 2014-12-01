#include <iostream>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>

void funThread() {
	boost::posix_time::seconds czasOczekiwania(5);
	std::cout << "Zg³asza siê w±tek i czas leci...\n";
	boost::this_thread::sleep(czasOczekiwania);
	std::cout << "Koniec w±tku\n";
}
int main(int argc, char* argv[]) {
	std::cout << "G³ówny program\n";
	boost::thread obiektWatku(funThread);
	std::cout << "Czekam na przy³±czenie do w±tku"
		<< " po jego zakoñczeniu\n";
	obiektWatku.join();
	std::cout << "Koniec g³ównego programu\n";
	return 0;
}
