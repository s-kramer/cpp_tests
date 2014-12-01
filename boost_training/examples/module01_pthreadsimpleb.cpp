int main(int argc, char * argv[]) {
	int er;
	// P�tla uruchamiania w�tk�w.
	for(unsigned i = 0; i < max_threads; ++i) {
		arguments[i] = 'A' + i;
		// Zwr�� uwag� na spos�b przekazania argumentu...
		er = pthread_create(&thread_table[i], NULL, &showThreader, (void *)&arguments[i]);
		if(er) {
			std::cerr << "Nieudane kreowanie w�tku z b�edem: " << er << '\n';
		}
	}
	// P�tla ,,przy��czaj�ca'' w�tki.
	for(unsigned i = 0; i < max_threads; ++i) {
		pthread_join(thread_table[i], NULL);
	}
	std::cout << '\n';
	return EXIT_SUCCESS;
}
