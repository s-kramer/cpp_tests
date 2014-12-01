#include <iostream>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>
void thrInterrupted() {
	boost::this_thread::disable_interruption di;
	std::cout << "A mnie si� przerwa� nie da przez 1 sek.\n";
	boost::posix_time::seconds s(1);
	boost::this_thread::sleep(s);
	std::cout << "Teraz da si� mnie przerwa�.\n";
	try {
		// Po opuszczeniu tego bloku kodu, zn�w przerywalny.
		boost::this_thread::restore_interruption ri(di);
		boost::this_thread::sleep(s);
	} catch (boost::thread_interrupted& e) {
		std::cout << "Ups, no to kto� chce mnie przerwa�\n";
	}
	std::cout << "No to czekam 5 sek. na przerwanie mnie ostateczne.\n";
	boost::this_thread::restore_interruption ri(di);
	boost::posix_time::seconds s5(5);
	boost::this_thread::sleep(s5);
	std::cout << "Nie doczeka�em si�...\n";
}
