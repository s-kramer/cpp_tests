#include <iostream>
#include <string>
#include <mpi.h> // Uruchamiac: mpirun -np 2 ./prog 
int main(int argc, char* argv[]) {
	int rank, size, myTag, data;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	myTag = 132;
	if(rank == 0) {
		MPI_Barrier(MPI_COMM_WORLD);
		data = 456;
		std::cout << "Proces id: " << rank << " wys³a³: " << data << "\n";
		MPI_Send(&data, 1, MPI_INT, 1, myTag,
			MPI_COMM_WORLD);
	} else if (rank == 1) {
		MPI_Barrier(MPI_COMM_WORLD);
		MPI_Recv(&data, 1, MPI_INT, 0, myTag,
			MPI_COMM_WORLD, &status);
		std::cout << "Proces id: " << rank << " otrzyma³: " << data << "\n";
	}
	MPI_Finalize();
	return 0;
}
