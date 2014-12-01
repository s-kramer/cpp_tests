#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <boost/thread.hpp>
using namespace std;
using namespace boost;
// Liczba w�tk�w.
const unsigned max_threads = 10;
// Klasa w�asnego w�tku.
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
