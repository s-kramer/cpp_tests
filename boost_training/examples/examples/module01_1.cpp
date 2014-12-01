#include <iostream>

int main(int argc, char * argv[]) {
	try {
		throw 'x';	// Sprawd¼ z 1, 1L.
	} catch (int) {
		std::cerr << "Wychwycono wyj±tek int.\n";
	} catch (char) {
		std::cerr << "Wychwycono wyj±tek char.\n";
	} catch (...) {
		std::cerr << "Wychwycono wyj±tek nieznany.\n";
	}
}
