...
int main(int argc, char * argv[]) {
	A aObiekt;				// Wynik to:
	C cObiekt;				// Klasa C
	A* pA = &cObiekt;		// Klasa A
	A* pA2 = &aObiekt;
	identf(pA);
	identf(pA2);
}
