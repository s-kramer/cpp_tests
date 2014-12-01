#include <iostream>
#include <omp.h>

int main(int argc, char* argv[]) {
	std::cout << "Na tej maszynie mamy dostepne dla programu " 
		<< omp_get_num_procs() << " jednoske wykonawcza.\n";
	#pragma omp parallel for
	for(int n = 0; n < 4; ++n) {
		std::cout << "Zglasza sie watek " << omp_get_thread_num() << '\n';
		std::cout << "Teraz dziala " << omp_get_num_threads() << '\n';
		std::cout << "Wykonuje prosta prace z n = " << n << '\n';
	}
	return 0;
}
