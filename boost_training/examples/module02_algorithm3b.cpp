void process2() {
	for(;;) {
		std::cout << "2: Sekcja lokalna\n";
		lock[1] = true;
		decision = 1;
		while((lock[0]) && (decision == 1)) {} // Czekanie aktywne.
		std::cout << "2: Praca w sekcji krytycznej\n";
		data = 20;
		if(data == 10) {
			std::cerr << "2: Ups naruszenie spójno¶ci danych!\n";
			exit(2);
		}
		lock[1] = false; // Oddanie blokady innemu...
		std::cout << "2: Poza sekcj± krytyczn±\n";
	}
}
int main(int argc, char* argv[]) {
	lock[0] = false; lock[1] = false;
	decision = 1; // Blokada wskazuje na 1 proces.
	boost::thread proc1(&process1);
	boost::thread proc2(&process2);
	proc1.join(); proc2.join();
	return 0;
}
