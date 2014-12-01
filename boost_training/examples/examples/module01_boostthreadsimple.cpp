#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <boost/thread.hpp>
using namespace std;
using namespace boost;
// Liczba wątków.
const unsigned max_threads = 10;
// Klasa własnego wątku.
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
// Tworzy wątek.
thread * make_thread() {
	static int i = 0;
	MyThread * thr = new MyThread('A' + i++);
	thread * thrPtr;
	thrPtr = new thread(*thr);
	delete thr;
	return thrPtr;
}
// Przyłącza wątek i usuwa go.
void join_deleter(thread * thrPtr) {
	thrPtr->join();
	delete thrPtr;
}
int main(int argc, char* argv[]) {
	// Wektor wątków.
	vector<thread *> thread_table(max_threads);
	// Pętla tworząca wątki.
	generate(thread_table.begin(), thread_table.end(), make_thread);
	// Pętla przyłączająca wątki i niszcząca obiekty.
	for_each(thread_table.begin(), thread_table.end(), join_deleter);
	cout << '\n';
	return EXIT_SUCCESS;
}
