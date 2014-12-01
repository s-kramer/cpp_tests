#include <iostream>

int main(int argc, char * argv[]) {
	try {
		try {
			throw 1;	// Zmieñ na 1L lub 'x'
		} catch (int) {
			std::cerr << "Chwyci³em int!\n";
			throw 'x'; // Zmieñ na 1L lub zakomentuj
		}
	} catch (char) {
		std::cerr << "Chwyci³em char!\n";
	} catch (...) {
		std::cerr << "No to jest szczyt!\n";
	}
}
