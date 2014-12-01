#include <iostream>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>
void work() {
	std::cout << "Poczatek pracy watku..\n";
	boost::posix_time::seconds s(2);
	boost::this_thread::sleep(s);
	std::cout << "Koniec pracy watku..\n";
}
int main(int argc, char* argv[]) {
	boost::thread_group myGroup;
	// Dwa watki kreowane w grupie
	myGroup.create_thread(&work);
	myGroup.create_thread(&work);
	// Jeden ,,luzny''
	boost::thread tr(&work);
	// .. i dolaczony do grupy.
	myGroup.add_thread(&tr);
	boost::posix_time::seconds s(1);
	myGroup.join_all();
	// Tu usuniety jawnie...
	myGroup.remove_thread(&tr);
	std::cout << "Koniec programu glownego.\n";
	return 0;
}
