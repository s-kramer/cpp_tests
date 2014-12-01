int main(int argc, char * argv[]) {
	int er;
	// Pêtla uruchamiania w±tków.
	for(unsigned i = 0; i < max_threads; ++i) {
		arguments[i] = 'A' + i;
		// Zwróæ uwagê na sposób przekazania argumentu...
		er = pthread_create(&thread_table[i], NULL, &showThreader, (void *)&arguments[i]);
		if(er) {
			std::cerr << "Nieudane kreowanie w±tku z b³edem: " << er << '\n';
		}
	}
	// Pêtla ,,przy³±czaj±ca'' w±tki.
	for(unsigned i = 0; i < max_threads; ++i) {
		pthread_join(thread_table[i], NULL);
	}
	std::cout << '\n';
	return EXIT_SUCCESS;
}
