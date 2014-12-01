#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/thread/once.hpp>
// Oczywiscie zlamana DRY :)
boost::once_flag flaga=BOOST_ONCE_INIT;
void onceFunction() {
	std::cout << ">No to raz<";
}
void myThr1() {
	std::cout << "Tu myThr1, uruchamiam funkcjê onceFunction()";
	boost::call_once(onceFunction, flaga);
	std::cout << "\n";
}
void myThr2() {
	std::cout << "Tu myThr2, uruchamiam funkcjê onceFunction()";
	boost::call_once(onceFunction, flaga);
	std::cout << "\n";
}
int main(int argc, char* argv[]) {
	boost::thread thr1(&myThr1);
	boost::thread thr2(&myThr2);
	thr1.join();
	thr2.join();
}
