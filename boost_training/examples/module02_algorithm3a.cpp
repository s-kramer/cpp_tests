#include <iostream>
#include <boost/thread.hpp>
// Oczywi¶cie naruszone DRY 
bool lock[2];		// Zmienna blokady.
int decision;		// Zmienna decyzji wej¶cia.
char data = 10;		// Dane wspó³dzielone
void process1() {
	for(;;) {
		std::cout << "1: Sekcja lokalna\n";
		lock[0] = true;
		decision = 2;
		while((lock[1]) && (decision == 2)) {} // Czekanie aktywne.
		std::cout << "1: Praca w sekcji krytycznej\n";
		data = 10;
		if(data == 20) {
			std::cerr << "1: Ups naruszenie danych!" << data;
			exit(1);	
		}
		lock[0] = false; // Oddanie blokady innemu...
		std::cout << "1: Poza sekcj± krytyczn±\n";
	}
}
