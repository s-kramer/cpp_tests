#include <iostream>
#include <mpi.h>
int main ( int argc, char *argv[] ) {
	int id;
	int p;
	double wtime;
	MPI::Init ( argc, argv );
	p = MPI::COMM_WORLD.Get_size ( );
	id = MPI::COMM_WORLD.Get_rank ( );
	if ( id == 0 ) {
		wtime = MPI_Wtime();
		std::cout << "\n";
		std::cout << "Tu proces glowny:\n";
		std::cout << " Dzia�a " << p << " procesow.\n";
	}
	std::cout << "  Proces " << id << " wita!\n";
	if ( id == 0 ) {
		std::cout << "Tu proces glowny:\n";
		std::cout << " Koniec dzia�ania.\n";
		wtime = MPI_Wtime() - wtime;
		std::cout << "\n";
		std::cout << "  czas dzia�ania = " << wtime << " sekund.\n";
	}
	MPI::Finalize ( );
	return 0;
}
