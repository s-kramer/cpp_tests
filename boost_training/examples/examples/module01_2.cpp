#include <iostream>

int main(int argc, char * argv[]) {
	try {
		try {
			throw 1;	// Zmie� na 1L lub 'x'
		} catch (int) {
			std::cerr << "Chwyci�em int!\n";
			throw 'x'; // Zmie� na 1L lub zakomentuj
		}
	} catch (char) {
		std::cerr << "Chwyci�em char!\n";
	} catch (...) {
		std::cerr << "No to jest szczyt!\n";
	}
}
