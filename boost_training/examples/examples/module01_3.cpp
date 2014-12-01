#include <iostream>

int main(int argc, char * argv[]) {
	throw {
		int 20;
	} catch (int e) {
		std::cerr << "Chwyci³em int o warto¶ci"
			<< e << ".\n";
	} catch (...) {
		std::cerr << "Tego nie znam!\n";
	}
}
