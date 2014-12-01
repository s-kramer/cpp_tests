#include <iostream>
#include <boost/thread.hpp>
// Oczywi¶cie naruszone DRY 
bool lock[2];		// Zmienna blokad.
char data = 10;		// Dane wspó³dzielone
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
		std::cout << "1: Poza sekcj± krytyczn±\n";
	}
}
