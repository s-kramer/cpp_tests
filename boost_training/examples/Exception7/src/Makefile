main: main.o FileException.o FileReadException.o FileSyntaxException.o
	g++ -o main main.o FileException.o FileReadException.o FileSyntaxException.o

FileException.o: FileException.hpp FileException.cpp
	g++ -c FileException.cpp

FileReadException.o: FileReadException.hpp FileReadException.cpp
	g++ -c FileReadException.cpp

FileSyntaxException.o: FileSyntaxException.hpp FileSyntaxException.cpp
	g++ -c FileSyntaxException.cpp

main.o: main.cpp 
	g++ -c main.cpp

clean:
	@rm -rf *.o main
