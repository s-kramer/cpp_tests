#include <iostream>
#include <boost/thread.hpp>
// Oczywiście naruszone DRY 
int lock;		// Zmienna blokady.
char data = 10;		// Dane współdzielone
void process1() {
	for(;;) {
		std::cout << "1: Sekcja lokalna\n";
		while(lock != 1) {} // Czekanie aktywne na blokadzie.
		std::cout << "1: Praca w sekcji krytycznej\n";
		data = 10;
		if(data == 20) {
			std::cerr << "1: Ups naruszenie danych!" << data;
			exit(1);	
		}
		lock = 2; // Oddanie blokady innemu...
		std::cout << "1: Poza sekcją krytyczną\n";
	}
}
void process2() {
	for(;;) {
		std::cout << "2: Sekcja lokalna\n";
		while(lock != 2) {} // Czekanie aktywne na blokadzie.
		std::cout << "2: Praca w sekcji krytycznej\n";
		data = 20;
		if(data == 10) {
			std::cerr << "2: Ups naruszenie spójności danych!\n";
			exit(2);
		}
		lock = 1; // Oddanie blokady innemu...
		std::cout << "2: Poza sekcją krytyczną\n";
	}
}
int main(int argc, char* argv[]) {
	// Blokada wskazuje na 1 proces.
	lock = 1;
	boost::thread proc1(&process1);
	boost::thread proc2(&process2);
	proc1.join(); proc2.join();
	return 0;
}
