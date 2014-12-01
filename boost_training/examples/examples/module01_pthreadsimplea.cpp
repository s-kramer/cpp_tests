#include <iostream>
#include <cstdlib>
#include <cstdio>
// W³±czenie pthreads.
extern "C" {
#include <pthread.h>
// Liczba w±tków
const unsigned max_threads = 10;
// Tablice id w±tków oraz argumentów.
pthread_t thread_table[max_threads];
char arguments[max_threads];
// Funkcja w±tku.
void * showThreader(void * arg) {
	char real_arg = *(static_cast<char * >(arg));
	for(int i = 0 ; i < 100 ; ++i) {
		std::cout << real_arg;
	}
	pthread_exit(NULL);
}
} // koniec extern "C"
