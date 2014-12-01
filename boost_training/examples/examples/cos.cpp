#include <iostream>
#include <cassert>
#include <vector>
#include <csignal>
void mySig(int param) {
		std::cerr << "Chwycony\n";
}

std::vector<int> v(10);
int valueInVector(int n) {
		assert(n >= 0 && n < v.size());
		return v[n];
}
int main(int argc, char * argv[] ) {
	//signal(SIGABRT, SIG_DFL);
	signal(SIGABRT, mySig);
	//raise(SIGABRT);
	v[3] = 12;
	std::cout << "Teraz jest wszystko ok\n";
	std::cout << "Wartość v[3]: " << valueInVector(3)
			<< std::endl;
	std::cout << "A tak nie można!\n";
	std::cout << "Wartość v[100]: " << valueInVector(100)
			<< std::endl;
}
