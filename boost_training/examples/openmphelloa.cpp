#include <iostream>
#include <omp.h>
int main(int argc, char* argv[]) {
	#pragma omp parallel num_threads(8)
	std::cout << "Ho ho ho... swieta minely...\n"; 
	return 0;
}
