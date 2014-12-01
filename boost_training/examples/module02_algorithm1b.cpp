void process2() {
	for(;;) {
		std::cout << "2: Sekcja lokalna\n";
		while(lock != 2) {} // Czekanie aktywne na blokadzie.
		std::cout << "2: Praca w sekcji krytycznej\n";
		data = 20;
		if(data == 10) {
			std::cerr << "2: Ups naruszenie spójno¶ci danych!\n";
			exit(2);
		}
		lock = 1; // Oddanie blokady innemu...
		std::cout << "2: Poza sekcj± krytyczn±\n";
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
