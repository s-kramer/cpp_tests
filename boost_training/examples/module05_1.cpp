#include <iostream>
#include <typeinfo>
class Bazowa{};
class Wyprowadzona : public Bazowa {};
class Inna{};
class PolBazowa { virtual void cokolwiek(){} };
class PolWyprowadzona: public PolBazowa {};
int main(int argc, char * argv[]) {
	int integer;
	int * ptrInteger;
	std::cout << "int     to: " << typeid(integer).name() << std::endl;
	std::cout << "*int    to: " << typeid(ptrInteger).name() << std::endl;
	...
