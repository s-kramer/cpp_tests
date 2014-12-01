#include <iostream>
#include <functional>
#include <algorithm>
int main(int argc, char* argv[]) {
	int numerki[] = {1,2,3,4,5,6,7,8,9};
	int ilosc;
	ilosc = std::count_if(numerki, numerki+9,
		std::bind2nd(std::greater_equal<int>(),4));
	std::cout << "Jest " << ilosc << " liczb >=4\n";
}
