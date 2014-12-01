#include <iostream>
#include <cstdlib>
#include <cstdio>
// Włączenie pthreads.
extern "C" {
#include <pthread.h>
// Liczba wątków
const unsigned max_threads = 10;
// Tablice id wątków oraz argumentów.
pthread_t thread_table[max_threads];
char arguments[max_threads];
// Funkcja wątku.
void * showThreader(void * arg) {
	char real_arg = *(static_cast<char * >(arg));
	for(int i = 0 ; i < 100 ; ++i) {
		std::cout << real_arg;
	}
	pthread_exit(NULL);
}
} // koniec extern "C"
int main(int argc, char * argv[]) {
	int er;
	// Pętla uruchamiania wątków.
	for(unsigned i = 0; i < max_threads; ++i) {
		arguments[i] = 'A' + i;
		// Zwróć uwagę na sposób przekazania argumentu...
		er = pthread_create(&thread_table[i], NULL, &showThreader, (void *)&arguments[i]);
		if(er) {
			std::cerr << "Nieudane kreowanie wątku z błedem: " << er << '\n';
		}
	}
	// Pętla ,,przyłączająca'' wątki.
	for(unsigned i = 0; i < max_threads; ++i) {
		pthread_join(thread_table[i], NULL);
	}
	std::cout << '\n';
	return EXIT_SUCCESS;
}
