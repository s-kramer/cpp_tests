#include <iostream>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>
int longCalc() {
	// Dlugie obliczenia
	boost::posix_time::seconds s(3);
	boost::this_thread::sleep(s);
	return 2 * 2;
}
int main(int argc, char* argv[]) {
	boost::packaged_task<int> myPackagedTask(longCalc);
	boost::unique_future<int> myFuture = myPackagedTask.get_future();
	// Uruchomienie zadania w watku
	boost::thread myTask(boost::move(myPackagedTask));
	// Czekamy na zakonczenie zadania zawieszajac
	// dzialanie glownego programu
	myFuture.wait();
	std::cout << "Dane sa dostepne: " << myFuture.is_ready() << '\n';
	std::cout << "Dane sa wartoscia: " << myFuture.has_value() << '\n';
	std::cout << "Rzucano wyjatek: " << myFuture.has_exception() << '\n';
	std::cout << "Stan danych wykonania to ready: " << (myFuture.get_state()
		== boost::future_state::ready) << '\n';
	std::cout << "Wynikiem jest: " << myFuture.get() << '\n';
	return 0;
}
