#include <iostream>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>
int longCalc() {
	// Dlugie obliczenia
	boost::posix_time::seconds s(3);
	boost::this_thread::sleep(s);
	return 2 * 2;
}
void realLazyCalc(boost::packaged_task<int>& myTask) {
	try {
		std::cout << "Leniwie liczymy.\n";
		myTask();
	} catch (boost::task_already_started&) {
	}
}
int main(int argc, char* argv[]) {
	boost::packaged_task<int> myPackagedTask(longCalc);
	myPackagedTask.set_wait_callback(realLazyCalc);
	boost::unique_future<int> myFuture = myPackagedTask.get_future();
	// Jesli zakomentujesz ponizsza linie z get(), obliczenia nie beda
	// wykonane!
	//std::cout << "Wynikiem jest: " << myFuture.get() << '\n';
	return 0;
}
