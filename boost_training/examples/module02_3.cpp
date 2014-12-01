#include <iostream>
#include <ostream>
#include <fstream>
int main(int argc, char * argv[]) {
	std::streambuf * fileBuf;
	std::streambuf * saveBuf;
	saveBuf = std::cerr.rdbuf();
	std::ofstream fileName("errors.txt");
	fileBuf = fileName.rdbuf();
	std::cerr.rdbuf(fileBuf);
	std::cerr << "Error to file :)\n";
	std::cerr.rdbuf(saveBuf);
	fileName.close();
}
