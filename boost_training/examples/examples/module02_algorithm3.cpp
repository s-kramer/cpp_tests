#include <iostream>
#include <boost/thread.hpp>
// Oczywiście naruszone DRY 
bool lock[2];		// Zmienna blokady.
int decision;		// Zmienna decyzji wejścia.
char data = 10;		// Dane współdzielone
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
		std::cout << "1: Poza sekcją krytyczną\n";
	}
}
void process2() {
	for(;;) {
		std::cout << "2: Sekcja lokalna\n";
		lock[1] = true;
		decision = 1;
		while((lock[0]) && (decision == 1)) {} // Czekanie aktywne.
		std::cout << "2: Praca w sekcji krytycznej\n";
		data = 20;
		if(data == 10) {
			std::cerr << "2: Ups naruszenie spójności danych!\n";
			exit(2);
		}
		lock[1] = false; // Oddanie blokady innemu...
		std::cout << "2: Poza sekcją krytyczną\n";
	}
}
int main(int argc, char* argv[]) {
	// Żaden z procesów nie chce (jeszcze) wejść do sekcji kr.
	lock[0] = false; lock[1] = false;
	// Blokada wskazuje na 1 proces.
	decision = 1;
	boost::thread proc1(&process1);
	boost::thread proc2(&process2);
	proc1.join(); proc2.join();
	return 0;
}
