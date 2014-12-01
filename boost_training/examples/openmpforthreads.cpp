#include <iostream>
#include <omp.h>
int main(int argc, char* argv[]) {
	#pragma omp parallel num_threads(4)
	{ // tu jest poczatek bloku dla omp parallel
	#pragma omp for // tu nie stosujemy parallel
	for(int n = 0; n < 8; ++n) {
		std::cout << "Zglasza sie watek " << omp_get_thread_num() << '\n';
		std::cout << "Teraz dzialaja " << omp_get_num_threads()
			<< " watki.\n";
		std::cout << "Wykonuje prosta prace z n = " << n << '\n';
	}
	}
	return 0;
}
