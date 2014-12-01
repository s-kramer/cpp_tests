#include <iostream>
#include <cmath>
#include <functional>
struct IsPrime: public std::unary_function<int, bool> {
	bool operator() (int myNum) {
		int max = (int) sqrt(myNum);
		for(int i = 2; i <= max; i++) {
			if (!(myNum % i))
				return false;
		}
		return true;
	}
};
int main(int argc, char* argv[]) {
	IsPrime primeObject;
	IsPrime::argument_type inArg;
	IsPrime::result_type answer;
	std::cout << "Podaj liczbe: ";
	std::cin >> inArg;
	answer = primeObject(inArg);
	std::cout << "Liczba " << inArg << (answer?" jest": " nie jest")
			<< " pierwsza,\n";
}
