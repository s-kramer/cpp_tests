#include <iostream>
struct A { virtual void name() { std::cout << "Klasa A\n"; } };
struct B : A { virtual void name() { std::cout << "Klasa B\n"; } };
struct C : A { virtual void name() { std::cout << "Klasa C\n"; } };
void identf(A* klasa) {
	B* pB = dynamic_cast<B*>(klasa);
	C* pC = dynamic_cast<C*>(klasa);
	if (pB)
		pB->name();
	else if (pC)
		pC->name();
	else
		klasa->name();
};
...
