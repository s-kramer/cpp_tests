#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <boost/thread.hpp>
using namespace std;
using namespace boost;
// Liczba w±tków.
const unsigned max_threads = 10;
// Klasa w³asnego w±tku.
class MyThread {
private:
	char myChar;
public:
	MyThread(char arg) : myChar(arg) {}
	~MyThread() {}
	void operator()() const {
		for(int i = 0; i < 100; ++i)
			cout << myChar;
	}
};
