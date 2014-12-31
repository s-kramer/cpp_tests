#include <iostream>
#include "counter.hpp"

int main(void) {
	Counter_imp<10, false> myCounter;
	for(int i = 0; i < 20; ++i) {
		++myCounter;
		std::cout << int(myCounter.get_value()) << std::endl;
	}
}
