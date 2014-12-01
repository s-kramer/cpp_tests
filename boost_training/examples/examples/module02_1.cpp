#include <iostream>
#include <cassert>
#include <vector>
std::vector<int> v(10);
int valueInVector(int n) {
		assert(n >= 0 && n < v.size());
		return v[n];
}
int main(int argc, char * argv[] ) {
	v[3] = 12;
	std::cout << "Teraz jest wszystko ok\n";
	std::cout << "Warto¶æ v[3]: " << valueInVector(3)
			<< std::endl;
	std::cout << "A tak nie mo¿na!\n";
	std::cout << "Warto¶æ v[100]: " << valueInVector(100)
			<< std::endl;
}
