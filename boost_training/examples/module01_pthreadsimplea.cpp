#include <iostream>
#include <cstdlib>
#include <cstdio>
// W��czenie pthreads.
extern "C" {
#include <pthread.h>
// Liczba w�tk�w
const unsigned max_threads = 10;
// Tablice id w�tk�w oraz argument�w.
pthread_t thread_table[max_threads];
char arguments[max_threads];
// Funkcja w�tku.
void * showThreader(void * arg) {
	char real_arg = *(static_cast<char * >(arg));
	for(int i = 0 ; i < 100 ; ++i) {
		std::cout << real_arg;
	}
	pthread_exit(NULL);
}
} // koniec extern "C"
