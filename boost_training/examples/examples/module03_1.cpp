#include <iostream>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>

void funThread() {
	boost::posix_time::seconds czasOczekiwania(5);
	std::cout << "Zg�asza si� w�tek i czas leci...\n";
	boost::this_thread::sleep(czasOczekiwania);
	std::cout << "Koniec w�tku\n";
}
int main(int argc, char* argv[]) {
	std::cout << "G��wny program\n";
	boost::thread obiektWatku(funThread);
	std::cout << "Czekam na przy��czenie do w�tku"
		<< " po jego zako�czeniu\n";
	obiektWatku.join();
	std::cout << "Koniec g��wnego programu\n";
	return 0;
}
