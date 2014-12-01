#include <iostream>
#include <boost/thread.hpp>
// Oczywiście naruszone DRY 
bool lock[2];		// Zmienna blokad.
char data = 10;		// Dane współdzielone
void process1() {
	for(;;) {
		std::cout << "1: Sekcja lokalna\n";
		lock[0] = true;
		while(lock[1]) {} // Czekanie aktywne na blokadzie.
		std::cout << "1: Praca w sekcji krytycznej\n";
		data = 10;
		if(data == 20) {
			std::cerr << "1: Ups naruszenie danych!" << data;
			exit(1);	
		}
		lock[0] = false; // Oddanie blokady...
		std::cout << "1: Poza sekcją krytyczną\n";
	}
}
void process2() {
	for(;;) {
		std::cout << "2: Sekcja lokalna\n";
		lock[1] = true;
		while(lock[0]) {} // Czekanie aktywne na blokadzie.
		std::cout << "2: Praca w sekcji krytycznej\n";
		data = 20;
		if(data == 10) {
			std::cerr << "2: Ups naruszenie spójności danych!\n";
			exit(2);
		}
		lock[1] = false; // Oddanie blokady...
		std::cout << "2: Poza sekcją krytyczną\n";
	}
}
int main(int argc, char* argv[]) {
	// Blokady zwolnione.
	lock[0] = false; lock[1] = false;
	boost::thread proc1(&process1);
	boost::thread proc2(&process2);
	proc1.join(); proc2.join();
	return 0;
}
