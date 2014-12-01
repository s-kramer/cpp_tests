#include <iostream>
#include <boost/thread.hpp>
// Oczywi¶cie naruszone DRY 
int lock;		// Zmienna blokady.
char data = 10;		// Dane wspó³dzielone
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
		std::cout << "1: Poza sekcj± krytyczn±\n";
	}
}
